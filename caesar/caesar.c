#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


bool only_digits(string plaintext);
char rotate(char plainchar, int key);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    //for loop
    for (int i = 0; i < strlen("plaintext"); i++)
    {
        //if (is alpha)
        if (isalpha(plaintext[i]))
        {
            //print text
            printf("%c", rotate(plaintext[i], key));
        }
        //else (is #/ $@#$)
        else
        {
            //print #/ $@#$
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}




bool only_digits(string plaintext)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isdigit(plaintext[i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
    }
    return true;
}



char rotate(char plainchar, int key)
{
    if (islower(plainchar))
    {
        char cipherchar = plainchar - '`';
        cipherchar += key;
        cipherchar = cipherchar % 26;
        cipherchar += '`';
        return cipherchar;
    }
    else if (isupper(plainchar))
    {
        char cipherchar = plainchar - '@';
        cipherchar += key;
        cipherchar = cipherchar % 26;
        cipherchar += '@';
        return cipherchar;
    }

    else
    {
        char cipherchar = plainchar;
        return cipherchar;
    }
}

