#include <stdio.h>
#include <string.h>

int validateUsername(const char *username) {
    
    if (strlen(username) < 5) {
        return 0; 
    }
    
    for (int i = 0; i < strlen(username); i++) {
        if (!((username[i] >= 'a' && username[i] <= 'z') ||
              (username[i] >= 'A' && username[i] <= 'Z') ||
              (username[i] >= '0' && username[i] <= '9') ||
              (username[i] == '_'))) {
            return 0; 
        }
    }
    return 1;
}

int validatePassword(const char *password) {
   
    if (strlen(password) < 8) {
        return 0; 
    }
    int hasUpper = 0, hasLower = 0, hasDigit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
        }
    }
    return (hasUpper && hasLower && hasDigit);
}

int main() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (validateUsername(username)) {
        printf("Username is valid.\n");
    } else {
        printf("Username is invalid. It must be at least 5 characters long and contain only letters, numbers, or underscores.\n");
    }

    if (validatePassword(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is invalid. It must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, and one digit.\n");
    }

    return 0;
}