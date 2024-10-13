#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// Bubble Sort: This function swaps adjacent elements if they’re out of order
void BubbleSort(vector < int > & arr){
	int bubble = arr.size();
	for (int i = 0; i < bubble - 1; i++){
		for (int j = 0; j < bubble - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// Merge Sort: This function uses the divide-and-conquer sorting algorithm
void MergeSort(vector < int > & arr, int left, int right){
	if (left < right){
		int mid = left + (right - left) / 2;

		// In here we sort the left and right half of the array
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		// And then merge the sorted half
		int sort1 = mid - left + 1;
		int sort2 = right - mid;
		vector < int > L(sort1), R(sort2);

		for (int i = 0; i < sort1; i++){
			L[i] = arr[left + i];
		}

		for (int j = 0; j < sort2; j++){
			R[j] = arr[mid + 1 + j];
		}

		int i = 0, j = 0, k = left;
		while (i < sort1 && j < sort2){
			arr[k++] = (L[i] <= R[j] ? L[i++] : R[j++]);
		}

		while (i < sort1) arr [k++] = L[i++];
		while (i < sort2) arr [k++] = R[j++];
	}
}

void TimeandSort (vector < int > delivery){
	vector < int > timestoSort;

	// We measure and display the results of Bubble Sort
	timestoSort = delivery;
	auto start = chrono::high_resolution_clock::now();
	BubbleSort(timestoSort);
	auto end = chrono::high_resolution_clock::now();

	cout << "Bubble Sort: ";
	for (int time : timestoSort) cout << time << " ";
	cout << "\nTime taken: " << chrono::duration <double> (end - start).count() << "seconds";
	cout << "\nTime Complexity: O(N^2)";
	cout << "\nExplanation: Inefficient for large dataset due to excessive comparison.\n";

	// Next we measure and display the results of Merge Sort
	timestoSort = delivery;
	start = chrono::high_resolution_clock::now();
	MergeSort(timestoSort, 0, timestoSort.size() - 1);
	end = chrono::high_resolution_clock::now();

	cout << "\nMerge Sort: ";
	for (int time : timestoSort) cout << time << " ";
	cout << "\nTime taken: " << chrono::duration <double> (end - start) .count() << "seconds";
	cout << "\nTime Complexity: O(N log N)";
	cout << "\nExplanation: Efficient for larger datasets because it uses divide-and-conquer algorithm.\n";
}

int main(){
	// This creates an array of random numbers or delivery times from small, medium, to large.
	cout << "\nList of Delivery Times: " << endl;
	srand(time(0));
	vector < int > small(5), medium(10), large(20);

	cout << "Small [";
	for (int i = 0; i < small.size(); ++i){
		small[i] = rand() %100;
		cout << small[i];
		if (i < small.size() - 1){
			cout << ", ";
		}
	}
	cout << "]\n";

	cout << "Medium [";
	for (int i = 0; i < medium.size(); ++i){
		medium[i] = rand() %100;
		cout << medium[i];
		if (i < medium.size() - 1){
			cout << ", ";
		}
	}
	cout << "]\n";

	cout << "Large[";
	for (int i = 0; i < large.size(); ++i){
		large[i] = rand() %100;
		cout << large[i];
		if (i < large.size() - 1){
			cout << ", ";
		}
	}

	cout << "]\n";

// And then print the sorted arrays with their elapsed time
	cout << "\n=== SMALL INPUT ===\n";
	TimeandSort(small);

	cout << "\n=== MEDIUM INPUT ===\n";
	TimeandSort(medium);

	cout << "\n=== LARGE INPUT ===\n";
	TimeandSort(large);

	return 0;
}
