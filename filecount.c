#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main(int argc, char **argv){
	int count = 0;
	int i;
	DIR * path;
	struct dirent *entry;
	char pathstr[80];
	
	//char send1[] = "send1";
	//char send2[] = "send2";
	
	if(argc == 2){
		strcpy(pathstr,argv[1]);
//		printf("%s\n",pathstr);
//		path = opendir(argv[1]);
		path = opendir(pathstr);
	        while((entry = readdir(path)) != NULL){
			if(entry->d_type== DT_REG){
        	               	count++;
                	}
        	}
		printf("%d",count);
		closedir(path);
	}
	else{
		printf("Filecount v1.3\n");
		printf("=============================\n");
		printf("Count total number of files\n");
		printf("=============================\n");
		printf("Get start: filecount {real path}\n");
		printf("ex: filecount /opt/sendmail/oms07/send1\n");
		printf("=============================\n");
		printf("Auther:SE team 20160930\n");
		printf("mail:ese01@104.com.tw\n");
	}
	return 0;
}
