#include "sorting_algorithms.h"

// Bubble Sort paso a paso
void SortingAlgorithms::bubbleSortStep(std::vector<int>& arr, int& i, int& j, int& comparisons, int& swaps) {
    int n = arr.size();

    if (i < n - 1) {
        if (j < n - i - 1) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swaps++;
            }
            j++;
        } else {
            j = 0;
            i++;
        }
    }
}

// Quick Sort paso a paso
void SortingAlgorithms::quickSortStep(std::vector<int>& arr, std::stack<std::pair<int, int>>& stack, int& comparisons, int& swaps) {
    if (!stack.empty()) {
        auto [low, high] = stack.top();
        stack.pop();

        if (low < high) {
            int pivot = arr[high];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                comparisons++;
                if (arr[j] < pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                    swaps++;
                }
            }
            std::swap(arr[i + 1], arr[high]);
            swaps++;

            int pi = i + 1;
            stack.push({low, pi - 1});
            stack.push({pi + 1, high});
        }
    }
}

// Insertion Sort paso a paso
void SortingAlgorithms::insertionSortStep(std::vector<int>& arr, int& i, int& j, int& comparisons, int& swaps) {
    int n = arr.size();
    if (i < n) {
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        comparisons++;
        arr[j + 1] = key;
        i++;
        j = i - 1;  // Restablecer j para el siguiente ciclo
    }
}

// Selection Sort paso a paso
void SortingAlgorithms::selectionSortStep(std::vector<int>& arr, int& i, int& comparisons, int& swaps) {
    int n = arr.size();
    if (i < n - 1) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[minIndex], arr[i]);
        swaps++;
        i++;
    }
}

// Merge Sort paso a paso
void SortingAlgorithms::mergeSortStep(std::vector<int>& arr, std::stack<std::tuple<int, int, bool>>& mergeStack, int& comparisons) {
    if (!mergeStack.empty()) {
        auto [l, r, isMergeStep] = mergeStack.top();
        mergeStack.pop();

        if (isMergeStep) {
            // Fusión de los segmentos ya divididos
            int m = l + (r - l) / 2;
            merge(arr, l, m, r, comparisons);
        } else {
            if (l < r) {
                int m = l + (r - l) / 2;

                // Poner en la pila primero el paso de fusión, luego las divisiones
                mergeStack.push({l, r, true});     // Fusión de l a r
                mergeStack.push({m + 1, r, false}); // División derecha
                mergeStack.push({l, m, false});     // División izquierda
            }
        }
    }
}




void SortingAlgorithms::merge(std::vector<int>& arr, int l, int m, int r, int& comparisons) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crear arrays temporales
    std::vector<int> L(n1), R(n2);

    // Copiar datos a los arrays temporales
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    // Fusionar los arrays temporales de vuelta en arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
