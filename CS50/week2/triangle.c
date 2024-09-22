#include <cs50.h>
#include <stdio.h>

bool triangle(int a, int b, int c);

int main(void)
{
    // Create the inputs to get the size

    int lado_a = get_int("length: ");
    int lado_b = get_int("length: ");
    int lado_c = get_int("length: ");

    // Recive the output of the function

   bool triangle_result = triangle(lado_a, lado_b, lado_c);

   if(triangle_result == true)
   {
     printf("true");
   }else
   {
    printf("false");
   }
}

bool triangle(int a, int b, int c)
{
    // check if the length of the sizes ar positive

    if (a < 0 || b < 0 || c < 0)
    {
        return false;
    }
    else if ((a + b) < c)
    {
        return false;
    }
    else
    {
        return true;
    }

}
