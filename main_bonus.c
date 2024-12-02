#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
	char *s = "";

	int fd = open("test", O_RDONLY);
	int fd1 = open("test1", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);

	s = get_next_line(fd1);
	printf("%s \n", s);
	free(s);
	s = get_next_line(fd2);
	printf("%s \n", s);
	free(s);
	s = get_next_line(fd);
	printf("%s \n", s);
	free(s);
	s = get_next_line(fd2);
	printf("%s \n", s);
	free(s);
	s = get_next_line(fd1);
	printf("%s \n", s);
	free(s);

	close(fd);
	close(fd1);
	close(fd2);
	return(0);
}