#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int calcularPuntos (string word);

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int score1 = calcularPuntos(player1);
    int score2 = calcularPuntos(player2);

    if(score1 > score2){
        printf("Player 1 wins!\n");
    }else if(score2 > score1){
        printf("Player 2 wins!\n");
    }else{
        printf("Tie!\n");
    }
}

int calcularPuntos (string word)
{
    int score = 0;

    for(int i = 0, len = strlen(word); i < len; i++){
        if (isupper(word[i])){
            score = score + POINTS[word[i] - 'A'];
        }else if(islower(word[i])){
            score = score + POINTS[word[i] - 'a'];
        }
    }
    return score;
}
