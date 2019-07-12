
vector<int> prefixFunction(string s) {
    int m = (int)s.size();

    vector<int> ret = vector<int>(m , 0);
    for (int i = 1 , k = 0 ; i < m ; i++) {
        while (k > 0 && s[k] != s[i])
            k = ret[k - 1];
        ret[i] = (s[i] == s[k] ? ++k : k);
    }

    return ret;
}

vector<int> KMP(string str, string pat) {
    int n = (int)str.size();
    int m = (int)pat.size();

    vector<int> ret;
    vector<int> prefix = prefixFunc(pat);

    for (int i = 0 , k = 0 ; i < n ; i++) {
        while (k > 0 && pat[k] != str[i])
            k = prefix[k - 1];

        if (pat[k] == str[i]) k++;

        if (k == m) {
            ret.push_back(i - m + 1);
            k = prefix[k - 1];
        }
    }
    return ret;
}
