#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

namespace ariel
{
    auto updAscList = [](vector<int> &container, vector<int *> &itlist)
    {
        itlist.clear();
        for (auto it = container.begin(); it != container.end(); ++it)
        {
            itlist.push_back(&(*it));
        }
        sort(itlist.begin(), itlist.end(), [](int *a, int *b)
             { return *a < *b; });
    };

    bool isPrime(int num)
    {
        if (num < 2)
        {
            return false;
        }
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    auto updPrimeList = [](vector<int> &container, vector<int *> &itlist)
    {
        itlist.clear();
        for (auto it = container.begin(); it != container.end(); ++it)
        {
            if (isPrime(*it))
            {
                itlist.push_back(&(*it));
            }
        }
    };

    auto updSideCrossList = [](vector<int> &container, vector<int *> &itlist)
    {
        itlist.clear();
        unsigned long left = 0;                      // Pointer starting from the beginning
        unsigned long right = container.size() - 1; // Pointer starting from the end

        while (left <= right)
        {
            itlist.push_back(&container[left++]); // Select an element from the start
            if (left <= right)
            {
                itlist.push_back(&container[right--]); // Select an element from the end
            }
        }
    };

    // Constructors
    MagicalContainer::MagicalContainer()
    {
        _itlists.push_back(IteratorList(updAscList));
        _itlists.push_back(IteratorList(updPrimeList));
        _itlists.push_back(IteratorList(updSideCrossList));
    }

    // Main Functions
    void MagicalContainer::addElement(int element)
    {

        // add to container
        _container.push_back(element);

        // update IteratorLists
        for (auto it = _itlists.begin(); it != _itlists.end(); ++it)
        {
            it->performUpdate(_container);
        }
    }

    void MagicalContainer::removeElement(int element)
    {
        // remove from container
        vector<int>::iterator index = find(_container.begin(), _container.end(), element);
        if (index == _container.end())
        {
            throw runtime_error("Element not found");
        }
        _container.erase(index);

        // update IteratorLists
        for (auto it = _itlists.begin(); it != _itlists.end(); ++it)
        {
            it->performUpdate(_container);
        }
    }

    int MagicalContainer::size() const
    {
        return _container.size();
    }

    // Aid Functions
    bool MagicalContainer::isEmpty() const
    {
        return _container.empty();
    }

    string MagicalContainer::toString() const
    {
        string str = "";
        for (auto it = _container.begin(); it != _container.end(); ++it)
        {
            str += to_string(*it) + " ";
        }
        return str;
    }

    // Getters
    vector<int>& MagicalContainer::getContainer() const
    {
        return (vector<int> &)_container;
    }

}