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
    private:
        vector<int *> list;
        function<void(vector<int>&, vector<int *>&)> updateList;

    public:
        // Constructors
        IteratorList(function<void(vector<int>&, vector<int *>&)> updateList) : updateList(updateList) {}

        // Main functions
        void updateList(vector<int> container)
        {
            updateList(container, list);
        }
    };
}

#endif