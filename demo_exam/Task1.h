#pragma once

int getLength(char str[]) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}

bool isHighMonth(char str[]) {
	if ((str[3] == '1' && str[4] != '1') || str[3] == '3' || str[3] == '5' || str[3] == '7' ||
		str[3] == '8') {
		return true;
	}
	return false;
}

bool CheckDate(char arr[]) {
	if (getLength(arr) !=5){
		return false;
	}

	if (arr[0] > '3' || arr[0] < '0' || arr[1] > '9' || arr[1] < '0' || 
		arr[2] != '.' || arr[3]<'0' || arr[3] > '1' || arr[4] < '0' || arr[4]> '9') {
		return false;
	}

	if ((arr[0] == '0' && arr[1] == '0') || (arr[0] == '3' && arr[1] > '1') ||
		(arr[3] == '0' && arr[4] == '0') || (arr[3] == '1' && arr[4] > '2')) {
		return false;
	}

	if (arr[3] == '0' && arr[4] == '2') {
		if (arr[0] > '2' || (arr[0] == '2' && arr[1] > '8')) {
			return false;
		}
	}

	if (isHighMonth(arr)) {
		if (arr[0] == '3' && arr[1] > '1') {
			return false;
		}
	}
	else {
		if (arr[0] == '3' && arr[1] > '0') {
			return false;
		}
	}

	return true;
}