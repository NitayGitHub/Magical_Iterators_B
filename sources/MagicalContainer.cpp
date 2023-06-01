#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
namespace ariel
{
    // Main Functions
    void MagicalContainer::addElement(int element)
    {

        // add to container
        _container.push_back(element);

        // add to ascendingList
        updateAscendingList();

        // add to primeList
        updatePrimeList();

        // add to sideCrossList
        updateSideCrossList();
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

        // remove from primeList
        updatePrimeList();

        // remove from ascendingList
        updateAscendingList();

        // remove from sideCrossList
        updateSideCrossList();
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

    bool MagicalContainer::isPrime(int num) const
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

    void MagicalContainer::updateAscendingList()
    {
        ascendingList.clear();
        for (auto it = _container.begin(); it != _container.end(); ++it)
        {
            ascendingList.push_back(&(*it));
        }
        sort(ascendingList.begin(), ascendingList.end(), [](int *a, int *b)
             { return *a < *b; });
    }

    void MagicalContainer::updatePrimeList()
    {
        primeList.clear();
        for (auto it = _container.begin(); it != _container.end(); ++it)
        {
            if (isPrime(*it))
            {
                primeList.push_back(&(*it));
            }
        }
    }

    void MagicalContainer::updateSideCrossList()
    {
        sideCrossList.clear();
        unsigned long left = 0;                      // Pointer starting from the beginning
        unsigned long right = _container.size() - 1; // Pointer starting from the end

        while (left <= right)
        {
            sideCrossList.push_back(&_container[left++]); // Select an element from the start
            if (left <= right)
            {
                sideCrossList.push_back(&_container[right--]); // Select an element from the end
            }
        }
    }

    // Getters
    vector<int> &MagicalContainer::getContainer() const
    {
        return (vector<int> &)_container;
    }

    vector<int *> &MagicalContainer::getAscendingList() const
    {
        return (vector<int *> &)ascendingList;
    }

    vector<int *> &MagicalContainer::getPrimeList() const
    {
        return (vector<int *> &)primeList;
    }

    vector<int *> &MagicalContainer::getSideCrossList() const
    {
        return (vector<int *> &)sideCrossList;
    }
}