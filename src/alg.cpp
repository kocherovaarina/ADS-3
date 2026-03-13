// Copyright 2025 NNTU-CS
#include <iostream>
#include <cstdint>
#include "alg.h"

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 0;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }
    return length + 1;
}

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxValue = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > maxValue) {
            maxValue = num;
        }
    }
    return maxValue;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int longestLength = 0;
    uint64_t numberWithLongestLength = lbound;

    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int currentLength = collatzLen(i);
        if (currentLength > longestLength) {
            longestLength = currentLength;
            numberWithLongestLength = i;
        }
    }

    *maxlen = longestLength;
    return numberWithLongestLength;
}
