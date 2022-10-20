#include <iostream>
using namespace std;

int main() {
	long long myNumber = 0;
	cin >> myNumber;
	long long myNumberCopy = myNumber;
	int digitCount = 0;

	if (myNumberCopy == 0) {
		digitCount = 1;
		cout << digitCount << endl;
		return 0;
	}

	while (myNumberCopy != 0) {
		myNumberCopy /= 10;
		digitCount++;
	}

	cout << digitCount << endl;

	return 0;
}