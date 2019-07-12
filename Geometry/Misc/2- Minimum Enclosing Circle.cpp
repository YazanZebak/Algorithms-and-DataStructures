const int MAX = 100000+9;
point pnts[MAX] , r[3] , cen;
double rad;
int ps , rs;    // ps = n, rs = 0, initially
// precondition
// random_shuffle(pnts , pnts + ps);        rs = 0;
// minimum enclosing circle
void MEC() { // O(n)
    if(ps == 0 && rs == 2) {
        cen = (r[0] + r[1])/2.0;
        rad = length(r[0] - cen);
    }
    else if(rs == 3) {
        pair < double , point > p = findCircle(r[0] , r[1] , r[2]);
        cen = p.second;
        rad = p.first;
    }
    else if(ps == 0) {
        cen = r[0]; // sometime be garbage, but will not affect
        rad = 0;
    }
    else {
        ps--;
        MEC();

        if(length(pnts[ps] - cen) > rad) {
            r[rs++] = pnts[ps];
            MEC();
            rs--;
        }

        ps++;
    }
}