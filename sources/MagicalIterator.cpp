#include "MagicalIterator.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors
    MagicalIterator::MagicalIterator(vector<int *> &List, size_t indx) : List(List), indx(indx) {}

    MagicalIterator::MagicalIterator(const MagicalIterator &other) : List(other.List), indx(other.indx) {}

    MagicalIterator::~MagicalIterator() {}

    // Operators

    MagicalIterator &MagicalIterator::operator=(const MagicalIterator &other)
    {
        if(List != other.List)
        {
            throw runtime_error("Cannot assign iterators of different types");
        }
        if (this != &other)
        {
            indx = other.indx;
            List = other.List;
        }
        return *this;
    }

    bool MagicalIterator::operator==(const MagicalIterator &other) const
    {
        if (List != other.List)
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return indx == other.indx;
    }

    bool MagicalIterator::operator!=(const MagicalIterator &other) const
    {
        if (List != other.List)
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return indx != other.indx;
    }

    bool MagicalIterator::operator<(const MagicalIterator &other) const
    {
        if (List != other.List)
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return indx < other.indx;
    }

    bool MagicalIterator::operator>(const MagicalIterator &other) const
    {
        if (List != other.List)
        {
            throw invalid_argument("Cannot compare iterators of different types");
        }
        return indx > other.indx;
    }

    int &MagicalIterator::operator*() const
    {
        return *List[indx];
    }

    MagicalIterator &MagicalIterator::operator++()
    {
        if(indx + 1 > List.size())
        {
            throw runtime_error("Cannot increment iterator past end of container");
        }
        indx++;
        return *this;
    }

    // Main functions

    MagicalIterator MagicalIterator::begin()
    {
        MagicalIterator mi = MagicalIterator(*this);
        mi.setIndx(0);
        return mi;
    }

    MagicalIterator MagicalIterator::end()
    {
        MagicalIterator mi = MagicalIterator(*this);
        mi.setIndx(List.size());
        return mi;
    }

    // Getters and setters
    size_t MagicalIterator::getIndx() const
    {
        return indx;
    }

    void MagicalIterator::setIndx(size_t indx)
    {
        this->indx = indx;
    }

}