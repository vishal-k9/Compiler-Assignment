/*** Definition section ***/



%{
/* C code to be copied verbatim */
#include <stdio.h>
%}



/* This tells flex to read only one input file */
%option noyywrap



%%
    /*** Rules section ***/

    /* [0-9]+ matches a string of one or more digits */

auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while   {
										printf("keyword (%s)\n",yytext);
									}    


[0-9]+("."[0-9]*)?        {printf("Real Number (%s)\n",yytext);}        
[a-z]([a-z]|[0-9])*    {printf("Identifier (%s)\n",yytext);}

.|\n|"//".*    {   /* Ignore all other characters. */   }

%%




/*** C Code section ***/

int main(void)
{
    /* Call the lexer, then quit. */
    yylex();
    return 0;
}