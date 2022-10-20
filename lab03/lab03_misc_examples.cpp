#include <iostream>
using namespace std;

int main() {
	unsigned int number;
	cin >> number; // see what happens if you try to enter a negative number
	cout << number << endl;  

	int a = 5;
	int b = 0;
	double c = 0.0;

	cout << a / c << endl; // note that this will be executed, pay attention to the result

	// cout << a / b << endl;
	// you can uncomment the line above to see what happens

	return 0;
}