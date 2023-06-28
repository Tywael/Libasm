#include "test.h"

static int test_strcmp(char *str, char *str2) {
    clock_t start;
    clock_t end;
    size_t len;
    size_t len2;
    double time_spent;
    double time_spent2;
    
    start = clock();
    len = ft_strcmp(str, str2);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    len2 = strcmp(str, str2);
    end = clock();
    time_spent2 = (double)(end - start) / CLOCKS_PER_SEC;

    if (g_verbose) {
        printf("Test ft_strcmp with arg: %s\t%s\n", str, str2);
        printf("ft_strcmp(\"%s\") =\t%li\n", str, len);
        printf("strcmp(\"%s\") =\t%li\n", str, len2);
        printf("Time ft_strcmp:\t%f\n", time_spent);
        printf("Time strcmp:\t%f\n\n", time_spent2);
    }
    return (len == len2) ? 0 : 1;
}

int all_strcmp() {
    int ret = 0;
    if (g_verbose)
        printf("Test ft_strcmp:\n------------------------\n\n");
    ret += test_strcmp("Hello World!", "Hello World!");
    ret += test_strcmp("Hello World!", "Hell0 World!");
    ret += test_strcmp("Hell0 World!", "Hello World!");
    ret += test_strcmp("Hello World!", NULL);
    ret += test_strcmp(NULL, "Hello World!");

    return (ret);
}
