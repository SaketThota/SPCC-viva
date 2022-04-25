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

void solve() {
    ll n;cin>>n;
    vs input(n+1);
    f(i, 0, n+1) getline(cin, input[i]);
    // cout<<input.size()<<endl;
    // f(i, 1, n+1) cout<<input[i]<<endl;
    map<string, vs>grammar;
    f(i, 1, n+1) {
        string temp = "";
        string first;
        bool flag = true;
        f(j, 0, input[i].length()) {
            if(input[i][j] == ' ') {
                if(flag) {
                    first = temp;
                    flag = false;
                }
                else grammar[first].pb(temp);
                temp = "";
            }
            else temp.pb(input[i][j]);
        }
        grammar[first].pb(temp);
    }
    cout<<"GIVEN GRAMMAR => "<<endl;
    for(auto i: grammar) {
        cout<<i.first<<" : ";
        shov(i.second);
    }
    map<string, int>first_done;
    for(auto i: grammar) first_done[i.first] = 0;
    map<string, set<string>>result;
    for(auto i: grammar) {
        // cout<<i.first<<endl;
        vs queue;
        queue.pb(i.first);
        while(queue.size() > 0) {
            // shov(queue);
            string temp = queue[queue.size() - 1];
            queue.pop_back();
            if(temp[0]>64 && temp[0]<91) {
                if(first_done[temp] == 1) {
                    for(auto j: result[temp]) result[i.first].insert(j);
                }
                else {
                    temp = temp.substr(0, 1 + (temp[1] == '`'));
                    queue.pb(grammar[temp][1]);
                    f(j, 2, grammar[temp].size()) if(grammar[temp][j] == "|") queue.pb(grammar[temp][j+1]);
                }
            }
            else {
                if(temp == "id") result[i.first].insert(temp);
                else result[i.first].insert(temp.substr(0, 1));
            }
        }
        first_done[i.first] = 1;
    }
    cout<<result.size()<<endl;
    cout<<"FIRST OF GRAMMAR"<<endl;
    for(auto i: result) {
        cout<<i.first<<" : ";
        for(auto j : i.second) cout<<j<<" ";
        cout<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    test(t) solve();
}