/*
*  Volume of Tetrahedrons given the length of the six sides
*  AB, AC, AD, BC, BD, CD.
*  Useful Links :
*  https://en.wikipedia.org/wiki/Tetrahedron#Volume
*/
#include <bits/stdc++.h>
typedef long long ll ;
using namespace std;

int main() {

    ios::sync_with_stdio(false) ;

    cout << fixed << setprecision(4) ;

    int t ;
    cin >> t;

    while (t--) {
        double U, V, W, u, v, w;
        cin >> w >> v >> u >> U >> V >> W;
        double X = (w - U + v) * (U + v + w);
        double x = (U - v + w) * (v - w + U);
        double Y = (u - V + w) * (V + w + u);
        double y = (V - w + u) * (w - u + V);
        double Z = (v - W + u) * (W + u + v);
        double z = (W - u + v) * (u - v + W);
        double a = sqrt(x * Y * Z);
        double b = sqrt(X * y * Z);
        double c = sqrt(X * Y * z);
        double d = sqrt(x * y * z);
        double ans = -a + b + c + d;
        ans *= a - b + c + d;
        ans *= a + b - c + d;
        ans *= a + b + c - d;
        ans = sqrt(ans) / (192.0 * u * v * w);
        cout << ans << endl;
    }

    return 0;
}
