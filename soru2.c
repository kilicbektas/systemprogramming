//Bektaş Kılıç
//B161210380 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char **argv)
{
	if (argc != 3 || (strcmp(argv[1], "-r") != 0 && strcmp(argv[1], "-s") != 0)) {
		printf("./soru2 [-s/-r] dosya\n");
		return -1;
	}
	
	FILE* fd = fopen(argv[2], "r");
	char line[1024];
	char part[64];
	int line_number = 0;
	int block_comment = 0;
	
	while (!feof(fd)) {
		fgets(line, 1024, fd);
		line_number++;
		char* char_index = line;
		
		if (!block_comment) {
			if (strstr(line, "/*") != NULL) {
				block_comment = 1;
			}
		}
		
		else if (strstr(line, "*/") != NULL) {
			block_comment = 0;
		}
		
		if (block_comment) {
			continue;
		}
			
		if (strstr(line, "//") != NULL) {
			strncpy(strstr(line, "//"), "", 1);
		}
		
		if (strstr(line, "strcpy") != NULL) {
			char* str = strstr(line, "strcpy");
			
			if (!isalnum(*(str - 1)) && !isalnum(*(str + 6))) {
				printf("Satir \t%d: strcpy() kullanilmis", line_number);
				
				if (strcmp(argv[1], "-r") == 0) {
					printf(", yerine strncpy() kullanabilirsiniz.\n");
				}
				
				else {
					printf(".\n");
				}
			}
		}
		
		if (strstr(line, "strcat") != NULL) {
			char* str = strstr(line, "strcat");
			
			if (!isalnum(*(str - 1)) && !isalnum(*(str + 6))) {
				printf("Satir \t%d: strcat() kullanilmis", line_number);
				
				if (strcmp(argv[1], "-r") == 0) {
					printf(", yerine strncat() kullanabilirsiniz.\n");
				}
				
				else {
					printf(".\n");
				}
			}
		}
		
		if (strstr(line, "sprintf") != NULL) {
			char* str = strstr(line, "sprintf");
			
			if (!isalnum(*(str - 1)) && !isalnum(*(str + 7))) {
				printf("Satir \t%d: sprintf() kullanilmis", line_number);
				
				if (strcmp(argv[1], "-r") == 0) {
					printf(", yerine snprintf() kullanabilirsiniz.\n");
				}
				
				else {
					printf(".\n");
				}
			}
		}
		
		if (strstr(line, "gets") != NULL) {
			char* str = strstr(line, "gets");
			
			if (!isalnum(*(str - 1)) && !isalnum(*(str + 4))) {
				printf("Satir \t%d: gets() kullanilmis", line_number);
				
				if (strcmp(argv[1], "-r") == 0) {
					printf(", yerine fgets() kullanabilirsiniz.\n");
				}
				
				else {
					printf(".\n");
				}
			}
		}
		
		if (strstr(line, "getpw") != NULL) {
			char* str = strstr(line, "getpw");
			
			if (!isalnum(*(str - 1)) && !isalnum(*(str + 5))) {
				printf("Satir \t%d: getpw() kullanilmis", line_number);
				
				if (strcmp(argv[1], "-r") == 0) {
					printf(", yerine getpwuid() kullanabilirsiniz.\n");
				}
				
				else {
					printf(".\n");
				}
			}
		}
	}

	
}
