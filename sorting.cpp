#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to hold the performance metrics of each algorithm
struct SortResult {
    string name;
    int comparisons;
    int swaps;
    
    // Total operations used to determine overall efficiency
    int totalOperations() const {
        return comparisons + swaps;
    }
};

// A) Simple Sort (Exchange Sort)
SortResult simpleSort(vector<int> arr) {
    SortResult result = {"Simple Sort", 0, 0};
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            result.comparisons++;
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
                result.swaps++;
            }
        }
    }
    return result;
}

// B) Bubble Sort (Optimized with early exit)
SortResult bubbleSort(vector<int> arr) {
    SortResult result = {"Bubble Sort", 0, 0};
    int n = arr.size();
    bool swapped;
    
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            result.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                result.swaps++;
                swapped = true;
            }
        }
        // If no two elements were swapped, the array is sorted
        if (!swapped) break;
    }
    return result;
}

// C) Insertion Sort
SortResult insertionSort(vector<int> arr) {
    SortResult result = {"Insertion Sort", 0, 0};
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Count the first comparison that will happen in the while loop condition
        if (j >= 0) result.comparisons++; 
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            result.swaps++; // Counting array shifts as swaps for the metric
            j--;
            
            // Count subsequent comparisons in the while loop
            if (j >= 0) result.comparisons++; 
        }
        arr[j + 1] = key;
    }
    return result;
}

// D) Selection Sort
SortResult selectionSort(vector<int> arr) {
    SortResult result = {"Selection Sort", 0, 0};
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            result.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
            result.swaps++;
        }
    }
    // Print the sorted array once just to prove it works
    cout << "Sorted Data: ";
    for(int val : arr) cout << val << " ";
    cout << "\n\n";
    
    return result;
}

int main() {
    int n;
    cout << "Enter the number of data items: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a valid number of items." << endl;
        return 1;
    }

    vector<int> data(n);
    cout << "Enter the " << n << " unsorted integers separated by spaces:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "\nProcessing sorts...\n";
    
    // Run all algorithms
    vector<SortResult> results;
    results.push_back(simpleSort(data));
    results.push_back(bubbleSort(data));
    results.push_back(insertionSort(data));
    results.push_back(selectionSort(data)); // This one also prints the sorted array

    // Display Results Table
    cout << string(55, '-') << "\n";
    cout << left << setw(18) << "Algorithm" 
         << setw(15) << "Comparisons" 
         << setw(10) << "Swaps" 
         << "Total Operations\n";
    cout << string(55, '-') << "\n";

    SortResult bestAlgo = results[0];

    for (const auto& res : results) {
        cout << left << setw(18) << res.name 
             << setw(15) << res.comparisons 
             << setw(10) << res.swaps 
             << res.totalOperations() << "\n";
             
        // Determine the most efficient
        if (res.totalOperations() < bestAlgo.totalOperations()) {
            bestAlgo = res;
        }
    }
    cout << string(55, '-') << "\n";

    // Output Conclusion
    cout << "\nCONCLUSION:\n";
    cout << "Based on the given data, the most efficient algorithm is **" 
         << bestAlgo.name << "**.\n";
    cout << "It required the least amount of total operations (" 
         << bestAlgo.totalOperations() << " combined comparisons and swaps).\n";

    return 0;
}