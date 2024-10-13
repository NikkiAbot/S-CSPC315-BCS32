#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// This function calculates the distance between two points
double calculateDistance(pair <int, int> p1, pair <int, int> p2){
	double x = p2.first - p1.first;
	double y = p2.second - p1.second;
	return sqrt(x * x + y * y);
}

// This function calculates the total distance for a sequence of points
double totalDistance(const vector < pair < int, int >> & points){
	double total_dist = 0.0;
	for (int i = 0; i < points.size() - 1; ++i){
		total_dist += calculateDistance(points[i], points[i + 1]);
	}
	return total_dist;
}

// This function calculates the sum of the first N natural numbers
int sumOfNaturalNumbers(int N){
	return (N * (N + 1)) / 2;
}

int main(){
	// Number of points
	int N;
	cout << "Enter the number of delivery points: ";
	cin >> N;

	vector < pair < int, int >> points(N);

	// Input the delivery points
	cout << "Enter the coordinates (x y) for each point: " << endl;
	for (int i = 0; i < N; ++i){
		cin >> points[i].first >> points[i].second;
		cout << "Values of x and y in point[" << (i + 1) << "]: (" << points[i].first << ", " << points[i].second << ")" << endl;
}

	// Calculate total distance
	double total_dist = totalDistance(points);
	cout << "\nTotal distance traveled: " << total_dist << endl;

	// Calculate the sume of the first N natural numbers
	int sum_N = sumOfNaturalNumbers(N);
	cout << "Sum of the first " << N << " natural numbers: " << sum_N << endl;

	return 0;
}
