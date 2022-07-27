#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int a, int b, int c);


int main(void)
{
  // Get user input
  int a = get_int("Side length 1: ");
  int b = get_int("Side length 2: ");
  int c = get_int("Side length 3: ");

  //Call function valid_triangle()
  bool valid = valid_triangle(a, b, c);


  //Print result
  if (valid)
  {
    printf("These numbers make a triangle: %i %i %i\n", a, b, c);
  }
  else
    printf("These numbers do not make a triangle: %i %i %i\n", a, b, c);

}



bool valid_triangle(int a, int b, int c)
{
  if(a + b > c && b + c > a && a + c > b)
  {
    return true;
  }
  else
    return false;
}