#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<char> ops = {'^', '/', '*', '%', '-', '+'};

    int t_cnt = 1;
    map<string, string> ans;

    for (int k = 0; k < 6;) {
        if (count(s.begin(), s.end(), ops[k]) == 0) {
            k++;
            continue;
        }

        int y;
        for (y = 0; y < s.size(); y++) {
            if (s[y] == ops[k])
                break;
        }

        int l = y - 1;
        string left = "";

        while (l >= 0 && find(ops.begin(), ops.end(), s[l]) == ops.end() && s[l] != '=') {
            left += s[l];
            l--;
        }
        reverse(left.begin(), left.end());

        int r = y + 1;
        string right = "";

        while (r < s.size() && find(ops.begin(), ops.end(), s[r]) == ops.end() && s[r] != '=') {
            right += s[r];
            r++;
        }

        string tnum = "t" + string(1, t_cnt + '0');
        ans[tnum] = left + ops[k] + right;
        s.erase(l + 1, r - l - 1);
        s.insert(l + 1, tnum);
        t_cnt++;
    }

    cout << "Three Address Code : \n\n";
    string last;
    for (auto &x : ans) {
        cout << x.first << "=" << x.second << "\n";
        last = x.first;
    }
    cout << s[0] << "=" << last;
}

int main() {
    solve();
}

/*
IP :- 
a=b-c*d+e/f

OP :-
Three Address Code : 

t1=e/f
t2=c*d
t3=b-t2
t4=t3+t1
a=t4
*/
