#include "test.h"

static int test_strlen(char *str) {
    clock_t start;
    clock_t end;
    size_t len;
    size_t len2;
    double time_spent;
    double time_spent2;
    
    start = clock();
    len = ft_strlen(str);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    len2 = strlen(str);
    end = clock();
    time_spent2 = (double)(end - start) / CLOCKS_PER_SEC;

    if (g_verbose) {
        printf("Test ft_strlen with arg: %s\n", str);
        printf("ft_strlen(\"%s\") =\t%li\n", str, len);
        printf("strlen(\"%s\") =\t%li\n", str, len2);
        printf("Time ft_strlen:\t%f\n", time_spent);
        printf("Time strlen:\t%f\n\n", time_spent2);
    }
    return (len == len2) ? 0 : 1;
}

int strlen_normal() {
    int ret = 0;

    ret = test_strlen("Hello World!");
    return (ret);
}

int strlen_empty() {
    int ret = 0;

    ret = test_strlen("");
    return (ret);
}

int strlen_null() {
    int ret = 0;

    ret = test_strlen(NULL);
    return (ret);
}

int strlen_long() {
    int ret = 0;

    ret = test_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec a diam lectus. Sed sit amet ipsum mauris. Maecenas congue ligula ac quam viverra nec consectetur ante hendrerit. Donec et mollis dolor.");
    return (ret);
}

int strlen_zero() {
    int ret = 0;

    ret = test_strlen("Hello\0 World!");
    return (ret);
}

int all_strlen() {
    int ret = 0;
    if (g_verbose)
        printf("Test ft_strlen:\n------------------------\n\n");
    ret += result_test(strlen_normal, "strlen normal");
    ret += result_test(strlen_empty, "strlen empty");
    ret += result_test(strlen_null, "strlen Null") == 11 ? 0 : 1;
    ret += result_test(strlen_long, "strlen long");
    ret += result_test(strlen_zero, "strlen zero");

    return (ret);
}
