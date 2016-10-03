#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
main(int argc, char **argv){
	int count = 0;
	int i;
	DIR * path;
	struct dirent *entry;
	char pathstr[80];
	struct stat s;
	int err;
	//char send1[] = "send1";
	//char send2[] = "send2";
	char * send[8] = {"/send1","/send2","/send3","/send4","/send5","/send6","/send7","/send8"};
	
	if(argc == 2){
		for(i=0;i<8;i++){
			strcpy(pathstr,argv[1]);
			strcat(pathstr,send[i]);
//		printf("%s\n",pathstr);
//		path = opendir(argv[1]);
			err = stat(pathstr,&s);
			if(!(-1 == err) && S_ISDIR(s.st_mode)){
				path = opendir(pathstr);
		        	while((entry = readdir(path)) != NULL){
			                if(entry->d_type== DT_REG){
        	                		count++;
                			}
        			}
				closedir(path);
			}
		}
		printf("%d",count);
	}
	else{
		printf("Mailcount v1.3\n");
		printf("=============================\n");
		printf("Count total number of emails for 104 oms server\n");
		printf("=============================\n");
		printf("Get start: mailcount {real path}\n");
		printf("ex: mailcount /opt/sendmail/oms07\n");
		printf("=============================\n");
		printf("Auther:SE team 20160930\n");
		printf("mail:ese01@104.com.tw\n");
	}
	return 0;
}
