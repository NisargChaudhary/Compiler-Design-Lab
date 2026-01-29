%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

int yyerror(const char *errormsg);
%}

%%

[ \t]+               ;   /* ignore spaces and tabs */

("hi"|"oi")[ \t]*\n?     { return HI; }

("tchau"|"bye")[ \t]*\n? { return BYE; }

.   { yyerror("Unknown char"); }

%%

int main(void)
{
    yyparse();
    return 0;
}

int yywrap(void)
{
    return 1;
}

int yyerror(const char *errormsg)
{
    fprintf(stderr, "%s\n", errormsg);
    exit(1);
}
