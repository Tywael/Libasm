#include "test.h"

static int test_strcmp(char *str, char *str2) {
    clock_t start;
    clock_t end;
    int len;
    int len2;
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
        printf("ft_strcmp(\"%s, %s\") =\t%i\n", str, str2, len);
        printf("strcmp(\"%s, %s\") =\t%i\n", str, str2, len2);
        printf("Time ft_strcmp:\t%f\n", time_spent);
        printf("Time strcmp:\t%f\n\n", time_spent2);
    }
    return (len == len2) ? 0 : 1;
}

int strcmp_normal() {
    int ret = 0;

    ret = test_strcmp("Hello World!", "Hello World!");
    return (ret);
}

int strcmp_empty() {
    int ret = 0;

    ret = test_strcmp("", "");
    return (ret);
}

int strcmp_null() {
    int ret = 0;

    ret = test_strcmp(NULL, NULL);
    return (ret);
}

int strcmp_long() {
    int ret = 0;

    ret = test_strcmp("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec a diam lectus. Sed sit amet ipsum mauris. Maecenas congue ligula ac quam viverra nec consectetur ante hendrerit. Donec et mollis dolor.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec a diam lectus. Sed sit amet ipsum mauris. Maecenas congue ligula ac quam viverra nec consectetur ante hendrerit. Donec et mollis dolor.");
    return (ret);
}

int strcmp_zero() {
    int ret = 0;

    ret = test_strcmp("Hello World!", "");
    return (ret);
}

int strcmp_zero2() {
    int ret = 0;

    ret = test_strcmp("", "Hello World!");
    return (ret);
}

int strcmp_greater() {
    int ret = 0;

    ret = test_strcmp("A", "B");
    return (ret);
}

int strcmp_lower() {
    int ret = 0;

    ret = test_strcmp("B", "A");
    return (ret);
}


int all_strcmp() {
    int ret = 0;
    if (g_verbose)
        printf("Test ft_strcmp:\n------------------------\n\n");
    ret += result_test(strcmp_normal, "strcmp normal");
    ret += result_test(strcmp_empty, "strcmp empty");
    ret += result_test(strcmp_null, "strcmp null") == 11 ? 0 : 1;
    ret += result_test(strcmp_long, "strcmp long");
    ret += result_test(strcmp_zero, "strcmp zero");
    ret += result_test(strcmp_zero2, "strcmp zero2");
    ret += result_test(strcmp_greater, "strcmp greater");
    ret += result_test(strcmp_lower, "strcmp lower");
    return (ret);
}
