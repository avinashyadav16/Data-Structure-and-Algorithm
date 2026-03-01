// TODO
/**
 *  @file: Min_Heap.cpp
 *  @author: Avinash Yadav
 *  @date: 26-06-2025
 *  @brief: Creating and Initializing a Min-Heap:
 */

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;
    
    void heapifyUp(int index)
    {
        if (index == 0)
        {
            return;
        }

        int parentIndex = (index - 1) / 2;

        if (heap[parentIndex] > heap[index])
        {
            swap(heap[parentIndex], heap[index]);

            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index)
    {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        
        int smallest = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[smallest])
        {
            smallest = leftChildIndex;
        }

        if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallest])
        {
            smallest = rightChildIndex;
        }

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin()
    {
        if (heap.empty())
        {
            cerr << "Heap is empty.";
            return -1;
        }

        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return min;
    }

    int peek() const
    {
        if (heap.empty())
        {
            cerr << "Heap is empty.";
            return -1;
        }

        return heap[0];
    }
};
