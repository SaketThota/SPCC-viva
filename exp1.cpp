#include<bits/stdc++.h>
using namespace std;

//#define endl "\n"
#define pb push_back
#define ll long long int
#define f(i, a, b) for(ll i=a;i<b;i++)
#define rf(i, a, b) for(ll i=a;i>=b;i--)

#define put(x) cout<<"I am here at "<<x<<" :";
#define shov(v) for(auto i: v) cout<<i<<" ";cout<<endl;
#define shom(m) for(auto i: m) cout<<i.first<<" "<<i.second<<endl;
#define test(t) ll t;cin>>t;while(t--)
#define __lcm(a, b) (((a) * (b)) / __gcd((a) , (b)))

#define vi vector<int>
#define vll vector<long long int>
#define vs vector<string>
#define mii map<int, int>
#define si set<int>

vector<string> delimiters = {" ",";", ",", "(", ")", "[", "]", "{", "}"};
vector<string> operators = {"+", "-", "*", "/", ">", "<", "="};
vector<string> keywords = {"if", "else", "while", "do", "break", "continue", "int", "float", "double", "return", "char", "case", "sizeof", "long", "short", "typedef", "switch", "unsigned", "void", "static", "struch", "goto", "bool"};


bool isInteger(string s) {
    f(i, 0, s.length()) {
        if(int(s[i])<48 || int(s[i]>57)) {
            if(i==0 && s[i]=='-') continue; 
            else return false; 
        } 
    }
    return true;
}

bool isValid(string s) {
    char temp = s[0];
    if(temp>64&&temp<91 || temp>96&&temp<123) return true;
    else return false;
}

void solve() {
    map<string, string>m;
    for(auto i: delimiters) m[i] = "delimiter";
    for(auto i: operators) m[i] = "operator";
    for(auto i: keywords) m[i] = "keyword";
    ll n;cin>>n;
    vs input(n);
    f(i, 0, n) cin>>input[i];
    cout<<"INPUT STRING : ";
    shov(input);
    map<string ,vs>result;
    f(i, 0, n) {
        if(m.find(input[i]) != m.end()) result[m[input[i]]].pb(input[i]);
        else if(isInteger(input[i])) result["constants"].pb(input[i]);
        else if(isValid(input[i])) result["valid identifiers"].pb(input[i]);
        else result["invalid identifiers"].pb(input[i]);
    }
    for(auto i : result) {
        cout<<i.first<<" : ";
        shov(i.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    test(t) solve();
}