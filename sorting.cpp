#include "includeAll.h"
using namespace std;

//--------------------------------------------------------------------

// "Bubble Sort" O(N^2)
void sort (int *listOfElements, int sizeOfList) {
	for (int i = 0; i < sizeOfList - 1; ++i) {
		for (int j = i+1; j < sizeOfList; ++j) 
            // If the element in the pos " i " is bigger than the element
            // in the pos " j ", we need to swap them to have the list in
            // an  ASC order, if you wish to sort the list in DESC order change the
            // comparison operator to less than " < "
            if (listOfElements[i] > listOfElements[j]) 
                swap (listOfElements[i], listOfElements[j]);
		// Print the list with the state of each iteration to simulate the bubble sort
		// For the user
		
		cout << "Iteration #" << i + 1 << ":" ;
		for (int k = 0; k < sizeOfList; ++k)
			cout << listOfElements[k];
		cout << endl;
	}
}

//--------------------------------------------------------------------

// "Insertion Sort"  O(N^2).
void sort (int *listOfElements, int size) {
    // This sorting method works by doing inplace comparison between it's
    // elements, basically the algorithm Assumes that from index 0 to the hole
    // all elements are sorted, after making this assumption the algorithm
    // compares all the elements from the unsorted subarray to all the elements
    // in the sorted subarray. If the element is found greater than the element
    // in sorted subarray. Insert this element in the sorted subarray and
    // shift all the elements accordingly
	int value = 0, hole = 0;
	for (int i = 1; i < size; ++i) {
		value = listOfElements[i];
		hole = i;

		while (hole > 0 && listOfElements[hole-1] > value) {
			listOfElements[hole] = listOfElements[hole-1];
			hole = hole - 1;
		}
		listOfElements[hole] = value;

    // Print the list with the state of each iteration to simulate the Insertion sort
    // for the user
	cout << "Iteration #" << i+1 << ":" ;
	for (int k = 0; k < size; ++k)
		cout << listOfElements[k];
	cout << endl;
	}
}

//--------------------------------------------------------------------

//Merge sort algorithm O(nlogn)
void merge (int array[], int beg, int mid, int end) {
	
	int i = 0, j = 0, k = 0, L[100] = { 0 }, R[100] = { 0 };
	int n1 = mid - beg + 1;
	int n2 = end - mid;
	
	//Initial array is divided into 2 halves. Left array 'L' and right array 'R'.
	for (i = 0; i < n1; i++)
        L[i] = array[beg + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];
	
	i = 0; j = 0; k = 0;
	
	/* Compare elements of L and R, now when sorting in ascending order, 
	all elements on the left half must be lesser than all elements on the right half.
	So, the smaller of the two, L[i] and R[i] is updated in the main array. 
	*/
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			array[k++] = L[i++];
		else
			array[k++] = R[j++];
	}
	/* Since L and R are not incremented equally in the previous while loop,
	there may be some elements remaining in either L or R. These are just appended directly to the main array.
	*/
	while (i < n1)
		array[k++] = array[i++];
	while (j < n2)
		array[k++] = array[j++];
}

/*This function is used to get the mid-point of the array, and to recursively call the function,
so that the array is recursively divided, so as to make the computation in merge function very less.
Array is divided till beg<end, that is, till only 2 elements is remaining in each divided array.
*/
void sort (int array[], int beg, int end) {
	if (beg < end) {
	
		int mid = beg + (end-1)/2;
	
		sort (array, beg, mid);
		sort (array, mid+1, end);
		merge (array, beg, mid, end);
	}
}

int partition (int array[], int start, int end) {
	int pivot = array[end];
	int j = start;
	
	for (int i = 1; i < end; ++i) {
		if (array[i] <= pivot) {
			++j;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		} 
	}
	int temp = array[j+1];
	array[j+1] = array[end];
	array[end] = temp;
	
	return (j+1);
}


void sort (int array[], int start, int end) {
	
	if (start < end) {
		int index = partition (array, start, end);
		
		sort (array, start, index-1);
		sort (array, index+1, end);
	}
	
} 
//--------------------------------------------------------------------
// "Selection Sort" O(N^2).
void sort (vector<int>& listOfElements) {
	// The selection sort algorithm divides the list into two parts
	// the subarray of already sorted elements which is built from left
	// to right the sorted sublist is empty and the unsorted list is the entire list
	// the algorithms finds the smallest element in the unordered subarray and swaps
	// it wit the left most element in the array and then moves the subarray boundry
	// one element to the right

	// Select the minimun index in the sorted subarray
	int minIndex = 0;

	// Advance the position of the last item in the sorted subarray
	// through the entire array
	for (int i = 0; i < listOfElements.size()-1; ++i) {
		// We assume the min element is the first element
		minIndex = i;

		// Find the min element by testing elemens after i
		// in the unsorted subarray
		for (int j = i+1; j < listOfElements.size(); ++j) {
			// If the element is less, then it should become the new minimun
			if (listOfElements[minIndex] > listOfElements[j])
				minIndex = j;
		}
		swap (listOfElements[minIndex], listOfElements[i]);

		// Print the list with the state of each iteration to simulate the bubble sort
		// For the user
		cout << "Iteration #" << i+1 << ":" ;
		for (int k = 0; k < listOfElements.size(); ++k)
			cout << listOfElements[k];
		cout << endl;
	}
}



int main () {

  // Read and declare size of desired list by user
	int sizeOfList, *listOfElements;
	cout << "Enter Size: " << endl;
	cin >> sizeOfList;

	// Declare vector to save list of elements
	listOfElements = (int *)malloc(sizeOfList * sizeof(int));

	// Receive list elements from the user and save them in the vector
	cout << endl << "Enter elements: " << endl;
	for (int i = 0; i < sizeOfList; ++i)
	  cin >> listOfElements[i];

    // Print the list before sorting for the user
	cout << endl << "Array before sorting: " << endl;
	for (int i = 0; i < sizeOfList; ++i)
		cout << listOfElements[i];
	cout << endl << endl;

	// Sort the elements in the list
	sort (listOfElements, sizeOfList);

	// Print the list after the list has been sorted
	cout << endl << "Array after sorting: " << endl;
	for (int i = 0; i < sizeOfList; ++i)
		cout << listOfElements[i];

	free(listOfElements);
	return 0;
}