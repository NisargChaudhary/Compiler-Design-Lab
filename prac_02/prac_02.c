/*
    A program to count digits, vowels, and symbols in a given line of text
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_vowel(char c) {
    c = tolower((unsigned char)c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void) {
    char buf[2048];
    unsigned long digits = 0, vowels = 0, symbols = 0;

    printf("Enter a line (press Enter):\n");
    if (!fgets(buf, sizeof(buf), stdin)) {
        return 0;
    }

    for (size_t i = 0; i < strlen(buf); ++i) {
        unsigned char ch = buf[i];
        if (isdigit(ch)) {
            ++digits;
        } else if (isalpha(ch)) {
            if (is_vowel(ch)) ++vowels;
        } else if (ch == '\n' || isspace(ch)) {
        } else {
            ++symbols;
        }
    }

    printf("Digits: %lu\n", digits);
    printf("Vowels: %lu\n", vowels);
    printf("Symbols: %lu\n", symbols);

    return 0;
}
