#include <bits/stdc++.h>
using namespace std ; 
#include <fstream>
#include <sstream>


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

    for(auto &it : prods){
        int recur = 0 ; 
        vector<string>curr;
        for(auto &x : it.second){
            if(string(1,x[0]) == it.first){
                recur = 1 ; 
            }
            curr.push_back(x);
        }
        if(recur == 0) continue ; 
        prods[it.first].clear();

        string np = "";
        np += it.first + "\'" ; 
        prods[np].push_back("#");
        for(auto &x : curr){
            if(string(1,x[0]) == it.first){
                x.erase(x.begin()); 
                x += np; 
                prods[np].push_back(x);
            }
            else{
                x += np; 
                prods[it.first].push_back(x);
            }
        }
    }

    for(auto it : prods){
        cout << it.first << " -> " ; 
        for(auto x : it.second){
            cout << x << " | " ;
        }cout << endl ; 
    }

}