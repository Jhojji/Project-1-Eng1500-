#include <stdio.h>
//Function Prototypes
int encryptionRotation(int encryptionKey, char letter);

int main() {
    //alphabet values for future use
int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7, i = 8, j = 9, k = 10, l = 11, m = 12, n = 13, o = 14, p = 15, q = 16, r = 17;
int s = 18, t = 19,  u = 20, v = 21, w = 22, x = 23, y = 24, z = 25;
int encryptionKey;
char letter;

//Encryption key is created
    printf("Please enter the encryption key: ");
    scanf("%d", &encryptionKey);

    printf("Please enter a letter to be encrypted: ");
    scanf("%s", &letter);
    printf("%d", (int)letter);

    //This converts lowercase to uppercase
 if(letter >= 97){
    letter -= 32;
    }
    //This will convert ascii numbers from previous bit into a 0-25 number, equivalent to the ints created at the start of the code (a-z)
    letter -= 65;
    //Encrypts letters
    letter += encryptionKey;
    letter += 65;
    printf("%c", letter);
    
return 0;
}
/*
//Rotation Cipher Encryption Function
int encryptionRotation(int encryptionKey, char letter) {
    
    //This will submit entered characters into their ascii numbers
    printf("Please enter a letter to be encrypted: \n");
    scanf("%c", &letter);
    printf("%d", (int)letter);

    //This converts lowercase to uppercase
 if(letter >= 97)
    letter -= 32;
//This will convert ascii numbers from previous bit into a 0-25 number, equivalent to the ints created at the start of the code (a-z)
    letter -= 65;
}
*/ 
