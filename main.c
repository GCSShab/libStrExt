#include "tools.h"

int main()
{
    //tester trim(s)
    char trt1[23]="  Hello boy boy boy   ";
    printf("|%s|%d\n",trt1,length(trt1));
    printf("|%s|\n",trim(trt1));
    printf("%c\n",charAt(trt1,5));
    printf("%s\n",substring(trt1,5,9));
    printf("position %d\n",indexOf(trt1,"boy"));
    printf("position %d\n",lastIndexOf(trt1,"boy"));

    replaceAll(trt1,"boy","girl");
    printf("%s\n",trt1);


    char s1[8]="Bonjour";
    char s2[8]="bonjour";
    printf("%s %s => %b\n",s1,s2,compareTo(s1,s2));
    printf("%s %s => %b\n",s1,s2,compareToIgnoreCase(s1,s2));

    printf ("%s\n",repeat('C',12));

    char **tab=splitWithDelimiters("A;B;C;Destination;E",';');
    printf("apres split %s\n",tab[3]);

    strip(trt1);
    printf("strip |%s|\n",trt1);

    return 0;
}
