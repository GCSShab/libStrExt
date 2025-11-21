#include "tools.h"

int main()
{
    //tester trim(s)
    char trt1[15]="  Hello boy   ";
    printf("|%s|%d\n",trt1,length(trt1));
    printf("|%s|\n",trim(trt1));
    printf("%c\n",charAt(trt1,5));
    printf("%s\n",substring(trt1,5,9));
    char s1[8]="Bonjour";
    char s2[8]="bonjour";

    printf("%s %s => %b\n",s1,s2,compareTo(s1,s2));
    printf("%s %s => %b\n",s1,s2,compareToIgnoreCase(s1,s2));

    return 0;
}
