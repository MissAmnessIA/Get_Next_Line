#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char *s;
	char *a;
	char *b;

	int fd = open("test", O_RDONLY);
	int fd1 = open("test1", O_RDONLY);
	int fd2 = open("test2", O_RDONLY);

	while (1)
	{
		s = get_next_line(fd);
		printf("%s \n", s);
		a = get_next_line(fd1);
		printf("%s \n", a);
		b = get_next_line(fd2);
		printf("%s \n", b);
		if (!s && !a && !b)
			break;
		free (s);
		free(a);
		free(b);
	}
	/*while (1)
	{
		s = get_next_line(fd1);
		printf("%s \n", s);
		if (s == NULL)
			break;
		free (s);
	}
	while (1)
	{
		s = get_next_line(fd2);
		printf("%s \n", s);
		if (s == NULL)
			break;
		free (s);
	}
	*/
	/*
	s = get_next_line(fd2);
	printf("%s \n", s);
	free(s);

	s = get_next_line(fd1);
	printf("%s \n", s);
	free(s);
	s = get_next_line(fd);
	printf("%s \n", s);
	free(s);
	s = get_next_line(fd2);
	printf("%s \n", s);
	free(s);
	s = get_next_line(fd);
	printf("%s \n", s);
	free(s);
	*/
	close(fd);
	close(fd1);
	close(fd2);
	return(0);
}