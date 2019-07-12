
// Range Max/Min Query

void build() {
	for (int i = 0 ;  i< MAX_SQRT ; i++) res[i] = OO;
	sq = ceil(sqrt(N));
	int cnt = 0;
	for (int i = 0 ; i < N ; i++) {
		if (i && i % sq == 0)cnt++;
		res[cnt] = min(res[cnt] , a[i]);
	}
}

int RMQ(int l, int r) {
	int ret = OO;
	while (l % sq != 0 && l < r) ret = min(ret , a[l--]);
	while (l + sq < r) ret = min(ret, res[l/sq]) , l += sq;
	while (l <= r) ret = min(ret , a[l++]);
	return ret;
}

void update(int i, int val) {
    a[i] = val; 
    int from = i/sq * sq , to = min(i/sq * sq + sq, N) , mn = (1e9)+1;
    while (from < to) mn = min(mn, a[from++]); 
    res[i/sq] = mn ;
}


// Range Sum Query

void build() {
	memset(res, 0, sizeof res);
	sq = ceil(sqrt(N));
	int cnt = 0;
	for (int i=0; i<N; i++) {
		if (i && i % sq == 0) cnt++;
		res[cnt] += a[i];
	}
}

int RSQ(int l, int r) {
	int ret = 0;
	while (l % sq != 0 && l < r) ret += a[l++];
	while (l + sq < r) ret += res[l/sq] , l += sq;
	while (l <=r ) ret += a[l++];
	return ret;
}

void update(int i, int val) {
    res[i / sq] -= a[i] , a[i] += val;
    res[i / sq] += a[i];
}
