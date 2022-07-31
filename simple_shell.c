#include "shell.h"
/**
 * sh_readline - reads users input and stores in a buffer
 * Return: pointer to a string
 */
char *sh_readline(void)
{
char *buffer;
size_t position = 0;
size_t c;/*Int is used instead of char inorder to check for EOF*/
buffer =(char *)malloc(sizeof(char) * BUFFERSIZE);
if (!buffer)
{
    free(buffer);
    perror("Dynamic Allocation Error for buffe\n");
}
while(1)
{
c = getchar();
if (c == EOF || c == '\n' || c == 4)
{
    buffer[position] = '\0';
    return(buffer);
}
else
{
    buffer[position] = c;
}
position ++;
}
}
/**
 * sh_parse - spilts the string into multiple words
 * @str: string literal to be parsed
 * Return: list of strings, args
 */
char **sh_parse(char *str)
{
   char **arg;
   int position = 0;
   char *token;

   arg = malloc(sizeof(char *) * 5);
   if(!arg)
   {
       free(arg);
       perror("Error during allocation of arg\n");
   }
   token = strtok(str, SH_TOK);
   if (!token)
   {
       perror("Error during string tokenization");
   }
   arg[position] = token;
   position += 1;
   while (token)
   {
       token = strtok(NULL, SH_TOK);
       arg[position] = token;
       position++;
   }

   return (arg);
}

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
    sh_readline(); /* Reads the user input,
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
