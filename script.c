#include <stdio.h>
#include <string.h>


int main () {

char source[] = "characters strcopy string";
char destination[20];

char createstr[7] = {'j', 'j','y','y','y','t','\0'};

strcpy(destination, source);

printf("source string: %s\n", source);

printf("destination string : %s\n", destination);

printf("display new string: %s\n", createstr);

return 0;

}
