#include <iostream>
using namespace std;

int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				if (i == j || j == k || k == i) {
					continue;
				}
				cout << i << j << k << endl;

				// following can be used instead
				//if (i != j && j != k && k != i) { 
				//	cout << i << j << k << endl;
				//}
			}
		}
	}
	return 0;
}