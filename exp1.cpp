#include <bits/stdc++.h>
using namespace std ; 
#include <fstream>
#include <sstream>


set<string> delimiters = {";", ",", "(", ")", "[", "]", "{", "}" , ">>" , "<<"};
set<string> operators = {"+", "-", "*", "/", ">", "<", "=" };
set<string> keywords = {"if", "else", "while", "do", "break", "continue", "int", "float", "double", "return", "char", "case", "sizeof", "long", "short", "typedef", "switch", "unsigned", "void", "static", "struch", "goto", "bool" , "cout" , "cin" , "endl"};

bool isInteger(string s) {
    for(int i = 0 ; i < s.size() ; i++) {
        if(int(s[i])<48 || int(s[i]>57)) {
            if(i==0 && s[i]=='-') continue; 
            else return false; 
        } 
    }
    return true;
}

set<string>sp; 
set<string>op; 
set<string>id; 
set<string>key; 
set<string>con;

int main(){
    ifstream in ; 
    in.open("source.txt"); 
    string s ; 
    while(getline(in , s)) {
        stringstream x(s); 
        vector<string>temp;
        string word ;
        while(getline(x,word,' ')) temp.push_back(word) ; 

        for(auto lex : temp){
            if(delimiters.find(lex) != delimiters.end()){
                sp.insert(lex);
            }
            else if(operators.find(lex) != operators.end()){
                op.insert(lex);
            }
            else if(keywords.find(lex) != keywords.end()){
                key.insert(lex);
            }
            else if(isInteger(lex)){
                con.insert(lex);
            }
            else{
                if(lex[0] != '#' && lex[0] != '<' && lex.back() != ')' && lex != "namespace" && lex != "std" && lex != "using")
                    id.insert(lex);
            }

        }
    }

    for(auto it : op) cout << it << " " ; 
    cout << endl ; 
    for(auto it : id) cout << it << " " ; 
    cout << endl ; 
    for(auto it : key) cout << it << " " ; 
    cout << endl ; 
    for(auto it : con) cout << it << " " ; 
    cout << endl ; 
    for(auto it : sp) cout << it << " " ; 
    cout << endl ; 
    return 0 ; 
}



//Source code
/*
#include <bits/stdc++.h>
using namespace std ; 

int main() {
    int a = 5 ; 
    int b = a + 2 ; 
    int c = a + b ; 
    cout << c << endl ; 
}
*/
