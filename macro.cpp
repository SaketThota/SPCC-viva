#include<bits/stdc++.h>
using namespace std ; 
#include <fstream>
#include <sstream>

//Data structures used
map<string,pair<int,int>>mnt; 
vector<string>mdt; 
map<string,vector<string>>ala; 
map<string,vector<string>>actual; 

void pass2(){
    ifstream in ; 
    in.open("input.txt"); 
    string s ;
    int macroFlag = 0 ; 
    int startFlag = 0 ;
    int mdtp = 0 ;
    string curr = "" ; 
    while(getline(in,s)){
        if(s == "MACRO"){ continue ; }
        if(s == "MEND"){ macroFlag = 0 ; continue ; }
        if(macroFlag == 1) continue ; 
        if(s == "START"){ startFlag = 1 ; continue ;}

        stringstream x(s);
        string word ; 
        vector<string>temp;
        while(getline(x,word,' ')){
            temp.push_back(word);
        }
        if(startFlag == 1){
            if(mnt.find(temp[0]) == mnt.end()) { cout << s << endl ; continue ; }
            for(int i =  mnt[temp[0]].first ; i < mnt[temp[0]].second ; i++){
                stringstream X(mdt[i]); 
                string Word ; 
                vector<string>line ; 
                while(getline(X,Word,' ')) line.push_back(Word); 
                vector<string>real ; 
                real.push_back(line[0]); 
                for(int i = 1 ; i < line.size() ; i++){
                    if(line[i] == ",") {real.push_back(",") ; continue ; }
                    auto it = find(ala[temp[0]].begin(),ala[temp[0]].end(),line[i]) - ala[temp[0]].begin(); 
                    if(it == ala[temp[0]].size()){
                        real.push_back(line[i]);
                    }
                    else{
                        real.push_back(actual[temp[0]][it]);
                    }
                }
                for(auto it : real){
                    cout << it << " " ; 
                }cout << endl ; 
            }
        }
    }
    in.close();
}

int main(){
    ifstream in ; 
    in.open("input.txt"); 
    string s ;
    int macroFlag = 0 ; 
    int startFlag = 0 ;
    int mdtp = 0 ;
    string curr = "" ; 
    while(getline(in,s)){
        if(s == "MACRO"){ macroFlag = 1 ; continue ; }
        if(s == "MEND"){ 
            macroFlag = 0 ; 
            mnt[curr].second = mdtp ; 
            curr = "" ; 
            continue ; 
        }
        if(s == "START"){ startFlag = 1 ; continue ;}

        stringstream x(s);
        string word ; 
        vector<string>temp;
        while(getline(x,word,' ')){
            temp.push_back(word);
        }

        if(macroFlag == 1){
            curr = temp[0] ;
            mnt[temp[0]].first = mdtp ; 
            for(int i = 1 ; i < temp.size() ; i++){
                if(temp[i] == ",") continue ;
                ala[curr].push_back(temp[i]);
            }
            macroFlag = 2 ;
        }
        else if(macroFlag == 2){
            mdt.push_back(s); 
            mdtp++ ; 
        }
        if(startFlag == 1){
            if(mnt.find(temp[0]) == mnt.end()) continue ; 
            for(int i = 1 ; i < temp.size() ; i++){
                if(temp[i] == ",") continue ; 
                actual[temp[0]].push_back(temp[i]);
            }
        }
    }
    in.close(); 

    cout << "MNT Table" << endl ; 
    for(auto it : mnt){

        cout << it.first << " " << it.second.first  << endl ; 
    }
    cout << "MDT Table" << endl ; 
    int index = 0 ; 
    for(auto x : mdt){
        cout << index << " " ; 
        cout << x << endl ; 
        index++ ;
    }

    cout << "Argument List Array" << endl ; 
    for(auto it : ala){
        cout << it.first << " -> " ; 
        for(auto x : ala[it.first]){
            cout << x << " " ; 
        }cout << endl ; 
    }

    cout << "Actual Parameter used in Macro call" << endl ; 
    for(auto it : actual){
        cout << it.first << " ->" ; 
        for(auto x : actual[it.first]){
            cout << x << " " ; 
        }cout << endl ; 
    }
    cout << "PASS 2 begins" << endl ; 
    pass2();


    return 0 ;
}