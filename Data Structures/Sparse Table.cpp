
void build(){
    
    for(int i = 0 ; (1 << i) <= n ; i++){
        for(int x = 0 ; x + (1 << i) - 1 < n ; x++){
            if(i == 0) 
                  table[x][i] = arr[x] ; 
            else
                  table[x][i] = max(table[x][i - 1] , table[x + (1 << i)][i - 1]);
        }
    }

}

int query(int l , int r){
    int k = log[r - l + 1] ; 
    return max(table[l][k] , table[r - (1 << k) + 1][k]);
}


/*********************** 2D Sparce Table *************************/

void build(){

    for(int i = 0 ; (1 << i) <= n ; i++) {
        for(int j = 0 ; (1 << j) <= m ; j++) {
            for(int x = 0 ; x + (1 << i) - 1 < n ; x++) {
                for(int y = 0 ; y + (1 << j) - 1  < m ; y++) {
                    if(i == 0 && j == 0)
                        table[x][y][i][j] = grid[x][y] ;
                    else if(i == 0)
                        table[x][y][i][j] = max(table[x][y][i][j - 1] , table[x][y + (1 << (j - 1))][i][j - 1]);
                    else if(j == 0)
                        table[x][y][i][j] = max(table[x][y][i - 1][j] , table[x + (1 << (i - 1))][y][i - 1][j]);
                    else
                        table[x][y][i][j] = max(table[x][y][i - 1][j - 1]
                                                , max(table[x + (1 << (i - 1))][y][i - 1][j - 1]
                                                      , max(table[x][y + (1 << (j - 1))][i - 1][j - 1]
                                                            , table[x + (1 << (i - 1))][y + (1 << (j - 1))][i - 1][j - 1])));
                }
            }
        }
    }


}

// top-left(x , y) , bottom-right(x1 , y1)
int query(int x , int y , int x1 , int y1) {
    int k = log[x1 - x + 1];
    int l = log[y1 - y + 1];
    return max(table[x][y][k][l] ,
               max(table[x1 - (1 << k) + 1][y][k][l] ,
                   max(table[x][y1 - (1 << l) + 1][k][l], table[x1 - (1 << k) + 1][y1 - (1 << l) + 1][k][l])));
}

