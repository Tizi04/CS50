#include <cs50.h>
#include <stdio.h>
#include <math.h>

int every_other_digit(long credit_card);
int multiplyAndSum(int last_digit);
int number_of_digit(long credit_card);
bool isValidAmex(long credit_card, int numbDigit);
bool isValidVisa(long credit_card, int numbDigit);
bool isValidMasterCard(long credit_card, int numbDigit);

int main (void)
{
    long credit_card = get_long("Credit Card: ");
    int sum_every_other_digit = every_other_digit(credit_card);
    int numbDigit = number_of_digit(credit_card);
    bool amex = isValidAmex(credit_card, numbDigit);
    bool visa = isValidVisa(credit_card, numbDigit);
    bool masterCard = isValidMasterCard(credit_card, numbDigit);
    //printf("%i\n", numbDigit);//
    if(sum_every_other_digit %10 != 0){
        printf("INVALID\n");
    }else if(amex == true){
        printf("AMEX\n");
    }else if(visa == true){
        printf("VISA\n");
    }else if(masterCard == true){
        printf("MASTERCARD\n");
    }else{
        printf("INVALID\n");
    }
}

bool isValidAmex(long credit_card, int numbDigit){
    int first_two_digit = credit_card / pow(10, 13);
    if((numbDigit == 15) && (first_two_digit == 34 || first_two_digit == 37)){
        return true;
    } else {
        return false;
    }
}

bool isValidVisa(long credit_card, int numbDigit){
    int first_digit = 0;
    if(numbDigit == 13){
        first_digit = credit_card / pow(10, 12);
    }else{
        first_digit = credit_card / pow(10, 15);
    }
    if((numbDigit == 13 || numbDigit == 16) && (first_digit == 4)){
        return true;
    } else {
        return false;
    }
}

bool isValidMasterCard(long credit_card, int numbDigit){
    int first_two_digit = credit_card / pow(10, 14);
    if((numbDigit == 16) && (first_two_digit == 51 || first_two_digit == 52 || first_two_digit == 53 || first_two_digit == 54 || first_two_digit == 55)){
        return true;
    } else {
        return false;
    }
}

int number_of_digit(long credit_card){
   int ct = 0;
    while(credit_card > 0){
        ct++;
        credit_card = credit_card / 10;
    }
    return ct;
}

int every_other_digit(long credit_card)
{
    int sum = 0;
    bool isAlternateDigit = false;
    while(credit_card > 0)
    {
        if(isAlternateDigit == true){
        int last_digit = credit_card % 10;
        int product = multiplyAndSum(last_digit);
        sum += product;
        }else{
            int last_digit = credit_card % 10;
            sum += last_digit;
        }
        isAlternateDigit = !isAlternateDigit;
        credit_card /= 10;
    }
    //printf("%i\n", sum);//
    return sum;
}

int multiplyAndSum(int last_digit){
    int multiply = last_digit * 2;
    int sum = 0;
    while(multiply > 0){
        int last_digit_multiply = multiply % 10;
        sum = sum + last_digit_multiply;
        multiply = multiply / 10;
    }
    return sum;
}
