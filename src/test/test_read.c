#include "test.h"
#include <errno.h>
#include <fcntl.h>
#include <string.h>

static int test_read(int fd, char *buf, char *buf2, size_t nbyte) {
    clock_t start;
    clock_t end;
    ssize_t ret;
    ssize_t ret2;
    int errno_tmp;
    double time_spent;
    double time_spent2;
    int res;

    start = clock();
    ret = ft_read(fd, buf, nbyte);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    errno_tmp = errno;

    start = clock();
    ret2 = read(fd, buf2, nbyte);
    end = clock();
    time_spent2 = (double)(end - start) / CLOCKS_PER_SEC;

    if (g_verbose) {
        printf("Test ft_read with arg: %i, %p, %li\n", fd, buf, nbyte);
        printf("ft_read(\"%i, %p, %li\") =\t%li\n", fd, buf, nbyte, ret);
        printf("read(\"%i, %p, %li\") =\t%li\n", fd, buf, nbyte, ret2);
        printf("ft_read errno = %i\nread errno = %i\n", errno_tmp, errno);
        printf("%s\n%s\n", buf, buf2);
        printf("Time ft_read:\t%f\n", time_spent);
        printf("Time read:\t%f\n\n", time_spent2);
    }
    res = (ret != ret2) || errno_tmp != errno;
    if (buf && buf2)
        res = res || (strcmp(buf, buf2) != 0);
    return (res);
}

int read_normal() {
    int ret = 0;
    int fd = open("test_folder/test.txt", O_RDONLY);
    char buf[100] = {0};
    char buf2[100] = {0};

    ret = test_read(fd, buf, buf2, strlen("Hello World"));
    close(fd);
    return (ret);
}

int read_bad_fd() {
    int ret = 0;
    int fd = -1;
    char buf[100] = {0};
    char buf2[100] = {0};

    ret = test_read(fd, buf, buf2, strlen("Hello World"));
    return (ret);
}

int read_bad_buf() {
    int ret = 0;
    int fd = open("test_folder/test.txt", O_RDONLY);
    char *buf = NULL;
    char *buf2 = NULL;

    ret = test_read(fd, buf, buf2, strlen("Hello World"));
    close(fd);
    return (ret);
}

int all_read() {
    int ret = 0;

    if (g_verbose)
        printf("Test ft_read:\n------------------\n\n");
    ret += result_test(read_normal, "read normal");
    ret += result_test(read_bad_fd, "read bad fd");
    ret += result_test(read_bad_buf, "read bad buf");
    return (ret);
}