#include "get_next_line.h"
#include <limits.h>
int main()
{
	int fd = open("test", O_RDONLY);
	char *s = NULL;
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	return (0);
}


