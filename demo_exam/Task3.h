#pragma once

int length(long a) {
	if (a == 0) {
		return 1;
	}

	int length = 0;
	while (a != 0) {
		length++;
		a /= 10;
	}

	return length;
}

int DigitPos(long num, int k) {
	int numlen = length(num);

	if (numlen < k) {
		return -1;
	}

	for (int i = 0; i < numlen - k; i++) {
		num /= 10;
	}

	return num % 10;
}