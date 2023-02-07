#pragma once
bool CheckDate(char date[]) {
	int len = 5;
	if (date[0] >= '0' && date[1] <= '3') {
		if (date[0] == 0 ||
			date[0] == 1 ||
			date[0] == 2) {
			if (date[1] >= '1' && date[1] <= '9') {
				if (date[2] == '.' &&
					(date[3] == '0' || date[3] == '1')
					&& (date[4] == '0' || date[4] == '1' || date[4] == '2')) {
					return true;

				}
			}
		}
		if (date[0] == 3) {
			if (date[1] == '0' || date[1] == '1') {
				if (date[2] == '.' &&
					(date[3] == '0' || date[3] == '1')
					&& (date[4] == '0' || date[4] == '1' || date[4] == '2')) {
					return true;

				}
			}
		}
	}
	return false;
}
double absDif(double a, double b) {
	const double EPSILON = 0.00000001;
	if (a - b < EPSILON || b - a < EPSILON) {
		return 0.0;
	}
	if (a > b) {
		return a - b;
	}
	if (a < b) {
		return b - a;
	}

}
bool CheckSquare(double x1, double y1, double x2, double y2) {
	double absXDif = absDif(x1, x2);
	double absYDif = absDif(y1, y2);
	if (absDif(absXDif, absYDif) == 0 &&
		absXDif != 0) {
		return true;
	}
	return false;
}
int tenPow(int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= n;
	}
	return result;
}
int len(long num) {
	int controlLen = 0;
	while (num != 0) {
		num /= 10;
		++controlLen;
	}
	return controlLen;
}
int DigitPos(long num, int k) {
	int lenNum = len(num);
	int divider = 1;
	int controlKPos = 0;
	while (num != 0) {
		++controlKPos;
		divider = tenPow(lenNum--);
		int currDig = num / divider;
		if (controlKPos == k) {
			return currDig;
		}
		num %= divider;
	}
	return -1;
}