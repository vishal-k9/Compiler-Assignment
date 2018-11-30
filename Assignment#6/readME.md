# Assignment 6
Using YACC (or Bison), implement a parser of your choice to handle for() loop and if-then-else construct. Integrate it with lex (or flex). Implementation should have all syntax directed translations and handle ambiguity, if any.

# apt-get install bison flex

# Running if-else-then parser
students@cselab-desktop:~$ lex ift.lex
students@cselab-desktop:~$ yacc ift.y
students@cselab-desktop:~$ gcc y.tab.c -ll -ly
students@cselab-desktop:~$ ./a.out
Enter the exp: if(a==1)  then b=1; else b=2;
Input accepted.


# Running for-loop parser
nn@linuxmint ~ $ lex for.l
nn@linuxmint ~ $ yacc for.y
conflicts: 25 shift/reduce, 4 reduce/reduce
nn@linuxmint ~ $ gcc y.tab.c -ll -ly
nn@linuxmint ~ $ ./a.out
Enter the expression:
for(i=0;i< n;i++)
i=i+1;
Input accepted



