#include <bits/stdc++.h>
using namespace std;
#define RANGE 255

// A utility function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(int arr[], int n) {  
    int i, key, j;  
    for (i = 1; i < n; i++) {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
}

void hashTableSort(int arr[], int n)
{
    int hash_table[100000] = {};

    for (int i = 0; i < n; i++) {
        hash_table[arr[i]]++;
    }

    int j = 0;
    for (int i = 0; i < 100000; i++)
    {
        while (hash_table[i] > 0)
        {
            arr[j] = i;
            hash_table[i]--;
            j++;
        }
    }
}
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  

int main() {
    int x;

    for (x = 1; x <= 5; x++) {
        double average_time, smallest_time, largest_time, total_time;
        vector<double> average, smallest, largest;
        clock_t s1, e1;

        for (int n = 0; n <= 1000; n += 10) {        
            smallest_time = DBL_MAX;
            largest_time = DBL_MIN;
            total_time = 0;

            for (int i = 0; i < 100; i++) {
                int arr[n];
                for (int i = 0; i < n; i++) {
                    arr[i] = rand() % 100000;
                }

                if (x == 1) {
                    s1 = clock();
                    insertionSort(arr, n);
                    e1 = clock();
                } else if (x == 2) {
                    s1 = clock();
                    quickSort(arr, 0, n - 1);
                    e1 = clock();
                } else if (x == 3) {
                    s1 = clock();
                    mergeSort(arr, 0, n - 1);
                    e1 = clock();
                } else if (x == 4) {
                    s1 = clock();
                    heapSort(arr, n);
                    e1 = clock();
                } else {
                    s1 = clock();
                    hashTableSort(arr, n);
                    e1 = clock();
                }

                double time = (double(e1 - s1) / double(CLOCKS_PER_SEC));
                if (time > largest_time) {
                    largest_time = time;
                }
                if (time < smallest_time) {
                    smallest_time = time;
                }

                total_time += time;
            }

            average_time = total_time / 100;

            average.push_back(average_time);
            smallest.push_back(smallest_time);
            largest.push_back(largest_time);
        }

        for (int i = 0; i < largest.size(); i++) {
            cout << fixed << largest[i] * 1000 << setprecision(6) << endl;
        }
        cout << endl;

        for (int i = 0; i < smallest.size(); i++) {
            cout << fixed << smallest[i] * 1000 << setprecision(6) << endl;
        }
        cout << endl;

        for (int i = 0; i < average.size(); i++) {
            cout << fixed << average[i] * 1000 << setprecision(6) << endl;
        }
        cout << endl;

        cout << endl << endl;
    }
}



