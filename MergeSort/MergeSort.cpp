// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void Merge(std::vector<int>& arr, size_t low, size_t mid, size_t high)
{
    std::vector<int> v;
    v.reserve(high - low);

    size_t i = low, j = mid;
    int k = 0;
    for (; i < mid && j < high;)
    {
        if (arr[i] < arr[j])
            v.push_back(arr[i++]);
        else
            v.push_back(arr[j++]);
    }
    for (; i < mid; ++i)
        v.push_back(arr[i]);
    for (; j < high; ++j)
        v.push_back(arr[j]);

    for (i = low, j = 0; i < high; ++i, ++j)
    {
        arr[i] = v[j];
    }
}

void Sort(std::vector<int>& arr, size_t low, size_t high)
{
    if (high - low == 1)
        return;

    size_t mid = (low + high) / 2;
    Sort(arr, low, mid);
    Sort(arr, mid, high);

    Merge(arr, low, mid, high);
}

void MergeSort(std::vector<int>& arr)
{
    Sort(arr, 0, arr.size());
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of elements in the array: ";
        std::cin >> count;
        if (count == 0)
            break;

        std::vector<int> vec(count);
        std::cout << "The number array: ";
        for (int i = 0; i < count; ++i)
            std::cin >> vec[i];

        MergeSort(vec);
        std::cout << "Sorted:" << std::endl;
        for (auto i = vec.cbegin(); i != vec.cend(); ++i)
        {
            if (i != vec.cbegin())
                std::cout << ", ";
            std::cout << *i;
        }
        std::cout << std::endl;
    }
}
