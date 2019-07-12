typedef vector < double  > row  ;
typedef vector < row >  matrix ;

matrix zero(int n , int m) {
    return matrix(n , row(m , 0));
}

matrix identity(int n) {
    matrix ret = matrix(n , row(n , 0));
    for(int i = 0 ; i < n ; i++) ret[i][i] = 1 ;
    return ret ;
}

int trace(matrix &A) {
    int ret = 0 ;
    for(int i = 0 ; i < A.size() ; i++) ret += A[i][i] ;
    return ret ;
}

matrix rotate(matrix &A) {

    matrix ret = A ;
    for(int i = 0 ; i < A.size() ; i++)
        for(int j = 0 ; j < A[0].size() ; j++)
            ret[j][A.size() - 1 - i] = A[i][j] ;

    return ret ;
}

matrix reflectVertical(matrix &A) {

    matrix ret = A ;
    for(int i = 0 ; i < A.size() / 2 ; i++)
        swap(ret[i] , ret[A.size() - i - 1]);

    return ret ;
}

matrix reflectHorizontal(matrix &A){

    matrix ret = A ;
    for(int i = 0 ; i < A.size() ; i++)
         reverse(ret[i].begin() , ret[i].end());

    return ret ;
}

matrix add(matrix &a , matrix &b) {

    matrix ret = zero( a.size() , a[0].size());

    for(int i = 0 ; i < a.size() ; i++)
        for(int j = 0 ; j < a[0].size() ; j++)
            ret[i][j] = a[i][j] + b[i][j] ;

    return ret ;
}

matrix addIdentity(const matrix &a) {
    matrix ret = a ;
    for(int i = 0 ; i < a.size() ; i++)  ret[i][i] = a[i][i] + 1 ;
    return ret ;
}

matrix multiply(const matrix &a , const matrix &b) {

    matrix ret = zero(a.size() , b[0].size()) ;

    for(int i = 0 ; i < a.size() ; i++)
        for(int k = 0 ; k < a[0].size() ; k++) {
            // Optimization : we could switch the last 2 loops if b[k][j] has more zeros
            for(int j = 0 ; j < b[0].size() && a[i][k] ; j++)
                ret[i][j] += a[i][k] * b[k][j] ;
        }

    return ret ;
}

matrix power(const matrix &A , ll k) {
    if(k == 0)
        return identity(A.size());

    if(k & 1)
        return multiply( A , power(A , k - 1) ) ;

    return power( multiply(A , A) , k / 2) ;
}
