#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

int fsize(FILE *f);
int main(int argc, char *argv[])
{
	if(argc < 2)
		printf("ERROR: Need to type tmp name of file which will be encrypted\n");
	if(argc <= 2)
		printf("ERROR: Need to type tmp name of file where the result will be written\n");
	if(argc <= 3)
		printf("ERROR: Need to type tmp key\n");
	if(argc <= 4)
		printf("ERROR: Need to type mode (e - enc, d - dec)\n");
	if(argc == 5)
	{
		FILE *f1,*f2;
		int i,n,j;
		char tmp;
		int k;
		int q = 1;
		switch(argv[4][0])
		{
			case 'd':
				break;
			case 'e':
				break;
			default:
				printf("ERROR: Need to type mode (e - enc, d - dec)\n");
				return 0;
		}	
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
			f2 = fopen(argv[2],"w");
			fclose(f2);
			return 0;
		}
		k=0;
		for(i=0;i<j;i++)
		{
			k += (argv[3][i]-'0') * pow(10,j-i-1);
		}
		f1 = fopen(argv[1],"r");
		n = fsize(f1);
		f2 = fopen(argv[2],"w");
		for(i=0;i<n;i++)
		{
			fscanf(f1,"%c",&tmp);
			j = tmp;
			if(j >= 65 && j <= 90 || j >= 97 && j <= 122)
			{
				if(j >= 65 && j <= 90)
					j -= 65;
				else if(j >= 97 && j <= 122)
					j -= 71;
				if(argv[4][0] == 'e')
				{
					j += k;
					while(j > 51)
						j -= 52;
				}else if(argv[4][0] == 'd')
				{
					j -= k;
					while(j < 0)
						j += 52;
				}
				if(j >= 0 && j <= 25)
					j += 65;
				else if(j >= 26 && j <= 51)
					j += 71;
			}
			tmp = j;
			fprintf(f2,"%c",tmp);
		}
	}
	return 0;
}
int fsize(FILE *f)
{
	int size = 0;
	fseek(f,0,SEEK_END);
	size = ftell(f)-1;
	fseek(f,0,SEEK_SET);
	return size;
}
