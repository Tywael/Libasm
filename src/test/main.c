#include "test.h"

int g_verbose = 0;
int signal_test = 0;

void    test(char *name, test_func func) {
    int ret = func();
    printf("%s: %s\x1b[0m\n", name, ret ? "\x1b[31mFAIL" : "\x1b[32mOK");
    if (g_verbose)
        printf("\n====================\n\n");
}

void print_signal(int signal)
{
	int status;

	if (WIFSIGNALED(signal))
	{
		status = WTERMSIG(signal);
		if (status == SIGBUS)
            printf("This test exited with Bus error [BUS]\n\n");
		if (status == SIGSEGV)
            printf("This test exited with Segmentation fault [SEGV]\n\n");
		if (status == SIGABRT)
            printf("This test exited with Abort [ABRT]\n\n");
		if (status == SIGFPE)
            printf("This test exited with Floating point exception [FPE]\n\n");
		if (status == SIGPIPE)
            printf("This test exited with Broken pipe [PIPE]\n\n");
		if (status == SIGILL)
            printf("This test exited with Illegal instruction [ILL]\n\n");
	}
}

int result_test(test_func func, char *name)
{
    int res = 0;

    if (g_verbose)
        printf("%s: \n", name);
    res = launch_test(func);

    if (res > 2 && g_verbose)
        print_signal(res);
    return (res);
}

int    launch_test(test_func func) {
    pid_t pid;
	int status;
    int res;

	pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
	else if (!pid) {
        res = func();
		if (res == 1)
			exit(1);
		exit(0);
	}
	else
	{
		pid = wait(&status);        
		if (!pid)
			return (1);
        return (status);
	}
    return (status);
}

int main(int argc, char **argv) {
    if (argc > 1)
        g_verbose = 1;
    (void)argv;
    (void)g_verbose;

    printf("This is my tester for libasm\n");
    printf("Usage: ./test [verbose]\n");
    printf("verbose: print details of each test\n");
    printf("verbose mode: \x1b[1m%s\x1b[0m\n\n", g_verbose ? "\x1b[32mON" : "\x1b[31mOFF");
    printf("====================\n\n");
    test("ft_strlen", all_strlen);
    test("ft_strcmp", all_strcmp);
    test("ft_strcpy", all_strcpy);
    test("ft_write", all_write);
    test("ft_read", all_read);
    test("ft_strdup", all_strdup);
    return 0;
}