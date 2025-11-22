#include "tools.h"

int main()
{

    char *nowDT=calloc(20,sizeof(char));
    now(nowDT);
    printf("Say now is : %s\n",nowDT);

    char trt1[23]="  Hello boy boy boy   ";

    printf("test length |%s| size=%d\n",trt1,length(trt1));

    printf("test trim |%s| => |%s|\n",trt1,trim(trt1));

    printf("test charAt(5) => |%s| => |%c|\n",trt1,charAt(trt1,5));

    printf("test substring(5,9) |%s| => |%s|\n",trt1,substring(trt1,5,9));

    printf("test indexOf(boy) => %d\n",indexOf(trt1,"boy"));

    printf("test lastIndexOf(boy) => %d\n",lastIndexOf(trt1,"boy"));

    replaceAll(trt1,"boy","girl");
    printf("test replaceAll(boy, girl) => |%s|\n",trt1);

    char trt2[23]="  Hello boy boy boy   ";
    replaceFirst(trt2,"boy","girl");
    printf("test replaceFirst(boy, girl) => |%s|\n",trt2);

    char s1[8]="BONJOUR";
    char s2[8]="bonjour";

    printf("test compareTo => %s vs %s => %s\n",s1,s2,compareTo(s1,s2) ? "true" : "false");
    printf("test compareToIgnoreCase %s vs %s => %s\n",s1,s2,compareToIgnoreCase(s1,s2) ? "true" : "false");

    toUpperCase(s2);
    printf("test toUpperCase() bonjour => %s\n",s2);

    toLowerCase(s1);
    printf("test toLowerCase() BONJOUR => %s\n",s1);

    printf ("test repeat(C,12) => %s\n",repeat('C',12));

    char s3[17]="hello the world!";
    printf("Test capitalize(%s) => ",s3);
    capitalize(s3);
    printf("%s\n",s3);


    char **tab=splitWithDelimiters("12;Col1;Col2;Destination;Col4",';');
    printf("test splitWithDelimiters(12;Col1;Col2;Destination;Col4,;)\n");
    for (int n=0;n<5;n++) {printf("\tCol[%d] => %s\n",n,tab[n]);}

    char *ligne="18;Col#;Col$;Col%;Col?";
    char **col=split(ligne,';');
    printf("test split(18;Col#;Col$;Col-;Col?,;)\n");
    for (int n=0;n<5;n++) {printf("\tCol[%d] => %s\n",n,col[n]);}

    strip(trt1);
    printf("test strip(trt1) => |%s|\n",trt1);

    char *valleft=calloc(9,sizeof(char));
    pad_left_zeros("1234",valleft,8);
    printf("test pad_left_zeros(1234,8) %s\n",valleft);

    char *valright=calloc(9,sizeof(char));
    pad_right_zeros("1234",valright,8);
    printf("test pad_right_zeros(1234,8) %s\n",valright);

    char *ew="myfile.csv";
    char *sw="PROG_1234.cfg";

    printf("test endWith(csv) %s => %s\n",ew,endWith(ew,"csv") ? "true" : "false");
    printf("test startWith(PROG) %s => %s\n",sw,startWith(sw,"PROG") ? "true" : "false");

    printf("test isEmpty '' => %s\n",isEmpty("") ? "true" : "false");
    printf("test isBlank '    ' => %s\n",isBlank("     ") ? "true" : "false");

    char A[3]="A";
    char B[2]="B";
    concat(A,B);
    printf("test concat(A,B) A + B => %s\n",A);

    printf("test contains(Hello the world, world) => %s\n",contains("Hello the world","world") ? "true" : "false");

    char *input="l'admin et l'équipe sont ok";
    char *output=calloc(200,sizeof(char));
    double_quotes(input,output);
    printf("test double_quotes %s => %s\n",input,output);

    char *datin="22/11/2025";
    char *datout=calloc(9,sizeof(char));
    convert_date_format(datin,datout);
    printf("test convert_date_format %s => %s\n",datin,datout);

    return 0;
}
