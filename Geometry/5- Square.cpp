
bool isSquare(point p1, point p2, point p3, point p4) {
 
    vector < point > p = {p1 , p2 , p3 , p4} ;
 
    for(int i = 0 ; i < 4 ; i++)
        for(int j = i + 1 ; j < 4 ; j++)
              if(same(p[i] , p[j])) return false;
 
    ll d2 = lengthSqr(p1, p2);
    ll d3 = lengthSqr(p1, p3);
    ll d4 = lengthSqr(p1, p4);
 
    if (d2 == d3 && 2 * d2 == d4 && 2 * d2 == lengthSqr(p2, p3)) {
        ll d = lengthSqr(p2, p4);
        return (d == lengthSqr(p3, p4) && d == d2);
    }
    if (d3 == d4 && 2 * d3 == d2 && 2 * d3 == lengthSqr(p3, p4)) {
        ll d = lengthSqr(p2, p3);
        return (d == lengthSqr(p2, p4) && d == d3);
    }
    if (d2 == d4 && 2 * d2 == d3 && 2 * d2 == lengthSqr(p2, p4)) {
        ll d = lengthSqr(p2, p3);
        return (d == lengthSqr(p3, p4) && d == d2);
    }
    return false;
}
 