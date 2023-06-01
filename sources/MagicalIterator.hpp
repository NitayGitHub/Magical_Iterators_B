#ifndef MAGICALITERATOR_H
#define MAGICALITERATOR_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace ariel
{
    class MagicalIterator
    {
    protected:
        vector<int *> &List;
        size_t indx = 0;

    public:
        // Constructors
        MagicalIterator(vector<int *> &List, size_t indx = 0);
        MagicalIterator(const MagicalIterator &other);
        virtual ~MagicalIterator();

        // Operators
        MagicalIterator &operator=(const MagicalIterator &other);
        bool operator==(const MagicalIterator &other) const;
        bool operator!=(const MagicalIterator &other) const;
        bool operator<(const MagicalIterator &other) const;
        bool operator>(const MagicalIterator &other) const;
        int &operator*() const;
        MagicalIterator &operator++();

        // Main functions
        MagicalIterator begin();
        MagicalIterator end();

        // Getters and setters
        size_t getIndx() const;
        void setIndx(size_t indx);
    };
}

#endif