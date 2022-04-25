#include <bits/stdc++.h>
using namespace std;
#include <fstream>
#include <sstream>

void merge(set<char> &a, set<char> b) {
    for (auto &x : b) {
        a.insert(x);
    }
}

void solve() {
    ifstream in;
    in.open("first_input.txt");
    map<string, vector<string>> prods;
    map<string, set<char>> first;
    map<string, set<char>> follow;

    string s;
    while (getline(in, s)) {
        stringstream x(s);
        string cur = "";

        string word;
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

    function<set<char>(char)> recur = [&](char ch) -> set<char> {
        set<char> temp1;

        if (ch >= 'A' && ch <= 'Z') {
            for (auto &it : prods[string(1, ch)]) {
                merge(temp1, recur(it[0]));
            }
        } else {
            temp1.insert(ch);
        }

        return temp1;
    };

    for (auto &x : prods) {
        set<char> temp_ans;
        for (auto &y : x.second) {
            merge(temp_ans, recur(y[0]));
        }
        first[x.first] = temp_ans;
    }

    bool start = true;
    for (auto &x : prods) {
        set<char> temp_ans;
        if (start) {
            start = false;
            temp_ans.insert('$');
        }

        for (auto &y : prods) {
            for (auto &it : y.second) {
                for (int i = 0; i < (int)it.size(); ++i) {
                    if (string(1, it[i]) == x.first) {
                        if (i + 1 < (int)it.size()) {
                            if (it[i + 1] >= 'A' && it[i + 1] <= 'Z') {
                                merge(temp_ans, first[string(1, it[i + 1])]);
                            } else {
                                temp_ans.insert(it[i + 1]);
                            }
                        } else {
                            merge(temp_ans, follow[y.first]);
                        }
                    }
                }
            }
        }

        follow[x.first] = temp_ans;
    }
}

int main() { solve(); }
