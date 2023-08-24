#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <time.h>
# include <stdarg.h>
# include <string.h>
# include <setjmp.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft.h"
# include "libasm.h"

# define RED   "\x1b[31m"
# define GREEN "\x1b[32m"
# define RESET "\x1b[0m"

extern int signal_test;
extern int g_verbose;
typedef int (*test_func)(void);

enum e_result
{
	OK,
	KO,
	sigsegv,
	sigbus,
	sigabrt,
	sigfpe,
	sigpip,
	sigill,
	unknown = -1
};

void signal_handler(int signum);
int launch_test(test_func func);
int result_test(test_func func, char *name);
void print_signal(int signal);
int all_strlen(void);
int all_strcmp(void);
int all_strcpy(void);
int all_write(void);
int all_read(void);
int all_strdup(void);


#endif