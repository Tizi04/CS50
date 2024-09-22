# include <stdio.h>
# include <cs50.h>

float avarage(int length, int array[]);

int main (void)
{
    int n = get_int("Number of scorce: ");
    int scores[n];
    for(int i = 0; i < n; i++){
        scores[i] = get_int("Scores: ");
    }
    printf("Avarage: %f\n", avarage(n, scores));
}

float avarage(int length, int array[]){
   int sum = 0;
    for(int i = 0; i < length; i++){
        sum += array[i];
    }
    return sum / (float) length;
}

