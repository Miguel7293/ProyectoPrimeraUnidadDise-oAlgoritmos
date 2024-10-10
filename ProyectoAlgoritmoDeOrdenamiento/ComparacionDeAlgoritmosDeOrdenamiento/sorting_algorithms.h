#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <stack>

class SortingAlgorithms {
public:
    static void bubbleSortStep(std::vector<int>& arr, int& i, int& j, int& comparisons, int& swaps);
    static void quickSortStep(std::vector<int>& arr, std::stack<std::pair<int, int>>& stack, int& comparisons, int& swaps);
    static void insertionSortStep(std::vector<int>& arr, int& i, int& j, int& comparisons, int& swaps);
    static void selectionSortStep(std::vector<int>& arr, int& i, int& comparisons, int& swaps);

    // Aquí aseguramos que mergeSortStep tenga la firma correcta
    static void mergeSortStep(std::vector<int>& arr, std::stack<std::tuple<int, int, bool>>& mergeStack, int& comparisons);
    static void merge(std::vector<int>& arr, int l, int m, int r, int& comparisons);
};


#endif // SORTING_ALGORITHMS_H
