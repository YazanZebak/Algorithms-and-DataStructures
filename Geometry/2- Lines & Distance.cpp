// Line Equations

// Explicit 2D :  y = f(x) = mx + b            , a non vertical 2D line                : m = slope = (y0 - y1)/(x0 - x1)
// Implicit 2D :  f(x , y) = ax + by + c = 0   , any 2D line but can't extended to 3D  : a = (y0 - y1) , b = (x1 - x0) , c = (x0 * y1 - x1 * y0)
// Parametric  :  P(t) =  P0 + t * v           , any line in any dimension             : t = [0 , 1] , v = (p1 - p0)

// Line L makes an angle theta with the x-axis
// a = -sin(theta) , b = cos(theta) , c = (sin(theta) * x0  - cos(theta) * y0)
// P(t) = (x0 + t * cos(theta) , y0 + t*sin(theta))


bool isCollinear(point a , point b , point c) {
    return fabs( cross(b - a , c - a) ) < eps ;
}

bool isPointOnRay(point a , point b , point c) {
    if(!isCollinear(a , b , c))
        return false ;
    return dcmp( dot(b - a , c - a) , 0) == 1 ;
}

bool isPointOnSegment(point a , point b , point c) {
    return isPointOnRay(a , b , c) && isPointOnRay(b , a , c);
}

double distToLine(point a , point b , point c){
     double dist = cross(b - a , c - a) / length(a - b) ;
     return fabs(dist) ;
}

// minimum distance from point p2 to segment p0-p1
double distToSegment( point p0 , point p1 , point p2) {

    double d1 , d2 ;
    point v1 = p1 - p0 , v2 = p2 - p0 ;

    if( (d1 = dot(v1 , v2) ) <= 0) // p2 before p0-p1
        return length(p2 - p0);
    if( (d2 = dot(v1 , v1) ) <= d1) // p2 after p0-p1 
        return length(p2 - p1);

    double t = d1 / d2 ;
    return length(p2 - (p0 + v1 * t) ); // p2 above p0-p1
}

bool intersectSegments(point a , point b , point c , point d , point &intersect) {

    double d1 = cross(a - b , d - c) , d2 = cross(a - c , d - c) , d3 = cross(a - b , a - c) ;
    if(fabs(d1) < eps)
        return false ; // Parllel || identical

    double t1 = d2/d1 , t2 = d3/d1 ;
    intersect = a + (b - a) * t1 ;

    if( t1 < -eps || t2 < -eps || t2 > 1 + eps )
        return false ; // e.g : ab(t1) is ray , cd(t2) is segment ..... change to whatever
    return true ;
}

// Other types of Intersections 
// http://geomalgorithms.com/a06-_intersect-2.html
// http://geomalgorithms.com/a05-_intersect-1.html