#include <stdio.h>

int main()
{

    // Null character is only added for string literals
    char single_quote[] = {'s', 't', 'r', 'i', 'n', 'g'};
    char double_quote[] = "string";
    printf("Initializing with chars: %lu\n", sizeof(single_quote));
    printf("Initializing using a string literal: %lu \n", sizeof(double_quote));

    // // Removing null character
    char s0[] = "C++";
    char s1[] = "Python";
    char s2[] = "MATLAB";
    s1[6] = 'x';
    printf("%s\n",s1);

    // // scanf
    // printf("Enter a string: ");
    // char c[10];
    // scanf("%s", c);
    // printf("Using scanf, you entered: %s\n", c);

    // //gets
    // char c2[10];
    // printf("Enter a string: ");
    // gets(c2);
    // printf("Using gets, you entered: %s\n", c2);

    // //fgets

    char c3[10];
    printf("Enter the string: ");
    fgets(c3, 10, stdin); // read from standard input
    printf("Using fgets, you entered is: %s\n", c3);

    // // Array of strings
    char* strings[3] = {"math", "physics", "CS"};
    printf("strings[1] = %s\n", strings[1]);
}