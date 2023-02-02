#pragma once

// Task 01
int GetLen(char arr[]) {
    int len = 0;
    while (arr[len] != '\0') {
        len++;
    }
    return len + 1;
}

bool CheckDate(char date[]) {
    if (GetLen(date) != 6) return false;
    if (date[2] != '.') return false;

    int month = (date[3] - '0') * 10 + (date[4] - '0');

    if (month <= 0 || month >= 13) return false;

    int days = (date[0] - '0') * 10 + (date[1] - '0');

    if (days <= 0) return false;

    if (month == 2) {
        return days <= 28;
    }

    if (month % 2 == 0) {
        return days <= 30;
    }
    else {
        return days <= 31;
    }

    return false;
}

// Task 02
bool CheckSquare(double x1, double y1, double x2, double y2) {
    if (x2 - x1 == y2 - y1) return true;
    if (x1 - x2 == y2 - y1) return true;
    if (x1 - x2 == y1 - y2) return true;
    if (x2 - x1 == y1 - y2) return true;
    return false;
}

// Task 03
int ReverseNum(long num) {
    int result = 0;
    while (num != 0) {
        result *= 10;
        result += (num % 10);
        num /= 10;
    }
    return result;
}

int LenInt(long num) {
    int len = 0;
    while (num != 0) {
        len++;
        num /= 10;
    }
    return len;
}

int DigitPos(long num, int k) {
    int lenNum = LenInt(num);
    int reversedNum = ReverseNum(num);
    int lenReversedNum = LenInt(reversedNum);

    if (k > lenNum) return -1;
    if (k > lenReversedNum) return 0;

    int index = 0;
    for (int i = 0; i < k - 1; i++) {
        reversedNum /= 10;
    }
    return reversedNum % 10;
}