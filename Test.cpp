#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <iostream>
#include <memory>
using namespace std;
using namespace ariel;

TEST_CASE("Removing Elements")
{
    MagicalContainer mc;
    mc.addElement(12);
    CHECK_NOTHROW(mc.removeElement(12));
    CHECK_THROWS(mc.removeElement(12));
}

TEST_CASE("Accurate Iteration")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(7);
    container.addElement(2);

    MagicalContainer::AscendingIterator ascIterator(container);

    vector<int> expected{2, 3, 5, 7};
    size_t index = 0;

    for (auto it = ascIterator.begin(); it != ascIterator.end(); ++it, ++index)
    {
        CHECK(*it == expected[index]);
    }

    ariel::MagicalContainer::PrimeIterator primeIterator(container);

    vector<int> expected2{5, 3, 7, 2};
    index = 0;

    for (auto it = primeIterator.begin(); it != primeIterator.end(); ++it, ++index)
    {
        CHECK(*it == expected2[index]);
    }

    MagicalContainer::SideCrossIterator sideCrossIterator(container);

    vector<int> expected3{5, 2, 3, 7};
    index = 0;

    for (auto it = sideCrossIterator.begin(); it != sideCrossIterator.end(); ++it, ++index)
    {
        CHECK(*it == expected3[index]);
    }
}

TEST_CASE("Accurate Iteration after removal")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(7);
    container.addElement(0);
    container.addElement(2);

    container.removeElement(5);
    container.removeElement(2);

    MagicalContainer::AscendingIterator ascIterator(container);

    vector<int> expected{0, 7};
    size_t index = 0;

    for (auto it = ascIterator.begin(); it != ascIterator.end(); ++it, ++index)
    {
        CHECK(*it == expected[index]);
    }

    CHECK(container.getIteratorList(0).getList().size() == 2);

    ariel::MagicalContainer::PrimeIterator primeIterator(container);

    vector<int> expected2{7};
    index = 0;

    for (auto it = primeIterator.begin(); it != primeIterator.end(); ++it, ++index)
    {
        CHECK(*it == expected2[index]);
    }

    CHECK(container.getIteratorList(1).getList().size() == 1);

    MagicalContainer::SideCrossIterator sideCrossIterator(container);

    vector<int> expected3{7, 0};
    index = 0;

    for (auto it = sideCrossIterator.begin(); it != sideCrossIterator.end(); ++it, ++index)
    {
        CHECK(*it == expected3[index]);
    }

    CHECK(container.getIteratorList(2).getList().size() == 2);
}

TEST_CASE("AcendingIterator Operators")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(7);
    container.addElement(2);

    MagicalContainer::AscendingIterator ascIterator(container);

    // Equality operator (==)

    auto it1 = ascIterator.begin();
    auto it2 = ascIterator.begin();
    CHECK(it1 == it2);

    // Inequality operator (!=)"

    ++it1;
    CHECK_FALSE(it1 == it2);
    CHECK(it1 != it2);

    // Less than operator (<)

    auto it3 = ascIterator.begin();
    auto it4 = ascIterator.begin();
    ++it4;
    ++it4;
    CHECK(it3 < it4);
    CHECK_FALSE(it4 < it3);

    // Greater than operator (>)

    auto it5 = ascIterator.begin();
    ++it5;
    ++it5;
    auto it6 = ascIterator.begin();
    CHECK(it5 > it6);
    CHECK_FALSE(it6 > it5);
}

TEST_CASE("PrimeIterator Operators")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(7);
    container.addElement(2);

    MagicalContainer::PrimeIterator primeIterator(container);

    // Equality operator (==)

    auto it1 = primeIterator.begin();
    auto it2 = primeIterator.begin();
    CHECK(it1 == it2);

    // Inequality operator (!=)"

    ++it1;
    CHECK_FALSE(it1 == it2);
    CHECK(it1 != it2);

    // Less than operator (<)

    auto it3 = primeIterator.begin();
    auto it4 = primeIterator.begin();
    ++it4;
    ++it4;
    CHECK(it3 < it4);
    CHECK_FALSE(it4 < it3);

    // Greater than operator (>)

    auto it5 = primeIterator.begin();
    ++it5;
    ++it5;
    auto it6 = primeIterator.begin();
    CHECK(it5 > it6);
    CHECK_FALSE(it6 > it5);
}

TEST_CASE("SideCrossIterator Operators")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(7);
    container.addElement(2);

    MagicalContainer::SideCrossIterator sideCrossIterator(container);

    // Equality operator (==)

    auto it1 = sideCrossIterator.begin();
    auto it2 = sideCrossIterator.begin();
    CHECK(it1 == it2);

    // Inequality operator (!=)"

    ++it1;
    CHECK_FALSE(it1 == it2);
    CHECK(it1 != it2);

    // Less than operator (<)

    auto it3 = sideCrossIterator.begin();
    auto it4 = sideCrossIterator.begin();
    ++it4;
    ++it4;
    CHECK(it3 < it4);
    CHECK_FALSE(it4 < it3);

    // Greater than operator (>)

    auto it5 = sideCrossIterator.begin();
    ++it5;
    ++it5;
    auto it6 = sideCrossIterator.begin();
    CHECK(it5 > it6);
    CHECK_FALSE(it6 > it5);
}

TEST_CASE("Iterators Operators Throw Exception Between Diffrent Iterator Types")
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(7);
    container.addElement(2);

    MagicalContainer::AscendingIterator ascIterator(container);
    MagicalContainer::PrimeIterator primeIterator(container);
    MagicalContainer::SideCrossIterator sideCrossIterator(container);

    auto itAsc = ascIterator.begin();
    auto itPrime = primeIterator.begin();
    auto itSideCross = sideCrossIterator.begin();

    CHECK_THROWS_AS(bool b1 = (itAsc == itPrime), std::invalid_argument);
    CHECK_THROWS_AS(bool b2 = (itAsc == itSideCross), std::invalid_argument);
    CHECK_THROWS_AS(bool b3 = (itPrime == itSideCross), std::invalid_argument);

    CHECK_THROWS_AS(bool b4 = (itAsc != itPrime), std::invalid_argument);
    CHECK_THROWS_AS(bool b5 = (itAsc != itSideCross), std::invalid_argument);
    CHECK_THROWS_AS(bool b6 = (itPrime != itSideCross), std::invalid_argument);

    CHECK_THROWS_AS(bool b7 = (itAsc < itPrime), std::invalid_argument);
    CHECK_THROWS_AS(bool b8 = (itAsc < itSideCross), std::invalid_argument);
    CHECK_THROWS_AS(bool b9 = (itPrime < itSideCross), std::invalid_argument);

    CHECK_THROWS_AS(bool b10 = (itAsc > itPrime), std::invalid_argument);
    CHECK_THROWS_AS(bool b11 = (itAsc > itSideCross), std::invalid_argument);
    CHECK_THROWS_AS(bool b12 = (itPrime > itSideCross), std::invalid_argument);
}
