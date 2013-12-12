#include <stdio.h>
#include <malloc.h>
#include <string.h>

int fsize(FILE *f);
int innum(char a);
int inchar(char a);
int vigenere(char *arg[]);
int vigenere(char *arg[])
{
		FILE *f1,*f2,*f3;
		int n,m,i,j;
		char *temp;
		char *smb;
		switch(arg[4][0])
		{
			case 'd':
				break;
			case 'e':
				break;
			default:
				printf("ERROR: Need to type mode (e - enc, d - dec)\n");
				return 0;
		}	
		f1 = fopen(arg[1],"r");
		n = fsize(f1);
		f3 = fopen(arg[3],"r");
		m = fsize(f3);
		if(m > n)
		{
			fclose(f1);
			fclose(f3);
			printf("ERROR: The length of key wouldn't be longer than a source text\n");
			return 0;
		}
		temp = (char*)malloc(n*sizeof(char));
		for(i=0;i<m;i++)
			fscanf(f3,"%c",&temp[i]);
		for(i=m,j=0;i<n;i++,j++)
			temp[i] = temp[j];
		smb = (char*)malloc(n*sizeof(char));
		for(i=0;i<n;i++)
			fscanf(f1,"%c",&smb[i]);
		for(i=0;i<n;i++)
		{
			if(smb[i] >= 65 && smb[i] <= 90 || smb[i] >= 97 && smb[i] <= 122)
			{
				smb[i] = innum(smb[i]);
				if(temp[i] >= 65 && temp[i] <= 90 || temp[i] >= 97 && temp[i] <= 122)
				{
					temp[i] = innum(temp[i]);
					if(arg[4][0] == 'e')
					{
						smb[i] = smb[i] + temp[i];
						if(smb[i] > 51)
							smb[i] -= 52;
					}
					else if(arg[4][0] == 'd')
					{
						smb[i] = smb[i] - temp[i];
						if(smb[i] < 0)
							smb[i] += 52;
					} 
					
				}
				smb[i] = inchar(smb[i]);
			}
		}
		f2 = fopen(arg[2],"w");
		smb[n] = '\n';
		for(i=0;i<=n;i++)
			fprintf(f2,"%c",smb[i]);
		free(temp);
		free(smb);
		fclose(f3);
		fclose(f2);
		fclose(f1);
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
int innum(char a)
{
	if(a >= 65 && a <= 90)
		a -= 65;
	else if(a >= 97 && a <= 122)
		a -= 71;
	return a;
}
int inchar(char a)
{
	if(a >= 0 && a <= 25)
		a += 65;
	else if(a >= 26 && a <= 51)
		a += 71;
	return a;
}
