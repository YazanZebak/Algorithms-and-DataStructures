// Complexity O(N)
const int LEN = 1e5 + 5;
char s[LEN];
int rad[2 * LEN];

void build_rad() { 
    n = 2 * strlen(s);
    for (int i = 0, j = 0, k; i < n; i += k, j = max(j - k, 0)) {
        for (; i >= j && i + j + 1 < n && s[(i - j) / 2] == s[(i + j + 1) / 2]; ++j);
        rad[i] = j;
        for (k = 1; i >= k && rad[i] >= k && rad[i - k] != rad[i] - k; ++k)
            rad[i + k] = min(rad[i - k], rad[i] - k);
    }
}

bool is_palindrome (int l, int r) { 
    return l >= 0 && r < n &&  rad[l + r] >= r - l + 1;
}


/****************** same algorithm / different implementation ************************/

//Returns vector of length (n = s.size()) for every i, the length of the longest palindromic string centered on i.
vector < int > manacher(string s) {
    int f = s.size();
    s = "@" + s + "$";
    vector < int > len(f + 1);
    int l = 1 , r = 1;
    for(int i = 1; i <= f; i++) {
        len[i] = min(r - i , len[l + (r - i)]);
        while(s[i - len[i]] == s[i + len[i]])
            len[i]++;
        if(i + len[i] > r) {
            l = i - len[i];
            r = i + len[i];
        }
    }
    len.erase(len.begin());
    return len;
}
