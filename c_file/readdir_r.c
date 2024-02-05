#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	DIR *pDir = NULL;
	struct dirent * pEnt = NULL;
    	struct dirent *entry = (struct dirent *)malloc(sizeof(struct dirent));
    	struct dirent **result = (struct dirent **)malloc(sizeof(struct dirent));
	unsigned int cnt = 0;
	unsigned int ret = 0;	
	if (argc != 2)
	{
		printf("usage: %s dirname\n", argv[0]);
		return -1;
	}
	pDir = opendir(argv[1]);
	if (NULL == pDir)
	{
		perror("opendir");
		return -1;
	}
	ret = readdir_r(pDir , entry , result);
	printf("return	:%d	\n", ret);
	printf("name	:[%s]	\n", entry->d_name);
	printf("name	:[%s]	\n", result[0]->d_name);
	ret = readdir_r(pDir , entry , result);
	printf("return	:%d	\n", ret);
	printf("name	:[%s]	\n", entry->d_name);
	printf("name	:[%s]	\n", result[0]->d_name);
	return 0;
 
}