#include <bits/stdc++.h>
using namespace std ; 
#include <fstream>
#include <sstream>

/*
A -> abB | abC | bD | E
*/


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
        int factor = 1 ; 
        string curr = it.first ; 
        while(factor){
            char left = ' ' ; 
            map<char,int>freq; 
            for(auto &x : prods[curr]) freq[x[0]]++ ; 
            for(auto p : freq){
                if(p.second > 1){left = p.first ; break;}
            }
            if(left == ' ') break;

            string np = curr + "\'" ; 
            vector<string>newProds; 
            int done = 0 ; 
            for(auto &x : prods[curr]){
                if(x[0] == left){
                    if(done == 0){
                        string temp = string(1,x[0]); 
                        temp += np ; 
                        newProds.push_back(temp);
                    }
                    x.erase(x.begin());
                    prods[np].push_back(x);
                    done = 1 ;
                }
                else{
                    newProds.push_back(x);
                }
            }
            prods[curr].clear(); 
            prods[curr]  = newProds ;  
            curr = np ;

        }
        
    }

    for(auto it : prods){
        cout << it.first << " -> " ; 
        for(auto x : it.second){
            cout << x << " | " ;
        }cout << endl ; 
    }

    return 0 ;
}
