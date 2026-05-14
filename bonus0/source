
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void p(char *dest, const char *prompt)
{
	char buffer[0x1008];

	puts(prompt);
	read(0, buffer, 0x1000);

	*strchr(buffer, '\n') = '\0';

	strncpy(dest, buffer, 0x14);
}

static void pp(char *dest)
{
	char first[0x14];
	char second[0x14];

	p(first, " - ");
	p(second, " - ");

	strcpy(dest, first);
	strcat(dest, " ");
	strcat(dest, second);
}

int main(void)
{
	char result[42];

	pp(result);
	puts(result);

	return 0;
}
