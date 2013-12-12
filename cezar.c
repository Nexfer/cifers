#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
int fsize(FILE *f);
int cezar(char *arg[]);
int cezar(char *arg[])
{
                FILE *f1,*f2;
                int i,n,j;
                char tmp;
                int k;
                int q = 1;
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
                j = strlen(arg[3]);
                for(i=0;i<j;i++)
                {
                        k=arg[3][i]-'0';
                        if(k < 0 || k > 9)
                        {
                                q = 0;
                                break;
                        }
                }
                if(q == 0)
                {
                        printf("ERROR: Need to type a number\n");
                        f2 = fopen(arg[2],"w");
                        fclose(f2);
                        return 0;
                }
                k=0;
                for(i=0;i<j;i++)
                {
                        k += (arg[3][i]-'0') * pow(10,j-i-1);
                }
                f1 = fopen(arg[1],"r");
                n = fsize(f1);
                f2 = fopen(arg[2],"w");
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
                                if(arg[4][0] == 'e')
                                {
                                        j += k;
                                        while(j > 51)
                                                j -= 52;
                                }else if(arg[4][0] == 'd')
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
