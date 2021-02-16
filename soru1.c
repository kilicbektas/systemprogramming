//Bektaş Kılıç
//B161210380 

#include <stdio.h>
#include <stdlib.h>       
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>


int main(int argc, char **argv)
{
	int data_start, data_size;
	int heap_start, heap_size;
	int stack_start, stack_size;
	
	struct rlimit lim;
	getrlimit(RLIMIT_DATA, &lim);
	data_size = lim.rlim_cur;
	heap_size = lim.rlim_cur;
	getrlimit(RLIMIT_STACK, &lim);
	stack_size = lim.rlim_cur;
	
	
	FILE* fd = fopen("/proc/self/maps", "r");
	char line[256];
	char part[64];
	
	while (!feof(fd)) {
		fgets(line, 256, fd);
		
		if (strstr(line, "soru1") != NULL && strstr(line, "rw-p") != NULL) {
			strncpy(part, line, strchr(line, '-') - line);
			data_start = strtoul(part, NULL, 16);
		}
			
		if (strstr(line, "heap") != NULL) {
			strncpy(part, line, strchr(line, '-') - line);
			heap_start = strtoul(part, NULL, 16);
		}
		
		if (strstr(line, "stack") != NULL) {
			strncpy(part, strchr(line, '-') + 1, strchr(line, ' ') - strchr(line, '-') + 1);
			stack_start = strtoul(part, NULL, 16);
		}
	}
	
	printf("Data bolumu  : baslangic: 0x%lx, \tboyut: %u Byte\n", data_start, data_size);
	printf("Yigit bolumu : baslangic: 0x%lx, \tboyut: %u Byte\n", heap_start, heap_size);
	printf("Yigin bolumu : baslangic: 0x%lx, \tboyut: %u Byte\n", stack_start, stack_size);

	
}
