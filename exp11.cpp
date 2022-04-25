%{
	int vow_count = 0;
	int con_count = 0;
%}

%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {con_count++;}
%%

int yywrap(){}
int main()
{
	printf("Enter the string of vowels and consonants:");
	yylex();
	printf("Number of vowels are %d\n", vow_count);
	printf("Number of consonants are: %d\n", con_count);
	return 0; 
}
