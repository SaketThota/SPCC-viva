#include <bits/stdc++.h>
using namespace std ; 
#include <fstream>
#include <sstream>

/*
E -> TG
G -> +TG | #
T -> FS
S -> *FS | #
F -> i | (E)
*/

map<string,set<char>>first; 
map<string,set<char>>follow;

//Data Structure
map<string,vector<string>>prods; 
int main(){
    ifstream in ; 
    in.open("ll1.txt");
    string s ; 
    while(getline(in,s)){
        vector<string>temp;
        stringstream x(s); 
        string word , cur = ""; 
        while (getline(x, word, ' ')) {
            if (word == "|" || word == "->")
                continue;

            if (cur == "") {
                cur = word;
            } else {
                prods[cur].push_back(word);
            }
        }
    }

    first["S"] = {'a'}; 
    first["A"] = {'a'}; 
    follow["S"] = {'$'}; 
    follow["A"] = {'$'};
    first["E"] = {'i','('}; 
    first["G"] = {'+','#'}; 
    first["T"] = {'i' , '('}; 
    first["S"] = {'*' , '#'}; 
    first["F"] = {'i' , '('}; 

    follow["E"] = {'$' , ')'}; 
    follow["G"] = {'$' , ')'}; 
    follow["T"] = {'+','$' , ')'}; 
    follow["S"] = {'+' , '$' , ')'}; 
    follow["F"] = {'*','+','$',')'};

    set<char>terminals; 
    for(auto &it : first){
        for(auto &x : it.second){
            if(x == '#') continue ; 
            terminals.insert(x);
        }
    }
    for(auto &it : follow){
        for(auto &x : it.second){
            terminals.insert(x);
        }
    }

    
    map<string,map<string,int>> table ; 
    int productionNum = 0 ; 
    for(auto &it : prods){
        for(auto &x : it.second){
            productionNum++;
            cout << productionNum << " : " << it.first << " -> " <<  x << endl ; 
            if(x[0] >= 'A' && x[0] <= 'Z'){
                for(auto &ch : first[string(1,x[0])]){
                    table[it.first][string(1,ch)] = productionNum ; 
                }
            }
            else if(x[0] == '#'){
                for(auto &ch : follow[it.first]){
                    table[it.first][string(1,ch)] = productionNum ; 
                }
            }
            else{
                table[it.first][string(1,x[0])] = productionNum ; 
            }
        }
    }

    cout << "LL1 Parser table" << endl; 
    cout << "  " ; 
    for(auto it : terminals) cout << it << " " ; 
    cout << endl ; 
    for(auto it : prods){
        cout << it.first << " " ; 
        for(auto t : terminals){
            cout << table[it.first][string(1,t)] << " " ; 
        }
        cout << endl ; 
    }


    return 0 ;
}
