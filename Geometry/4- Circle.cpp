// Area : PI * R^2 
// Circumference : PI * 2 * R 
// Length of Arc : theta / 360 * (2 * PI * R)
// Sector Area : theta / 360 (PI * R^2) 
// Tangent :  E . (A + E) , E = dist from point to circle , A = diamater. 


// 2 points has infinite circles
// Find circle passes with 3 points, some times, there is no circle! (in case collinear)
// Draw two perpendicular lines and intersect them
// https://www.qc.edu.hk/math/Advanced%20Level/circle%20given%203%20points.htm
pair < double , point > findCircle(point a , point b , point c) {
    if(isCollinear(a , b , c)) return undefind ;
    point m1 = (b + a) * 0.5 , v1 = b - a , pv1 = point(v1.Y , -v1.X);
    point m2 = (b + c) * 0.5 , v2 = b - c , pv2 = point(v2.Y, -v2.X);
    point end1 = m1 + pv1 , end2 = m2 + pv2 , center;
    intersectSegments(m1 , end1 , m2 , end2 , center);
    return make_pair( length(a - center) , center );
}

// If line intersect circle at point p , and p = p0 + t(p1-p0)
// Then (p-c)(p-c) = r^2 substitute p and rearrange
// (p1-p0)(p1-p0)t^2 + 2(p1-p0)(p0-C)t + (p0-C)(p0-C) = r*r; -> Quadratic
vector < point > intersectLineCircle(point p0 , point p1 , point C , double r) {
    double a = dot(p1 - p0 , p1 - p0) , b = 2 * dot(p1 - p0 , p0 - C) , c = dot(p0 - C , p0 - C) - r*r;
    double f = b*b - 4*a*c;

    vector < point > v;
    if( dcmp(f, 0) >= 0 ) {
        if( dcmp(f, 0) == 0 )	f = 0;
        double t1 =(-b + sqrt(f))/(2*a);
        double t2 =(-b - sqrt(f))/(2*a);
        v.push_back( p0 + t1*(p1-p0) );
        if( dcmp(f , 0) != 0)	v.push_back( p0 + t2*(p1-p0) );
    }
    return v;
}

vector < point > intersectCircleCircle(point c1 , double r1 , point c2 , double r2) {
    // Handle infinity case first: same center/radius and r > 0
    if(same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
        return vector< point >(3 , c1);    // infinity 2 same circles (not points)

    // Compute 2 intersection case and handle 0, 1, 2 cases
    double ang1 = angle(c2 - c1) , ang2 = getAngle_A_abc(r2 , r1 , length(c2 - c1));

    if(::isnan(ang2)) // if r1 or d = 0 => nan in getAngle2 (/0)
        ang2 = 0; // fix corruption

    vector < point > v(1 , polar(r1, ang1 + ang2) + c1);

    // if point NOT on the 2 circles = no intersection
    if(dcmp(dot(v[0] - c1 , v[0] - c1) , r1 * r1) || dcmp(dot(v[0] - c2 , v[0] - c2) , r2*r2))
        return vector < point >();

    v.push_back(polar(r1, ang1 - ang2) + c1);
    if(same(v[0], v[1]))  // if same, then 1 intersection only
        v.pop_back();
    return v;
}

// Given a line with first end point P(x1,y1) another end point is unknown
// intersect with a circle that located at point C(x,y) with radius R at only one point(tangent) T(x2,y2).
// P.S. Note that there is also a second tangent, which is found by rotating DO by minus alpha
// https://stackoverflow.com/a/19795093
point tangentPointWithCircle(point p1, point c, double r, int sign) {

    point p_to_c = vec(p1, c);

    double dist = length(p_to_c);
    double alpha = asin(r / dist);
    double side = sqrt(dist*dist - r*r);

    point tanget;

    tanget = rotate(p_to_c, sign * alpha);
    tanget = normalize(tanget);
    tanget *= side;

    tanget = p1 + tanget;
    return tanget;
}

