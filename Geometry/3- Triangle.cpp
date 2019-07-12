/**

   Law of Sines   : sin(A)/a  = sin(B)/b = sin(C)/c

   Law of Cosines : a^2 = b^2 + c^2 - 2*b*c * cos(A)
                  : b^2 = a^2 + c^2 - 2*a*c * cos(B)
                  : c^2 = a^2 + b^2 - 2*a*b * cos(C)

**/

//! https://www.mathsisfun.com/algebra/trig-solving-triangles.html
double getSide_a_bAB(double b , double A , double B) {
    return (sin(A) * b)/sin(B) ;
}

double getAngle_A_abB(double a , double b , double B) {
    return asin( fixAngle( (a * sin(B)/b )) ) ;
}

double getAngle_A_abc(double a , double b , double c) {
    return acos( fixAngle ( (b*b + c*c - a*a)/(2*b*c) ) ) ;
}

double triangleArea(point p0 , point p1 , point p2) {
    double a = length(p0 - p1) , b = length(p0 - p2) , c = length(p1 - p2);
    double s = (a + b + c)/2 ;
    return sqrt( (s - a) * (s - b) * (s - c) * s ); //! Heron's formula
}

//! Given the length of the 3 medians of a triangle , find area
double triangleArea(double m1 , double m2 , double m3) {
    // area of triangle using medians as sides = 3/4 * (area of original triangle )
    if(m1 <= 0 || m2 <= 0 || m3 <= 0) return -1 ;
    // for area made by sides as medians
    double s = 0.5 * (m1 + m2 + m3) ;
    double medians_area = (s * (s - m1) * (s - m2) * (s - m3) ) ;
    double area = 4.0/3.0 * sqrt(medians_area) ;
    if(medians_area <= 0.0 || area <= 0) return -1 ;
    return area ;
}

//! if these 3 points on circle boundary ( Triangle inside Circle )
double getRadius(point p0 , point p1 , point p2) {
    double a = length(p0 - p1) , b = length(p0 - p2) , c = length(p1 - p2);
    return (a * b * c)/(4 * triangleArea(p0 , p1 , p2)) ;
}

//! if circle inside triangle
double getRadius(point p0 , point p1 , point p2) {
    double a = length(p0 - p1) , b = length(p0 - p2) , c = length(p1 - p2);
    double s = (a + b + c)/2 ;
    return sqrt(  ( (s - a) * (s - b) * (s - c) ) / s ) ;
}

// A non-degenerate triangle is a triangle with positive area.
// a + b > c such that a <= b <= c
