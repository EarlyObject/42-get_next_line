#include "get_next_line.h"

int main(void)
{
	FILE *fp;
	char **line = (char**)malloc(sizeof(char));
	//fp = fopen("./testfile.txt", "r");
	//fp = fopen("./empty_lines", "r");
	//fp = fopen("./42_char", "r");
	fp = fopen("./alphabet", "r");
	//fp = fopen("./huge_file", "r");
	//fp = fopen("./1_newline", "r");
	//fp = fopen("./4_newlines", "r");
	//fp = fopen("./empty_file", "r");
	//fp = fopen("./half_marge_bottom", "r");
	//fp = fopen("./half_marge_top", "r");
	//fp = fopen("./huge_alphabet", "r");
	//fp = fopen("./huge_line", "r");
	//fp = fopen("./huge_lines", "r");
	//fp = fopen("./huge_lines2", "r");
	//fp = fopen("./mix_marge1", "r");
	//fp = fopen("./mix_marge2", "r");
	int fd = fileno(fp);
	//printf("file descriptor is %d\n", fd);
	
	int rv;

	while ((rv = get_next_line(fd, line)) >= 0)
	{
		printf("\nmain file output: ");
		printf("%s", *line);
		printf("\n");
		if (rv == 0)
			break ;
	}
	free(line);
	//check_leaks();
	return (0);
}
