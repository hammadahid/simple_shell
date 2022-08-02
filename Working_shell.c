#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFERSIZE 32
#define SH_TOK " "
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
   while (token != NULL)
   {
       arg[position] = token;
       position++;
       token = strtok(NULL, SH_TOK);
   }
    arg[position] = NULL;
    return (arg);
}
void _exec(char **list){
    pid_t child;
    child = fork();
    char *str_exit = "exit";
    // check for exit condition
    for(int i = 0; list[i]; i++)
    {
       if (strcmp(str_exit, list[i]) == 0)
       {
           exit(0);
       }
    }
    if (child == -1)
    {
    perror("Fork error\n");
    }
    if (child == 0)
    {
    if(execve(list[0],list,NULL) == -1)
    {
        perror("Execve failed\n");
    } 
    }
}
int main()
{
putchar('$');
putchar(' ');
char *line = sh_readline();
char **args = sh_parse(line);
_exec(args);
free(line);
free(args);
}