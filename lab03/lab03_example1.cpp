#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;

	if (n > 0) {
		long long factorial = 1;
		for (int i = n; i > 0; i--) {
			factorial *= i;
		}
		cout << factorial << endl;
	} 
	else {
		cout << -1 << endl; // you can print another message, showing the input is invalid
	}

	return 0;
}