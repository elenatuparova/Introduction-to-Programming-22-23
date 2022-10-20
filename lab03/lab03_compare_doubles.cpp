#include <iostream>
using namespace std;

const double EPSILON = 0.000001;

int main() {
	double first, second;
	cin >> first >> second;

	double difference = first - second;
	double absDifference = difference > 0 ? difference : -difference;
	if (absDifference < EPSILON) {
		cout << "equal";
	}
	else {
		cout << "not equal";
	}
}