
void prefixSum(){

    for(int i = 1 ; i <= n ; i++)
          pre[i] = pre[i - 1] + arr[i] ;

    for(int i = 0 ; i < q ; i++){
          int l , r ;
          cin >> l >> r ;
          res = pre[r] - pre[l - 1] ;
    }
}

void prefixSum2D(){
    
    for(int i = 1 ; i <= n ; i++) for(int j = 1 ; j <= m ; j++){
          pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + arr[i][j] ;
    }

    for(int i = 0 ; i < q ; i++){
          int x1 , y1 , x2 , y2 ;
          // (x1 , y1) the coordinate of the top-left corner
          // (x2 , y2) the coordinate of the bottom-right corner
          ans = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] ;
    }
}

void lazySum(){

    for(int i = 0 ; i < q ; i++){
           int l , r , val ;
           l-- , r-- ;
           pre[l] += val;
           pre[r + 1] += -val;
    }

    for(int i = 1 ; i < n ; i++) pre[i] += pre[i - 1] ;

    for(int i = 0 ; i < n ; i++) arr[i] += pre[i] ;
}

void prefixXor(){

   for(int i = 0 ; i < n ; i++){
       pre_xor[i] = (i == 0) ? a[i] : pre_xor[i - 1] ^ a[i] ;
   }

   for(int i = 0 ; i < q ; i++){
          int l , r ;
          l-- , r-- ;
          ans = (l == 0) ? pre_xor[r] : pre_xor[r] ^ pre_xor[l - 1]  ;
   }
}
