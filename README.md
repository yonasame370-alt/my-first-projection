Enter the number of data items: 5
Enter the 5 unsorted integers separated by spaces:
5 2 4 1 3

Processing sorts...
Sorted Data: 1 2 3 4 5 

-------------------------------------------------------
Algorithm         Comparisons    Swaps     Total Operations
-------------------------------------------------------
Simple Sort       10             7         17
Bubble Sort       10             7         17
Insertion Sort    9              7         16
Selection Sort    10             3         13
-------------------------------------------------------

CONCLUSION:
Based on the given data, the most efficient algorithm is **Selection Sort**.
It required the least amount of total operations (13 combined comparisons and swaps).
Enter number of elements: 10
Enter elements: 10 20 30 40 50 60 70 80 90 100
Enter target element: 70

--- Results ---
Sequential Search: Found (Comparisons = 7)
Binary Search: Found (Comparisons = 2)

--- Efficiency ---
Binary Search is more efficient.
How the Search Logic Worked
1. Sequential Search (Linear)
The algorithm starts at the first index and checks every single element until it finds the target.

It checked: 10, 20, 30, 40, 50, 60, 70.

Total Comparisons: 7.

2. Binary Search (Divide and Conquer)
Binary Search requires a sorted array (which your code handles using sort()). It jumps to the middle and eliminates half of the possibilities each time.

First check: It looks at the middle of the 10 elements (usually index 4 or 5). Let's say it checks 50.

Comparison: 70 > 50, so it ignores everything below 50.

Second check: it looks at the middle of the remaining upper half and finds 70 (or 80, then 70).

Total Comparisons: 2 (or 3, depending on the specific rounding of the mid calculation).
