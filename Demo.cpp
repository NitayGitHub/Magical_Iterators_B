#include <iostream>
#include "sources/MagicalContainer.hpp"
#include <chrono>
#include <random>

using namespace ariel;

int random_int(int min = 0, int max = 100)
{
    default_random_engine generator(static_cast<unsigned long>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

int main()
{
    // Create a MagicalContainer and add some elements
    cout << "How many elements would you like to add?" << endl;
    int numOfElements;
    cin >> numOfElements;

    MagicalContainer container;
    for (int i = 0; i < numOfElements; i++)
    {
        container.addElement(random_int());
    }

    // Print container
    cout << "Container: " << endl;
    cout << container.toString() << endl;

    // Use AscendingIterator to display elements in ascending order
    cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;

    // Use DescendingIterator to display elements in descending order
    cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;

    // Use PrimeIterator to display prime numbers only
    cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container);
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
    {
        cout << *it << ' '; // 2 3 17
    }
    cout << endl;

    // Remove elements
    cout << "Enter elements to remove, enter -1 to stop" << endl;
    int elementToRemove;
    cin >> elementToRemove;
    while (elementToRemove != -1)
    {
        container.removeElement(elementToRemove);
        cin >> elementToRemove;
    }

    // Print container
    cout << "Container: " << endl;
    cout << container.toString() << endl;

    // Use AscendingIterator to display elements in ascending order
    cout << "Elements in ascending order:\n";
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;

    // Use DescendingIterator to display elements in descending order
    cout << "Elements in cross order:\n";
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;

    // Use PrimeIterator to display prime numbers only
    cout << "Prime numbers:\n";
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
    {
        cout << *it << ' '; // 2 3 17
    }
    cout << endl;

    return 0;
}
