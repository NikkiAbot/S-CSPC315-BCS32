// Problem 1: Mathematical Foundations
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double distance(const vector < pair < int, int >> & points) {
    double dist = 0.0;
    for (int i = 0; i < points.size() - 1; ++i){
        double x = points[i + 1].first - points[i].first;
        double y = points[i + 1].second - points[i].second;
        dist += sqrt(x * x + y * y);
    }
    return dist;
}

int SumOfNaturalNumbers(int N){
    return N * (N + 1) / 2;
}

int main(){
    int N;
    cout << "Enter the number of delivery inputs: ";
    cin >> N;

    vector < pair < int, int >> points (N);
    for (int i = 0; i < N; ++i){
        cout << "Enter the coordinate (x) for point " << i + 1 << ": ";
        cin >> points[i].first;
        cout << "Enter the coordinate (y) for point " << i + 1 << ": ";
        cin >> points[i].second;

        // In here we display the points in (x y)
        cout << "Point " << i + 1 << " = (" << points[i].first << ", " << points[i].second << ") \n" << endl;
    }


    cout << "Total distance traveled: " << distance(points) << endl;
    cout << "Sum of the first " << N << " natural numbers " << SumOfNaturalNumbers(N) << endl;

    return 0;
}
