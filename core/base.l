%{
    #include <stdio.h>
    #include <stdlib.h>
%}
%option outfile="core/Scanner.c" 

%%

\n {fprintf(yyout, "<br>", "");}
[\t] {fprintf(yyout, "&emsp;", "");}
" " {fprintf(yyout, "&nbsp;", "");}

%%

int yywrap(){}
int main(int argc, char **argv) {

    yyin = fopen(argv[1], "r");
    yyout = fopen("core/output.html", "w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;

}