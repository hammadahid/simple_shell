#ifndef SHELL_H_
#define SHELL_H_
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#define BUFFERSIZE 32
#define SH_TOK " "
int _putchar(char c);
void _puts(char *str);
char *sh_read();
char **sh_parse(char *line);
int sh_execute(char **args);
void sh_loopp(void);
#endif // SHELL_H_
