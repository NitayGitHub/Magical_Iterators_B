#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "MagicalIterator.hpp"

using namespace std;

namespace ariel
{

    class MagicalContainer
    {
    private:
        vector<int> _container;
        vector<int*> ascendingList;
        vector<int*> primeList;
        vector<int*> sideCrossList;

    public:
        // Main functions
        void addElement(int element);
        void removeElement(int element);
        int size() const;

        // Aid functions
        bool isEmpty() const;
        bool isPrime(int num) const;
        string toString() const;
        void updateAscendingList();
        void updatePrimeList();
        void updateSideCrossList();

        // Getters
        vector<int> &getContainer() const;
        vector<int*> &getAscendingList() const;
        vector<int*> &getPrimeList() const;
        vector<int*> &getSideCrossList() const;

        // Iterators

        class AscendingIterator : public MagicalIterator
        {
        public:
            // Constructors
            AscendingIterator(const MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator();
        };

        class PrimeIterator : public MagicalIterator
        {
        public:
            // Constructors
            PrimeIterator(const MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();
        };

        class SideCrossIterator : public MagicalIterator
        {
         public:
            // Constructors
            SideCrossIterator(const MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator();
        };
    };
}

#endif