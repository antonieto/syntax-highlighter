%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%option outfile="Scanner.c"

DIGITO [0-9]
LETRA [A-z]

ENTERO {DIGITO}+
REAL {DIGITO}+"."{DIGITO}+

IDENTIFICADOR {LETRA}({LETRA}|{DIGITO}|"_")*

DELIMITADOR [\t\r\f" "]


%%
{ENTERO}        {fprintf(yyout, "<span class=\"entero\">%s</span>", yytext);}
{REAL}          {fprintf(yyout, "<span class='real'>%s</span>", yytext);}
{IDENTIFICADOR} {fprintf(yyout, "<span class='identificador'>%s</span>", yytext);}

{DELIMITADOR} {fprintf(yyout, "%s", yytext);} 
.              {fprintf(yyout, "ERROR LEXICO");}  

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