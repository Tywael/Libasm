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
        for (size_t i = 0; i < strlen(str); i++) {
            printf("dup[%ld] = %c, %c\n", i, dup[i], dup2[i]);
        }
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

int strdup_empty() {
    int ret = 0;

    ret = test_strdup("");
    return (ret);
}

int strdup_null() {
    int ret = 0;

    ret = test_strdup(NULL);
    return (ret);
}

int strdup_long() {
    int ret = 0;

    ret = test_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
    return (ret);
}

int all_strdup(void) {
    int ret = 0;

    if (g_verbose)
        printf("Test ft_strdup:\n------------------------\n\n");
    ret += result_test(strdup_normal, "strdup normal");
    ret += result_test(strdup_empty, "strdup empty");
    ret += result_test(strdup_null, "strdup null") == 11 ? 0 : 1;
    ret += result_test(strdup_long, "strdup long");
    return (ret);
}
