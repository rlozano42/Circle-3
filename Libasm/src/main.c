#include "../libasm.h"

#define RESET		"\033[0;37m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define BLACKBACK	"\e[97m\e[40m"
#define BLUE		"\033[0;32m"
#define YELLOW		"\033[0;32m"
#define BUFFER_SIZE	512

int 	ret1;
int		ret2;
char	dest1[BUFFER_SIZE];
char	dest2[BUFFER_SIZE];
int 	ret3;
int 	ret4;
char	*str1;
char	*str2;
int		testwrite = 0;
int		testread = 0;


int		strlen_test(char *str)
{
	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	printf("\nINPUT:\n"BLUE"%s"RESET"\n", str);
	printf("ORIGINAL STRLEN:\n" YELLOW "%d" RESET "\nOWN FT_STRLEN:\n" YELLOW "%d" RESET "\n\n-------------------------------------------------------------------------\n", ret1, ret2);
	return (1);
}

int		strcpy_test(char *src)
{
	bzero(dest1, BUFFER_SIZE);
	bzero(dest2, BUFFER_SIZE);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	printf("\nINPUT:\n" BLUE "[%s]" RESET "\n", src);
	printf("ORIGINAL STRCPY:\n" YELLOW "%s" RESET "\nOWN STRCPY:\n" YELLOW "%s" RESET "\n", dest1, dest2);
	return (1);
}

int		strcmp_test(char *s1, char *s2)
{
	ret3 = ft_strcmp(s1, s2);
	ret4 = strcmp(s1, s2);
	printf("\nINPUT:\n" BLUE "%s" RESET " && " BLUE "%s" RESET "\n", s1, s2);
	printf("ORIGINAL STRCMP:\n" YELLOW "%d" RESET "\nOWN STRCMP:\n" YELLOW "%d" RESET "\n\n-------------------------------------------------------------------------\n", ret1, ret2);
	return (1);
}

int		read_test(char *str)
{
	int		ft_read_pipe[2];
	char	buf[BUFFER_SIZE];
	int		ret;

	bzero(buf, BUFFER_SIZE);
	if (pipe(ft_read_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_read_pipe[0], F_SETFL, O_NONBLOCK);
	write(ft_read_pipe[1], str, strlen(str));
	ret = ft_read(ft_read_pipe[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';
	printf("\nINPUT:\n" BLUE "%s" RESET "\n", buf);
	if (!strcmp(buf, str))
		testread++;
	close(ft_read_pipe[1]);
	close(ft_read_pipe[0]);
	return (1);
}

int		write_test(char *str)
{
	int		ft_write_pipe[2];
	char	buf[BUFFER_SIZE];
	int		ret;

	bzero(buf, BUFFER_SIZE);
	if (pipe(ft_write_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_write_pipe[0], F_SETFL, O_NONBLOCK);
	ft_write(ft_write_pipe[1], str, strlen(str));
	ret = read(ft_write_pipe[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';

	printf("\nINPUT:\n" BLUE "%s" RESET "\n", str);
	if (!strcmp(buf, str))
		testwrite++;
	close(ft_write_pipe[1]);
	close(ft_write_pipe[0]);
	return (1);
}

int		strdup_test(char *str)
{
	str1 = ft_strdup(str);
	str2 = strdup(str);
	printf("\nINPUT:\n" BLUE "%s" RESET "\n", str);
	printf("ORIGINAL STRDUP:\n" YELLOW "%s" RESET "\nOWN STRDUP:\n" YELLOW "%s" RESET "\n\n-------------------------------------------------------------------------\n", str1, str2);
	return (1);
}

int	main(void)
{
	/*
	** FT_STRLEN
	*/
	printf("\n" BLACKBACK "------------------------------->FT_STRLEN<-------------------------------" RESET "\n");
	strlen_test("saludos");
	strlen_test("");
	strlen_test("una frase un poco mas larga");
	strlen_test("con un \0 caracter nulo");
	strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus\nmetus, finibus quis sagittis quis, volutpat a justo. Nunc et \npellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	strlen_test("        ");
	printf("\n\n");

	/*
	** FT_STRCPY
	*/
	printf("" BLACKBACK "------------------------------->FT_STRCPY<-------------------------------" RESET "\n");
	strcpy_test("abc");
	strcpy_test("");
	strcpy_test("saludos a todo el mundo");
	strcpy_test("con un \0 caracter nulo");
	strcpy_test("otra frase");
	strcpy_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus\nmetus, finibus quis sagittis quis, volutpat a justo. Nunc et \npellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	strcpy_test("        ");
	printf("\n\n");

	/*
	** FT_STRCMP
	*/
	printf("" BLACKBACK "------------------------------->FT_STRCMP<-------------------------------" RESET "\n");
	strcmp_test("hola", "hola");
	strcmp_test("abcdef", "zcdef");
	strcmp_test("", "hola");
	strcmp_test("una frase un poquito mas larga", "   ");
	strcmp_test("", "");
	strcmp_test("beta", "");
	strcmp_test("te\0", "\0");
	strcmp_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus\nmetus, finibus quis sagittis quis, volutpat a justo. Nunc et \npellentesque quam. Fusce aliquam aliquam libero, ed pulvinar nullam.\n", "\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus\nmetus, finibus quis sagittis quis, volutpat a justo. Nunc et\npellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n\n");
	/*
	** FT_READ
	*/

	printf("" BLACKBACK "-------------------------------->FT_READ<--------------------------------" RESET "\n");
	read_test("hola");
	read_test("hola mi gente");
	read_test("hola \0 mi gente");
	read_test("");
	read_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus\nmetus, finibus quis sagittis quis, volutpat a justo. Nunc et \npellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n\n");
	/*
	** FT_WRITE
	*/
	printf("" BLACKBACK "------------------------------->FT_WRITE<--------------------------------" RESET "\n");
	write_test("");
	write_test("test");
	write_test("test hola");
	write_test("test hola \0 que");
	printf("\n\n");

	/*
	** FT_STRDUP
	*/
	printf("" BLACKBACK "------------------------------->FT_STRDUP<-------------------------------" RESET "\n");
	strdup_test("");
	strdup_test("hola");
	strdup_test("hola guapo");
	strdup_test("hola \0 mi gente");
	strdup_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus\nmetus, finibus quis sagittis quis, volutpat a justo. Nunc et \npellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n");

	/*
	** RESULTS
	*/
	printf("FT_STRLEN ");
	if (ret1 == ret2)
		printf("=========================================================>" GREEN " [OK]" RESET "");
	else
		printf("=========================================================>" RED " [KO]" RESET "");
	printf("\nFT_STRCPY ");
	if (!strcmp(dest1, dest2))
		printf("=========================================================>" GREEN " [OK]" RESET "");
	else
		printf("=========================================================>" RED " [KO]" RESET "");
	printf("\nFT_STRCMP ");
	if ((ret3 > 0 && ret4 > 0) || (ret3 < 0 && ret4 < 0) || (ret3 == 0 && ret4 == 0))
		printf("=========================================================>" GREEN " [OK]" RESET "");
	else
		printf("=========================================================>" RED " [KO]" RESET "");
	printf("\nFT_WRITE ");
	if (testwrite == 4)
		printf("==========================================================>" GREEN " [OK]" RESET "");
	else
		printf("==========================================================>" RED " [KO]" RESET "");
	printf("\nFT_READ ");
	if (testread == 5)
		printf("===========================================================>" GREEN " [OK]" RESET "");
	else
		printf("===========================================================>" RED " [KO]" RESET "");
	printf("\nFT_STRDUP ");
	if (!strcmp(str1, str2))
		printf("=========================================================>" GREEN " [OK]" RESET "");
	else
		printf("=========================================================>" RED " [KO]" RESET "");
	free(str1);
	free(str2);
	printf("\n");

	return (0);
}