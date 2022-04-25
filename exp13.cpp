%{
	int lines = 0;
	int words = 0;
	int chars = 0;
%}

%%
[\n] {lines++;}
.  chars++;
([a-zA-Z0-9])* {words++;}
%%

int yywrap(){}
int main()
{
	printf("Enter the input : ");
	yylex();
	printf("Lines: %d\n", lines);
	printf("Words: %d\n", words);
	printf("Characters: %d\n", chars);
	return 0;
}

/*
IP :
Enter each character in the new line :)
*/
