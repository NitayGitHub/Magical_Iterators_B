#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{
    // Constructors
    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container) : 
    MagicalIterator(container._itlists[2].getList()) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : 
    MagicalIterator(other.List, other.indx) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}
}