#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letter_count(string s);
int word_count(string s);
int sentences_count(string s);

int main(void)
{
    // Obtener el texto a analizar
    string text = get_string("Text: ");

    // Crear tres variables que reciban los 3 programas
    int letterCount = letter_count(text);
    int wordsCount = word_count(text);
    int sentencesCount = sentences_count(text);

    // Crear una variable y un condicional que determine que grado es el texto

    float l = ((float) letterCount / (float) wordsCount) * 100;
    float s = ((float) sentencesCount / (float) wordsCount) * 100;
    float coleman_index = 0.0588 * l - 0.296 * s - 15.8;

    if (coleman_index < 2)
    {
        printf("Before Grade 1\n");
    }
    else if (coleman_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %0.f\n", round(coleman_index));
    }
}

// Hacer un programa que cuenta cuantas letras tiene el texto

int letter_count(string s)
{
    int ct = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            ct++;
        }
    }
    return ct;
}

// Hacer un programa que cuente cuantas palabras tiene el texto

int word_count(string s)
{
    int ct = 1;

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
        {
            ct++;
        }
    }
    return ct;
}

// Hacer un programa que cuente cuantas oraciones tiene el texto

int sentences_count(string s)
{
    int ct = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            ct++;
        }
    }
    return ct;
}
