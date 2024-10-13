#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char buffer){
	if (n == 1){
		cout << "Move package 1 from " << source << " to " << destination << endl;
	return;
	}

	// This will move the n-1 packages from source to buffer
	towerOfHanoi(n - 1, source, buffer, destination);

	// This will move the nth package from source to destination
	cout << "Move package " << n << " from " << source << " to " << destination << endl;

	// This will move the n-1 packages from buffer to destination
	towerOfHanoi(n - 1, buffer, destination, source);
}

int main(){
	int N;
	cout << "Enter the number of packages: ";
	cin >> N;

	cout << "Number of moves to solve the Tower of Hanoi for " << N << " packages:" << endl;
	// A = Source, C = Destination, B = Buffer
	towerOfHanoi(N, 'A', 'C', 'B');

	// And then calculate the total number of moves
	int totalMoves = (1 << N) - 1;
	cout << "Total number of moves required: " << totalMoves << endl;

	return 0;
}
