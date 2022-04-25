#include <bits/stdc++.h>
using namespace std;

#include <fstream>
#include <sstream>

int main() {
    ifstream in;
    in.open("source.txt");

    map<string, string> mp;
    map<string, int> vis;

    string s;
    int t_cnt = 1;

    while (getline(in, s)) {
        stringstream x(s);
        string word;

        vector<string> temp;

        while (getline(x, word, ' ')) {
            temp.push_back(word);
        }

        int equal = 0;

        for (auto &x : temp) {
            if (x == "=") {
                equal = 1;
            } else if (equal) {
                if (vis[x]) {
                    continue;
                }
                vis[x] = 1;
                string t_idx = "t" + string(1, '0' + t_cnt);
                mp[t_idx] = x;

                t_cnt++;
            }
        }
    }

    for (auto &x : mp) {
        cout << x.first << " = " << x.second << "\n";
    }
}

// Source code
/*
t1 = -c
t2 = a+b
t3 = a+b
t4 = a+b
t5 = a+b
t6 = d+5
t7 = a+b
t8 = -c
*/
