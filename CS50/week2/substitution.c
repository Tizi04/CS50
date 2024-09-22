#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool only_has_letters(string s);
bool has_unique_characters(string s);
string crypt(string s, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./cipher key\n");
        return 1;
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("The key must contain 26 characters.\n");
        return 1;
    }
    else if (!only_has_letters(key))
    {
        printf("The key must contain only letters.\n");
        return 1;
    }
    else if (!has_unique_characters(key))
    {
        printf("The key must not contain duplicate characters.\n");
        return 1;
    }

    string plainText = get_string("PlainText: ");
    string cyphertext = crypt(plainText, key);
    printf("ciphertext: %s\n", cyphertext);

    return 0;
}

bool only_has_letters(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool has_unique_characters(string s)
{
    bool chars[26] = {false};
    for (int i = 0; i < strlen(s); i++)
    {
        int index = tolower(s[i]) - 'a';
        if (chars[index])
        {
            return false;
        }
        chars[index] = true;
    }
    return true;
}

string crypt(string s, string key)
{
    int n = strlen(s);
    string result = malloc(n + 1); // +1 para el terminador nulo
    if (result == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        if (isupper(s[i]))
        {
            result[i] = toupper(key[s[i] - 'A']);
        }
        else if (islower(s[i]))
        {
            result[i] = tolower(key[s[i] - 'a']);
        }
        else
        {
            result[i] = s[i];
        }
    }
    result[n] = '\0'; // Añadir el terminador nulo

    return result;
}
