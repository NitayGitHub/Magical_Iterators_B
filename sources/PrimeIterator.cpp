#include "MagicalContainer.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
using namespace std;

namespace ariel
{
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container) : 
    MagicalIterator(container.getPrimeList()) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : 
    MagicalIterator(other.List, other.indx) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}
}