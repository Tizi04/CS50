#include <stdio.h>
#include <cs50.h>


int main(void)
{
    string name = get_string("ur name: ");
    string last_name = get_string("ur last name: ");
    int age = get_int("ur age: ");
    int phone_number = get_int("ur number: ");
    printf("Your Name: %s\n Last Name: %s\n Age: %i\n Phone Number: %i\n", name, last_name, age, phone_number);
}


