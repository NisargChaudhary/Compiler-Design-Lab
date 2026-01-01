#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validate_username(const char *u, char *reason, size_t rlen) {
    size_t len = strlen(u);
    if (len < 5 || len > 15) {
        snprintf(reason, rlen, "username length must be 5..15");
        return 0;
    }
    if (!isalpha((unsigned char)u[0])) {
        snprintf(reason, rlen, "username must start with a letter");
        return 0;
    }
    for (size_t i = 0; i < len; ++i) {
        unsigned char c = (unsigned char)u[i];
        if (!(isalnum(c) || c == '_')) {
            snprintf(reason, rlen, "username may contain only letters, digits, or '_'");
            return 0;
        }
    }
    return 1;
}

int validate_password(const char *p, char *reason, size_t rlen) {
    size_t len = strlen(p);
    if (len < 8) {
        snprintf(reason, rlen, "password must be at least 8 characters");
        return 0;
    }
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    for (size_t i = 0; i < len; ++i) {
        unsigned char c = (unsigned char)p[i];
        if (islower(c)) hasLower = 1;
        else if (isupper(c)) hasUpper = 1;
        else if (isdigit(c)) hasDigit = 1;
        else if (isspace(c)) {
            snprintf(reason, rlen, "password must not contain spaces");
            return 0;
        } else hasSpecial = 1;
    }
    if (!hasLower || !hasUpper || !hasDigit || !hasSpecial) {
        char missing[128] = "missing:";
        int first = 1;
        if (!hasUpper) { if (!first) strncat(missing, ",", sizeof(missing)-strlen(missing)-1); strncat(missing, " upper", sizeof(missing)-strlen(missing)-1); first = 0; }
        if (!hasLower) { if (!first) strncat(missing, ",", sizeof(missing)-strlen(missing)-1); strncat(missing, " lower", sizeof(missing)-strlen(missing)-1); first = 0; }
        if (!hasDigit) { if (!first) strncat(missing, ",", sizeof(missing)-strlen(missing)-1); strncat(missing, " digit", sizeof(missing)-strlen(missing)-1); first = 0; }
        if (!hasSpecial) { if (!first) strncat(missing, ",", sizeof(missing)-strlen(missing)-1); strncat(missing, " special", sizeof(missing)-strlen(missing)-1); }
        snprintf(reason, rlen, "%s", missing);
        return 0;
    }
    return 1;
}

static void strip_newline(char *s) {
    size_t n = strlen(s);
    if (n == 0) return;
    if (s[n-1] == '\n') s[n-1] = '\0';
}

int main(void) {
    char username[64];
    char password[128];
    char reason[256];

    printf("Enter username: ");
    if (!fgets(username, sizeof(username), stdin)) return 0;
    strip_newline(username);

    printf("Enter password: ");
    if (!fgets(password, sizeof(password), stdin)) return 0;
    strip_newline(password);

    if (validate_username(username, reason, sizeof(reason))) {
        printf("Username: valid\n");
    } else {
        printf("Username: invalid (%s)\n", reason);
    }

    if (validate_password(password, reason, sizeof(reason))) {
        printf("Password: valid\n");
    } else {
        printf("Password: invalid (%s)\n", reason);
    }

    if (validate_username(username, reason, sizeof(reason)) && validate_password(password, reason, sizeof(reason))) {
        printf("Overall: credentials are valid\n");
    } else {
        printf("Overall: credentials are invalid\n");
    }

    return 0;
}
