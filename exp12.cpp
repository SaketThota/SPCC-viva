%{
	int n = 0;
	int w = 0;
%}

%%
[0123456789] {n++;}
[a-zA-Z] {w++;}
%%

int yywrap(){}
int main()
{
	printf("Enter it");
	yylex();
	if (n > 0){
	printf("It is a number");	
	}
	
	if (w>0){
	printf("It is a word");	
	}
	
	return 0;
}

/*
Dont forget to enter ctrl+d
*/
