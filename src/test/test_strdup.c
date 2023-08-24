#include "test.h"

static int test_strdup(char *str) {
    clock_t start;
    clock_t end;
    char *dup;
    char *dup2;
    double time_spent;
    double time_spent2;
    int res;

    start = clock();
    dup = ft_strdup(str);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    dup2 = strdup(str);
    end = clock();
    time_spent2 = (double)(end - start) / CLOCKS_PER_SEC;

    if (g_verbose) {
        printf("Test ft_strdup with arg: %s\n", str);
        printf("ft_strdup(\"%s\") =\t%s\n", str, dup);
        printf("strdup(\"%s\") =\t%s\n", str, dup2);
        printf("Time ft_strdup:\t%f\n", time_spent);
        printf("Time strdup:\t%f\n\n", time_spent2);
    }
    
    res = (strcmp(dup, dup2) != 0);
    free(dup);
    free(dup2);
    return (res);

}

int strdup_normal() {
    int ret = 0;

    ret = test_strdup("Hello World!");
    return (ret);
}

int all_strdup(void) {
    int ret = 0;

    if (g_verbose)
        printf("Test ft_strdup:\n------------------------\n\n");
    ret += result_test(strdup_normal, "strdup normal");
    return (ret);
}
