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
    vector<string>v(n);
    f(i, 0, n) cin>>v[i];
    f(i, 0, n) {
        bool first = true, found = false;
        vs alpha, beta;
        ll len = v[i].length();
        f(j, 3, len) {
            if(v[i][j] == v[i][0]) {
                found = true;
                string temp = "";
                f(k, j + 1, len) {
                    if(v[i][k] == '|') {
                        j = k;
                        if(temp.length() > 0) alpha.pb(temp);
                        temp = "";
                        break; 
                    }
                    else temp.pb(v[i][k]);
                }
                // if(temp.length() > 0) alpha.pb(temp);
            }
            else {
                if(found) {
                    string temp = "";
                    f(k, j, len) {
                        if(v[i][k] == '|') {
                            j = k;
                            if(temp.length() > 0) beta.pb(temp);
                            temp = "";
                            break;
                        }
                        else temp.pb(v[i][k]);
                    }
                    if(temp.length() > 0) {
                        beta.pb(temp);
                        j = len;
                    }
                }
                else break;
            }
            // cout<<j<<endl;
        }
        // shov(alpha);
        // shov(beta);
        if(!found) cout<<v[i]<<endl;
        else {
            if(beta.size() == 0) {
                shov(v[i]);
                continue;
            }
            cout<<v[i][0]<<" -> ";
            f(j, 0, beta.size()) {
                cout<<beta[j]<<v[i][0]<<"'";
                if(beta.size()>0 && j==beta.size()-1) continue; 
                else cout<<" | ";
            }
            cout<<endl;
            cout<<v[i][0]<<"' -> ";
            for(auto j: alpha) cout<<j<<v[i][0]<<"' | ";
            cout<<"epi"<<endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    test(t) solve();
}
