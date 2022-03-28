%{
    #include <stdio.h>
    #include <stdlib.h>
%}
%option outfile="core/Scanner.c" 

%%

"if"|"or"|"while"|"return"|"for"|"in"|"class"|"def"|"try"|"else"|"raise"|"from"|"import"|"except"|"as" {fprintf(yyout, "<span class='regex-0'>%s</span>", yytext);}
"("|")"|"{"|"}"|"["|"]" {fprintf(yyout, "<span class='regex-1'>%s</span>", yytext);}
"true"|"false"|"True"|"False"|"null"|"void"|"string"|"int"|"None"|"public" {fprintf(yyout, "<span class='regex-2'>%s</span>", yytext);}
"//".*|"#".* {fprintf(yyout, "<span class='regex-3'>%s</span>", yytext);}
[0-9]+ {fprintf(yyout, "<span class='regex-4'>%s</span>", yytext);}
[0-9]+"."[0-9]+ {fprintf(yyout, "<span class='regex-5'>%s</span>", yytext);}
[A-z]([A-z]|[0-9]|"_")* {fprintf(yyout, "<span class='regex-6'>%s</span>", yytext);}
"<="|">="|"=="|"!="|"<"|">" {fprintf(yyout, "<span class='regex-7'>%s</span>", yytext);}
"\."|","|";"|":" {fprintf(yyout, "<span class='regex-8'>%s</span>", yytext);}
"'"."'" {fprintf(yyout, "<span class='regex-9'>%s</span>", yytext);}
"!"|"%"|"^"|"+"|"="|"-"|"*" {fprintf(yyout, "<span class='regex-10'>%s</span>", yytext);}
"\"".*"\"" {fprintf(yyout, "<span class='regex-11'>%s</span>", yytext);}
\n {fprintf(yyout, "<br>", "");}
[\t] {fprintf(yyout, "&emsp;", "");}
" " {fprintf(yyout, "&nbsp;", "");}

%%

int yywrap(){}
int main(int argc, char **argv) {

    yyin = fopen("data_entry.txt", "r");
    yyout = fopen("core/output.html", "w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;

}
