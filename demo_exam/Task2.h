#pragma once

double epsilon = 0.00001;

double abs(double a) {
	return (a < 0) ? -a : a;
}

bool equals(double a, double b) {
	if (abs(a - b) > epsilon) {
		return false;
	}
	return true;
}

bool CheckSquare(double x1, double y1, double x2, double y2) {
	if (equals(x1, x2) || equals(y1, y2)) {
		return false;
	}
	if (!equals(abs(x2 - x1), abs(y2 - y1))) {
		return false;
	}
}