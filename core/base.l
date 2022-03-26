%{
    #include <stdio.h>
    #include <stdlib.h>
%}
%option outfile="Scanner.c" 

%%
    <Regular_expression>
    {this->regex}   {this->instruccion}
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