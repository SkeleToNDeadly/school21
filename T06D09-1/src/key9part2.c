#include <stdio.h>

#define LEN 100

void add(long long* num1, int len1, long long* num2, int len2, long long* result, int* resultLen);
int subtract(long long* num1, int len1, long long* num2, int len2, long long* result, int* resultLen);
int input(long long* num, int* len);
void output(long long* num, int len);
int isValidSubtraction(long long* num1, int len1, long long* num2, int len2);

int main() {
    int success = 1;
    long long number1[LEN], number2[LEN], sumResult[LEN], subtractResult[LEN];
    int len1, len2, sumResultLen, subtractResultLen;

    success = input(number1, &len1);
    if (success) {
        success = input(number2, &len2);
        if (success) {
            add(number1, len1, number2, len2, sumResult, &sumResultLen);
            output(sumResult, sumResultLen);
            printf("\n");

            if (isValidSubtraction(number1, len1, number2, len2)) {
                subtract(number1, len1, number2, len2, subtractResult, &subtractResultLen);
                output(subtractResult, subtractResultLen);
            } else {
                printf("n/a");
            }
        }
    }

    return success;
}

int input(long long* num, int* len) {
    int success = 1;
    char c = ' ';
    int digit;
    *len = -1;

    while (1) {
        if (success == 0) break;

        scanf("%c", &c);

        if (c == '\n') break;
        if (c == ' ') continue;

        digit = c - '0';

        if (digit < 0 || digit > 9) {
            success = 0;
        }

        (*len)++;

        if (*len >= LEN) {
            success = 0;
        }

        num[*len] = digit;
    }

    return success;
}

void output(long long* num, int len) {
    int leadingZeros = 1;

    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == 0 && leadingZeros) {
            continue;
        }

        leadingZeros = 0;
        printf("%lld", num[i]);

        if (i != 0) {
            printf(" ");
        }
    }

    if (leadingZeros) {
        printf("0");
    }
}

void add(long long* num1, int len1, long long* num2, int len2, long long* result, int* resultLen) {
    long long carry = 0;
    *resultLen = 0;

    for (int i = len1, j = len2; i >= 0 || j >= 0 || carry; i--, j--) {
        long long digitSum = carry;

        if (i >= 0) {
            digitSum += num1[i];
        }

        if (j >= 0) {
            digitSum += num2[j];
        }

        result[*resultLen] = digitSum % 10;
        carry = digitSum / 10;
        (*resultLen)++;
    }
}

int subtract(long long* num1, int len1, long long* num2, int len2, long long* result, int* resultLen) {
    long long borrow = 0;
    *resultLen = 0;

    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--) {
        long long digitDiff = borrow;

        if (i >= 0) {
            digitDiff += num1[i];
        }

        if (j >= 0) {
            digitDiff -= num2[j];
        }

        if (digitDiff < 0) {
            borrow = 1;
            digitDiff += 10;
        } else {
            borrow = 0;
        }

        result[*resultLen] = digitDiff;
        (*resultLen)++;
    }

    while (*resultLen > 1 && result[*resultLen - 1] == 0) {
        (*resultLen)--;
    }

    return 1;
}

int isValidSubtraction(long long* num1, int len1, long long* num2, int len2) {
    if (len1 < len2) {
        return 0;  // Invalid subtraction, num2 is greater than num1
    } else if (len1 == len2) {
        for (int i = len1 - 1; i >= 0; i--) {
            if (num1[i] < num2[i]) {
                return 0;  // Invalid subtraction, num2 is greater than num1
            } else if (num1[i] > num2[i]) {
                break;  // Valid subtraction, num1 is greater than num2
            }
        }
    }
    return 1;  // Valid subtraction, num1 is greater than or equal to num2
}
