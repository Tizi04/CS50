#include <stdio.h>
#include <cs50.h>

void encrypting(string word, int key);

int main(void) {
    string word = get_string("plaintext: ");
    int key = get_int("Ingrese en numero de llave: ");
    while(key > 25){
        key = get_int("ingrese en numero de llave menor a 25: ");
    }
    encrypting(word, key);
    printf("ciphertext: %s\n", word);
}

void encrypting(string word, int key) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] = (word[i] + key);
        } else if (word[i] >= 'A' && word[i] <= 'Z'){
            word[i] = (word[i] + key);
        }
    }
}



