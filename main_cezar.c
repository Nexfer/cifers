#include <stdio.h>
int main(int argc, char *argv[])
{
        if(argc < 2)
                printf("ERROR: Need to type a name of file which will be encrypted\n");
        if(argc <= 2)
                printf("ERROR: Need to type a name of file where the result will be written\n");
        if(argc <= 3)
                printf("ERROR: Need to type a key\n");
        if(argc <= 4)
                printf("ERROR: Need to type mode (e - enc, d - dec)\n");
        if(argc == 5)
        {
		cezar(argv);
	}
        return 0;
}
