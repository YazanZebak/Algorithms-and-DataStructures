
// Maximum Rectangle Sum O(N^3)
int MRS(){

    int ret = 0 , best = 0 ;

    for(int i = 1 ; i <= m ; i++){
        for(int j = i ; j <= m ; j++){
            for(int k = 1 , mis = 0 ; k <= n ; k++){
                 sum = pre[k][j] - pre[k][j - i];
                 mis = (mis < 0) ? sum : mis + sum ;
                 best = max(best , mis) ;
            }
            ret = max(ret , best);
        }
    }

    return ret ;
}

// Largest Square of Ones O(N^2)
int LSQ(int i , int j){

    if(i < 0 || i >= n) return 0 ;
    if(j < 0 || j >= n) return 0 ;

    if(A[i][j] == 0) return 0 ;

    return 1 + min(LSQ(i + 1 , j + 1) , min(LSQ(i + 1,  j) , LSQ(i , j + 1))) ;
}
