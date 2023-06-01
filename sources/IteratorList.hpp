#ifndef ITERATORLIST_H
#define ITERATORLIST_H
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <functional>

using namespace std;

namespace ariel
{
    class IteratorList
    {
    protected:
        vector<int *> list;
    public:
        // Constructors
        IteratorList(function<void(vector<int>)> updateList): updateList(updateList) {}

        // Main functions
        void UpdateList(vector<int> container);
        
    };
}

#endif