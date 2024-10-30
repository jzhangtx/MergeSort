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
    std::vector<int> vec{ 5, 4, 2, 5, 3, 1 };
    MergeSort(vec);
}
