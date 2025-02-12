#include <iostream>
using namespace std;


void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

int extractMin(int heap[], int& n) {
    int minElement = heap[0];
    heap[0] = heap[n - 1];
    n--;
    heapify(heap, n, 0);
    return minElement;
}

void insertHeap(int heap[], int& n, int key) {
    n++;
    int i = n - 1;
    heap[i] = key;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int optimalMergePattern(int files[], int n) {
    int totalCost = 0;

        for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(files, n, i);
    }

        while (n > 1) {
        int first = extractMin(files, n);
        int second = extractMin(files, n);
        int mergeCost = first + second;
        totalCost += mergeCost;
        insertHeap(files, n, mergeCost);
    }

    return totalCost;
}

int main() {
    int n;

    
    cout << "Enter the number of files: ";
    cin >> n;

    int files[n];

    cout << "Enter the sizes of the files: ";
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    int totalCost = optimalMergePattern(files, n);
    cout << "Total minimum cost of merging all files: " << totalCost << endl;

    return 0;
}