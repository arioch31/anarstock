#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main (void)
{
	char    *str;
	int     len = 2;
				   
	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	 while (len--)
		 strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in      leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend        et, scelerisque non dolor. Suspendisse augue augue, tempus\n");
	if (str)
	    write(1, str, strlen(str));
	return (0);
	
}
