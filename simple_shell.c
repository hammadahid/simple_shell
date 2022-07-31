#include "shell.h"

/**
 * sh_loop - main loop of the program
 * Return: void
 */
void sh_loop(void)
{
char **args;
char *line;
int status = 1;
do
{
    _puts("$ ");
    sh_read(); /* Reads the user input,
                * stores it in a buffer called line*/
    sh_parse(line); /* split userinput into words called tokens,
                     * and return an array of those words called args*/
    sh_execute(args); /* execute the contents of the array args*/

    free(line); /* Free dynmically allocated string line */
    free(args); /* Free dynamically allocated array of string, args */
} while (status);
}

/**
 * main - calls sh_loop function
 * Return: EXIT_SUCCESS
 */
int main()
{
sh_loop();
return (EXIT_SUCCESS);
}
