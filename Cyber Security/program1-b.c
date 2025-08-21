//  2 Rail fence row
//(https://crypto.interactive-maths.com/rail-fence-cipher.html)

#include <stdio.h>
#include <string.h>

void rail_fence_encrypt(char *text, int key, char *result) {
    int len = strlen(text);
    char rail[key][len];
    
 
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    int row = 0, down = 1;
    for (int i = 0; i < len; i++) {
        rail[row][i] = text[i];

        if (row == 0)
            down = 1;
        else if (row == key - 1)
            down = 0;

        row += down ? 1 : -1;
    }

    int k = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                result[k++] = rail[i][j];

    result[k] = '\0';
}

void rail_fence_decrypt(char *cipher, int key, char *result) {
    int len = strlen(cipher);
    char rail[key][len];

   
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';

    
    int row = 0, down = 1;
    for (int i = 0; i < len; i++) {
        rail[row][i] = '*';

        if (row == 0)
            down = 1;
        else if (row == key - 1)
            down = 0;

        row += down ? 1 : -1;
    }

   
    int k = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*' && k < len)
                rail[i][j] = cipher[k++];


    row = 0; down = 1;
    for (int i = 0; i < len; i++) {
        result[i] = rail[row][i];

        if (row == 0)
            down = 1;
        else if (row == key - 1)
            down = 0;

        row += down ? 1 : -1;
    }
    result[len] = '\0';
}

int main() {
    char message[1000], encrypted[1000], decrypted[1000];
    int key;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; 

    printf("Enter the number of rails (key): ");
    scanf("%d", &key);

    rail_fence_encrypt(message, key, encrypted);
    printf("Encrypted message: %s\n", encrypted);

    rail_fence_decrypt(encrypted, key, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}
