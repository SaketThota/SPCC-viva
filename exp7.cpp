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
