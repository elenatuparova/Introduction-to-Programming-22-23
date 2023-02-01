
// DD.MM
const int STR_LEN = 5, DOT_INDEX = 2;
const int DAY_MIN = 1, DAY_MAX = 31;
const int MONTH_MIN = 1, MONTH_MAX = 12;
const int MONTHS_DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool CheckDate(const char arr[]) {
    if(arr == nullptr) {
        return false;
    }
    if(arr[STR_LEN] != '\0') {
        return false;
    }
    for(int i = 0; i < STR_LEN; i++) {
        if((i == DOT_INDEX && arr[i] != '.')) {
            return false;
        }
        else if(i != DOT_INDEX && !(arr[i] >= '0' && arr[i] <= '9')) {
            return false;
        }
    }
    int day = (arr[0] - '0') * 10 + (arr[1] - '0'), month = (arr[3] - '0') * 10 + (arr[4] - '0');
    if(!(day >= DAY_MIN && day <= DAY_MAX && month >= MONTH_MIN && month <= MONTH_MAX)) {
        return false;
    }
    if(day > MONTHS_DAYS[month - 1]) {
        if(month == 2 && day == 29) {
            return true;
        }
        return false;
    }
    return true;
}

const double EPSILON = 0.00000000000000000000001;

double abs(double num) {
    return num < 0 ? -num : num;
}

bool CheckSquare(double x1, double y1, double x2, double y2) {
    if(abs(x1 - x2) < EPSILON && abs(y1 - y2) < EPSILON) {
        return false;
    }
    return abs(abs(x1 - x2) - abs(y1 - y2)) < EPSILON;
}

long pow(long a, int b) {
    long result = 1;
    for(int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int numberLength(long num) {
    int result = 0;
    do {
        result++;
        num /= 10;
    } while(num != 0);
    return result;
}

int DigitPos(long num, int k) {
    if(k <= 0) {
        return -1;
    }
    int length = numberLength(num);
    if(k > length) {
        return -1;
    }
    return (int)(num / pow(10, numberLength(num) - k) % 10);
}

