%{
    #include <stdio.h>
    #include <stdlib.h>
%}
%option outfile="core/Scanner.c" 

%%

\n {fprintf(yyout, "<br>", "");}
%%

int yywrap(){}
int main(int argc, char **argv) {

    yyin = fopen("data_entry.txt", "r");
    yyout = fopen("index.html", "w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;

}