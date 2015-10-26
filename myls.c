#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>


int main(int argc,char **argv){

	char buf[256];
	getcwd(buf,sizeof(buf));

	int ch;

	int lflag=0;

	while((ch=getopt(argc,argv,"l"))!=-1){
		switch(ch){
			case 'l':
				lflag=1;
				break;
			default:
				printf("default :%s\n",optarg);
		}
	}

	printf("=========================================\n");
	printf("===    1352958 Jinmin's LS Tool       ===\n");
	printf("=========================================\n");

	
	DIR*dirptr=NULL;
	struct dirent*entry;

	if((dirptr=opendir(buf))==NULL){
		fprintf(stderr,"Open Directory Error!\n");
		return 1;
	}


	while(entry=readdir(dirptr)){

		

		struct stat st;
		stat(entry->d_name,&st);

		if(!lflag){
			printf(" %s\n",entry->d_name);
			continue;
		}

		if(S_ISREG(st.st_mode)){
			printf("-");
		}else if(S_ISDIR(st.st_mode)){
			printf("d");
		}else if(S_ISLNK(st.st_mode)){
			printf("l");
		}else if(S_ISCHR(st.st_mode)){
			printf("c");
		}else{
			printf("?");
		}


		/// Priority
		if(st.st_mode&S_IRUSR){
			printf("r");
		}else{ printf("-"); }

		if(st.st_mode&S_IWUSR){
			printf("w");
		}else{ printf("-"); }
		
		if(st.st_mode&S_IXUSR){
			printf("x");
		}else{ printf("-"); }
		
		if(st.st_mode&S_IRGRP){
			printf("r");
		}else{ printf("-"); }
		
		if(st.st_mode&S_IWGRP){
			printf("w");
		}else{ printf("-"); }
		
		if(st.st_mode&S_IXGRP){
			printf("x");
		}else{ printf("-"); }
		
		if(st.st_mode&S_IROTH){
			printf("r");
		}else{ printf("-"); }

		if(st.st_mode&S_IWOTH){
			printf("w");
		}else{ printf("-"); }
		
		if(st.st_mode&S_IXOTH){
			printf("x");
		}else{ printf("-"); }
		
		printf(" %d",st.st_nlink);

		printf(" %s",getpwuid(st.st_uid)->pw_name);

		printf(" %s",getgrgid(st.st_gid)->gr_name);

		printf(" %10ld",st.st_size);

		struct tm*ptime;

		ptime=localtime(&(st.st_mtime));

		printf("\t%d.%d.%d %d:%d",ptime->tm_year+1900,ptime->tm_mon,ptime->tm_mday,ptime->tm_hour,ptime->tm_min);

		
		
		printf(" %s\n",entry->d_name);

	}

	closedir(dirptr);
	
	return 0;
}


