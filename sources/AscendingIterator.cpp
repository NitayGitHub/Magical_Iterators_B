#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{
    // Constructors
    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container) : 
    MagicalIterator(container._itlists[0].getList()) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : 
    MagicalIterator(other.List, other.indx) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

}