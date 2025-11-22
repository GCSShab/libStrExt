#include "tools.h"

#define TEST_ASSERT(expr) do { \
    if (expr) { \
        printf("[OK]   %s:%d: %s\n\n", __FILE__, __LINE__, #expr); \
    } else { \
        printf("[FAIL] %s:%d: %s\n\n", __FILE__, __LINE__, #expr); \
    } \
} while(0)

int main()
{

    char *nowDT=calloc(20,sizeof(char));
    now(nowDT);
    printf("Say now is : %s\n",nowDT);
    printf("%s\n\n",repeat('=',32));

    char trt1[23]="  Hello boy boy boy   ";

    printf("test length |%s| size=%d\n",trt1,length(trt1));
    TEST_ASSERT(length(trt1) == 22);

    printf("test trim |%s| => |%s|\n",trt1,trim(trt1));
    TEST_ASSERT(strcmp(trim(trt1),"Hello boy boy boy")==0);

    printf("test charAt(5) => |%s| => |%c|\n",trt1,charAt(trt1,5));
    TEST_ASSERT(charAt(trt1,5)=='l');


    printf("test substring(5,9) |%s| => |%s|\n",trt1,substring(trt1,5,9));
    TEST_ASSERT(strcmp(substring(trt1,5,9),"lo bo")==0);

    printf("test indexOf(boy) => %d\n",indexOf(trt1,"boy"));
    TEST_ASSERT(indexOf(trt1,"boy")==8);

    printf("test lastIndexOf(boy) => %d\n",lastIndexOf(trt1,"boy"));
    TEST_ASSERT(lastIndexOf(trt1,"boy")==16);

    replaceAll(trt1,"boy","girl");
    printf("test replaceAll(boy, girl) => |%s|\n",trt1);
    TEST_ASSERT(strcmp(trt1,"  Hello girl girl girl")==0);

    char trt2[23]="  Hello boy boy boy   ";
    replaceFirst(trt2,"boy","girl");
    printf("test replaceFirst(boy, girl) => |%s|\n",trt2);
    TEST_ASSERT(strcmp(trt2,"  Hello girl boy boy   ")==0);

    char s1[8]="BONJOUR";
    char s2[8]="bonjour";
    printf("test compareTo => %s vs %s => %s\n",s1,s2,compareTo(s1,s2) ? "true" : "false");
    TEST_ASSERT(compareTo(s1,s2)==0);
    printf("test compareToIgnoreCase %s vs %s => %s\n",s1,s2,compareToIgnoreCase(s1,s2) ? "true" : "false");
    TEST_ASSERT(compareToIgnoreCase(s1,s2)==1);

    toUpperCase(s2);
    printf("test toUpperCase() bonjour => %s\n",s2);
    TEST_ASSERT(strcmp(s2,"BONJOUR")==0);

    toLowerCase(s1);
    printf("test toLowerCase() BONJOUR => %s\n",s1);
    TEST_ASSERT(strcmp(s1,"bonjour")==0);

    printf ("test repeat(C,12) => %s\n",repeat('C',12));
    TEST_ASSERT(strcmp(repeat('C',12),"CCCCCCCCCCCC")==0);

    char s3[17]="hello the world!";
    printf("Test capitalize(%s) => ",s3);
    capitalize(s3);
    printf("%s\n",s3);
    TEST_ASSERT(strcmp(s3,"Hello The World!")==0);

    char **tab=splitWithDelimiters("12;Col1;Col2;Destination;Col4",';');
    printf("test splitWithDelimiters(12;Col1;Col2;Destination;Col4,;)\n");
    for (int n=0;n<5;n++) {printf("\tCol[%d] => %s\n",n,tab[n]);}
    TEST_ASSERT(strcmp(tab[4],"Col4")==0);

    char *ligne="18;Col#;Col$;Col%;Col?";
    char **col=split(ligne,';');
    printf("test split(18;Col#;Col$;Col-;Col?,;)\n");
    for (int n=0;n<5;n++) {printf("\tCol[%d] => %s\n",n,col[n]);}
    TEST_ASSERT(strcmp(col[1],"Col#")==0);

    strip(trt1);
    printf("test strip(trt1) => |%s|\n",trt1);
    TEST_ASSERT(strcmp(trt1,"Hellogirlgirlgirl")==0);

    char *valleft=calloc(9,sizeof(char));
    pad_left_zeros("1234",valleft,8);
    printf("test pad_left_zeros(1234,8) %s\n",valleft);
    TEST_ASSERT(strcmp(valleft,"00001234")==0);

    char *valright=calloc(9,sizeof(char));
    pad_right_zeros("1234",valright,8);
    printf("test pad_right_zeros(1234,8) %s\n",valright);
    TEST_ASSERT(strcmp(valright,"12340000")==0);

    char *ew="myfile.csv";
    char *sw="PROG_1234.cfg";

    printf("test endWith(csv) %s => %s\n",ew,endWith(ew,"csv") ? "true" : "false");
    TEST_ASSERT(endWith(ew,"csv")==1);

    printf("test startWith(PROG) %s => %s\n",sw,startWith(sw,"PROG") ? "true" : "false");
    TEST_ASSERT(startWith(sw,"PROG")==1);

    printf("test isEmpty '' => %s\n",isEmpty("") ? "true" : "false");
    TEST_ASSERT(isEmpty("")==1);

    printf("test isBlank '    ' => %s\n",isBlank("     ") ? "true" : "false");
    TEST_ASSERT(isBlank("     ")==1);

    char A[3]="A";
    char B[2]="B";
    concat(A,B);
    printf("test concat(A,B) A + B => %s\n",A);
    TEST_ASSERT(strcmp(A,"AB")==0);

    printf("test contains(Hello the world, world) => %s\n",contains("Hello the world","world") ? "true" : "false");
    TEST_ASSERT(contains("Hello the world","world")==1);

    char *input="l'admin et l'équipe sont ok";
    char *output=calloc(200,sizeof(char));
    double_quotes(input,output);
    printf("test double_quotes %s => %s\n",input,output);
    TEST_ASSERT(strcmp(output,"l''admin et l''équipe sont ok")==0);

    char *datin="22/11/2025";
    char *datout=calloc(9,sizeof(char));
    convert_date_format(datin,datout);
    printf("test convert_date_format %s => %s\n",datin,datout);
    TEST_ASSERT(strcmp(datout,"20251122")==0);

    return 0;
}
