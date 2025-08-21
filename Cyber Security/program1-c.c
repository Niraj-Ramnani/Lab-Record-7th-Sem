//  3 Column Transformation
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort_key(char *key, int *order) {
    int len = strlen(key);
    char sorted_key[20];
    strcpy(sorted_key, key);

    for (int i = 0; i < len; i++) {
        order[i] = i;
    }

    for (int i = 0; i < len-1; i++) {
        for (int j = i+1; j < len; j++) {
            if (sorted_key[order[i]] > sorted_key[order[j]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }
}

void column_encrypt(char *text, char *key, char *result) {
    int key_len = strlen(key);
    int text_len = strlen(text);
    int row = (text_len + key_len - 1) / key_len;

    char matrix[row][key_len];
    int k = 0;

 
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < key_len; j++) {
            if (k < text_len)
                matrix[i][j] = text[k++];
            else
                matrix[i][j] = 'X';  
        }
    }

    int order[20];
    sort_key(key, order);

    k = 0;
    for (int i = 0; i < key_len; i++) {
        int col = order[i];
        for (int j = 0; j < row; j++) {
            result[k++] = matrix[j][col];
        }
    }
    result[k] = '\0';
}

void column_decrypt(char *cipher, char *key, char *result) {
    int key_len = strlen(key);
    int text_len = strlen(cipher);
    int row = (text_len + key_len - 1) / key_len;

    char matrix[row][key_len];
    int order[20];
    sort_key(key, order);

    int k = 0;


    for (int i = 0; i < key_len; i++) {
        int col = order[i];
        for (int j = 0; j < row; j++) {
            matrix[j][col] = cipher[k++];
        }
    }

   
    k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < key_len; j++) {
            result[k++] = matrix[i][j];
        }
    }
    result[k] = '\0';
}

int main() {
    char text[1000], key[20], encrypted[1000], decrypted[1000];

    printf("Enter the message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  

    printf("Enter the key (e.g., ZEBRAS): ");
    scanf("%s", key);

    column_encrypt(text, key, encrypted);
    printf("Encrypted Message: %s\n", encrypted);

    column_decrypt(encrypted, key, decrypted);
    printf("Decrypted Message: %s\n", decrypted);

    return 0;
}

