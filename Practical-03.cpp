#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

// -------------------------
// Max Heap
// -------------------------

void maxHeapify(vector<int> &arr, int n, int index)
{
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Check left child
    if (leftChild < n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    // Check right child
    if (rightChild < n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    // If largest element is not the root
    if (largest != index)
    {
        swap(arr[index], arr[largest]);

        // Heapify the affected subtree
        maxHeapify(arr, n, largest);
    }
}

void maxHeapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }

    // Perform Heap Sort
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        maxHeapify(arr, i, 0);
    }
}
// -------------------------
// Min Heap
// -------------------------

void minHeapify(vector<int> &arr, int n, int index)
{
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Check left child
    if (leftChild < n && arr[leftChild] < arr[smallest])
    {
        smallest = leftChild;
    }

    // Check right child
    if (rightChild < n && arr[rightChild] < arr[smallest])
    {
        smallest = rightChild;
    }

    // If smallest element is not the root
    if (smallest != index)
    {
        swap(arr[index], arr[smallest]);

        // Heapify the affected subtree
        minHeapify(arr, n, smallest);
    }
}

void minHeapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(arr, n, i);
    }

    // Perform Heap Sort
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        minHeapify(arr, i, 0);
    }

    // Reverse array to get ascending order
    reverse(arr.begin(), arr.end());
}
// -------------------------
// Main Function
// -------------------------

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> original(n);

    // Generate random numbers
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        original[i] = rand() % 100000;
    }

    // Create copies for both heap sorts
    vector<int> maxHeapArray = original;
    vector<int> minHeapArray = original;

    // -------------------------
    // Max Heap Sort
    // -------------------------

    auto startMax = high_resolution_clock::now();

    maxHeapSort(maxHeapArray);

    auto endMax = high_resolution_clock::now();

    // -------------------------
    // Min Heap Sort
    // -------------------------

    auto startMin = high_resolution_clock::now();

    minHeapSort(minHeapArray);

    auto endMin = high_resolution_clock::now();

    // -------------------------
    // Calculate Execution Time
    // -------------------------

    auto nanoMax = duration_cast<nanoseconds>(endMax - startMax);
    auto microMax = duration_cast<microseconds>(endMax - startMax);
    auto milliMax = duration_cast<milliseconds>(endMax - startMax);
    duration<double> secMax = endMax - startMax;

    auto nanoMin = duration_cast<nanoseconds>(endMin - startMin);
    auto microMin = duration_cast<microseconds>(endMin - startMin);
    auto milliMin = duration_cast<milliseconds>(endMin - startMin);
    duration<double> secMin = endMin - startMin;

    // -------------------------
    // Display Results
    // -------------------------

    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << nanoMax.count() << " ns\n";
    cout << "Microseconds : " << microMax.count() << " us\n";
    cout << "Milliseconds : " << milliMax.count() << " ms\n";
    cout << "Seconds      : " << secMax.count() << " s\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << nanoMin.count() << " ns\n";
    cout << "Microseconds : " << microMin.count() << " us\n";
    cout << "Milliseconds : " << milliMin.count() << " ms\n";
    cout << "Seconds      : " << secMin.count() << " s\n";

    return 0;
}
