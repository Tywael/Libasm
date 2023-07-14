#include "test.h"

int flag() {
    if (g_verbose) {
        printf("NOW u now why no one use this function\n");
        printf("Flag captured\n");
    }
    return (1);
}

static int test_strcpy(char *dest, char *src) {
    clock_t start;
    clock_t end;
    char *ret;
    char *ret2;
    int result;
    double time_spent;
    double time_spent2;
    char *dest_cpy = ft_strdup(dest);
    char *src_cpy = ft_strdup(src);

    start = clock();
    ret = ft_strcpy(src, dest);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    ret2 = strcpy(src_cpy, dest_cpy);
    end = clock();
    time_spent2 = (double)(end - start) / CLOCKS_PER_SEC;
    if (g_verbose) {
        printf("Test ft_strcpy with arg: %s, %s\n", dest, src);
        printf("ft_strcpy(\"%s, %s\") =\t%s\n", dest, src, ret);
        printf("strcpy(\"%s, %s\") =\t%s\n", dest_cpy, src_cpy, ret2);
        printf("Time ft_strcpy:\t%f\n", time_spent);
        printf("Time strcpy:\t%f\n\n", time_spent2);
    }
    free(dest_cpy);
    result = ft_strcmp(ret, ret2);
    free(src_cpy);
    return (result);
}

int strcpy_normal() {
    int ret = 0;
    char dest[12];

    ret = test_strcpy("Hello world", dest);
    return (ret);
}

int strcpy_empty() {
    int ret = 0;

    ret = test_strcpy("", "");
    return (ret);
}

int strcpy_null() {
    int ret = 0;

    ret = test_strcpy("NULL", NULL);
    return (ret);
}

int strcpy_rnull() {
    int ret = 0;

    ret = test_strcpy(NULL, "NULL");
    return (ret);
}

int strcpy_long() {
    int ret = 0;
    char dest[1000];

    ret = test_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec a diam lectus. Sed sit amet ipsum mauris. Maecenas congue ligula ac quam viverra nec consectetur ante hendrerit. Donec et mollis dolor.", dest);
    return (ret);
}

int strcpy_nospace() {
    int ret = 0;
    char dest[10];

    ret = test_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec a diam lectus. Sed sit amet ipsum mauris. Maecenas congue ligula ac quam viverra nec consectetur ante hendrerit. Donec et mollis dolor.", dest);
    return (ret);
}

int strcpy_toospace() {
    int ret = 0;
    char dest[1000];

    ret = test_strcpy("Lorem ipsum", dest);
    return (ret);
}

int strcpy_flag() {
    int ret = 0;
    char dest[1000];

    ret = test_strcpy("Lorem ipsum", dest);
    return (ret);
}

int all_strcpy() {
    int ret = 0;
    if (g_verbose)
        printf("Test ft_strcpy:\n------------------------\n\n");
    ret += result_test(strcpy_normal, "strcpy normal");
    ret += result_test(strcpy_empty, "strcpy empty") == 11 ? 0 : 1;
    ret += result_test(strcpy_null, "strcpy null") == 11 ? 0 : 1;
    ret += result_test(strcpy_rnull, "strcpy rnull") == 11 ? 0 : 1;
    ret += result_test(strcpy_long, "strcpy long");
    ret += result_test(strcpy_nospace, "strcpy nospace") == 11 ? 0 : 1;
    ret += result_test(strcpy_toospace, "strcpy toospace");
    ret += result_test(strcpy_flag, "strcpy flag");
    
    return (ret);
}