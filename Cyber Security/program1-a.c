
//Implement the following Substitution & Transposition Techniques concepts: (a) Caesar Cipher (b) Rail fence row & Column Transformation
//(a) Caesar Cipher
#include <stdio.h>
#include <ctype.h>

void caesar_encrypt(char *text, int shift) {
    char ch;
    int i = 0;
    while (text[i] != '\0') {
        ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            text[i] = (ch - base + shift) % 26 + base;
        }
        i++;
    }
}

void caesar_decrypt(char *text, int shift) {
    caesar_encrypt(text, 26 - (shift % 26));  
}

int main( ) {
    char message[1000];
    int shift;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the shift value: ");
    scanf("%d", &shift);

   
    caesar_encrypt(message, shift);
    printf("Encrypted message: %s", message);


    caesar_decrypt(message, shift);
    printf("Decrypted message: %s", message);

    return 0;
}
