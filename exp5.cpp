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

bool proceed(vs v) {
    if(v.size() == 1) return false;
    f(i, 1, v.size()) {
        if(v[i][v[i].size() - 1] != v[0][v[0].size() - 1]) return false; 
    }
    return true; 
}

vs modify(vs v) {
    vs temp;
    f(i, 0, v.size()) if(v[i].size() > 0) temp.pb(v[i]);
    return temp;
}

void solve() {
    string s;cin>>s;
    string caps = "ABCDEFGHIKLMNOPQURSTUVWXYZ";
    ll step = 1;
    ll loc = 0;
    vs v;
    string temp = "";
    ll len = s.length();
    f(i, 3, len) {
        if(s[i]=='|') {
            v.pb(temp);
            temp = "";
        }
        else temp.pb(s[i]);
    }
    cout<<endl;
    cout<<"***********************RESULTS************************"<<endl;
    v.pb(temp);
    f(i, 0, v.size()) reverse(v[i].begin(), v[i].end());
    sort(v.begin(), v.end());
    vs logs;
    char prev = 'S';
    while(proceed(v)) {
        cout<<"Grammar still has common prefixes, left factoring can be done"<<endl;
        cout<<endl;
        cout<<"STEP"<<step<<" : "<<endl;
        if(step==1) {
            string output = "S-> ";
            output.pb(v[0][v[0].size() - 1]);
            output += "S'";
            logs.pb(output);
            f(i, 0, v.size()) v[i].pop_back();
            v = modify(v);
        }
        else {
            string output = "";
            output.pb(prev);
            output += "'";
            output += "-> ";
            output.pb(v[0][v[0].size() - 1]);
            output.pb(caps[loc]);
            output += "'";
            logs.pb(output);
            prev = caps[loc];
            loc++;
            f(i, 0, v.size()) v[i].pop_back();
            v = modify(v);
        }
        cout<<logs[0]<<endl;
        f(i, 1, logs.size()) cout<<logs[i]<<"|eps"<<endl;
        cout<<prev<<"'-> ";
        f(i, 0, v.size()) {
            ll len = v[i].size();
            rf(j, len - 1, 0) cout<<v[i][j];
            cout<<" | ";
        }
        cout<<"eps"<<endl;
        step++;
        cout<<endl;
        cout<<"******************************************************"<<endl;
        cout<<endl;
    }
    cout<<"No more common prefixes present, VIVA khatam"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);a
    // freopen("output.txt", "w", stdout);
    test(t) solve();
}