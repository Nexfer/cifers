#include <stdio.h>
#include <string.h>
#include <math.h>

int fsize(FILE *f);
int DOStoANSI(int code);
int ANSItoDOS(int code);
int main(int argc,char *argv[])
{
	if(argc < 2)
		printf("ERROR: Need to type a name of file which will be encrypted\n");
	if(argc <= 2)
		printf("ERROR: Need to type a name of file where the result will be written\n");
	if(argc <= 3)
		printf("ERROR: Need to type a key for cifer\n");
	if(argc <= 4)
		printf("ERROR: Need to type mode (dec or enc)\n");
	if(argc == 5)
	{
		FILE *f1,*f2;
		int i,n,j;
		char tmp;
		int k;
		int q = 1;
			j = strlen(argv[3]);
			for(i=0;i<j;i++)
			{
				k=argv[3][i]-'0';
				if(k < 0 || k > 9)
				{
					q = 0;
					break;
				}
			}
			if(q == 0)
			{
				printf("ERROR: Need to type a number\n");
				if ((f2 = fopen("out.txt","w")) != NULL)
				{
					fprintf(f2,"");
				fclose(f2);
				}
				else printf("File error!");
				return 0;
			}
			k=0;
			for(i=0;i<j;i++)
			{
				k = k + (argv[3][i]-'0') * pow(10,j-i-1);
			}
			if ((f1 = fopen(argv[1],"r")) != NULL)
			{
				if ((f2 = fopen(argv[2],"w")) != NULL)
				{
					n = fsize(f1);
					fseek(f1,0,SEEK_SET);
					if(argv[4][0] == 'd' && argv[4][1] == 'e' && argv[4][2] == 'c')
					{
						for(i=0;i<n;i++)
						{
							fscanf(f1,"%c",&tmp);
							j = tmp;
							if(tmp < 0)
								j = tmp + 256;
							j = ANSItoDOS(j);
							if(j >= 65 && j <= 90 || j >= 97 && j <= 122 || j >= 128 && j <= 175 || j >= 224 && j <= 239)
								j -= k;
							j = DOStoANSI(j);
							fprintf(f2,"%c",j);
						}
					}
					else if(argv[4][0] == 'e' && argv[4][1] == 'n' && argv[4][2] == 'c')
					{
						for(i=0;i<n;i++)
						{
							fscanf(f1,"%c",&tmp);
							j = tmp;
							if(j >= 65 && j <= 90 || j >= 97 && j <= 122 || j >= 128 && j <= 175 || j >= 224 && j <= 239)
								j += k;
							j = DOStoANSI(j);
							fprintf(f2,"%c",j);
						}
					}
					else printf("ERROR: Need to type mode (dec or enc)\n");
				fclose(f2);
				}
				else printf("File error!");
			fclose(f1);
			}else printf("File error!");
	}
	return 0;
}

int fsize(FILE *f)
{
	int n = 0;
	fseek(f,0,SEEK_END);
	n = ftell(f);
	return n;
}
int DOStoANSI(int code)
{
	if(code >= 128 && code <= 175)
		code = code + 64;
	else if(code >= 224 && code <= 239)
		code = code + 16;
	return code;
}
int ANSItoDOS(int code)
{
	if(code >= 192 && code <= 239)
		code -=  64;
	else if(code >= 240 && code <= 255)
		code -=  16;
	return code;
}
