/***************** Complex ****************/

const double PI = acos(-1) ;
const double eps = (1e-8) ;

typedef complex < double > point ;

#define X real()
#define Y imag()

#define angle(u)      (atan2((u).Y , (u).X))
#define vec(p1 , p2)  ((p2) - (p1))

//! hypot is slow function but avoid overflow
//! is the squared distance enough ?  
#define length(v) (hypot((v).Y , (v).X))
#define normalize(v) (v)/length(v)

//! avoid using norm, use dot(x, x) insted
#define dot(v , u)      ( (conj(v) * (u)).X )
#define cross(v , u)    ( (conj(v) * (u)).Y )

#define same(p1 , p2) 	(dot(vec(p1 , p2),vec(p1 , p2)) < eps)
#define lengthSqr(p)  	(dot(p, p))

/***************** Angles Methods ****************/

int dcmp(double a , double b){
     if(fabs(a - b) <= eps) return 0 ;
     return a < b ? -1 : 1 ;
}

double toDegree(double radian){
    if(radian < 0) return radian += 2 * PI ;
    return (radian * 180 / PI) ;
}

double toRadian(double degree){
       return (degree * PI / 180.0) ;
}

double fixAngle(double A){
      return A > 1 ? 1 : (A < -1 ? -1 : A) ;
}

/***************** Misc ****************/

bool isPerp(point v , point w){
    return dot(v , w) == 0 ;
}

double slope(point a , point b){
      return tan(arg(vec(a , b)));
}

/***************** Transformations ****************/

//! (x' , y') = (x + h, y + k)
//! line' = Ax' + By' + (-Ah - Bk + C) = 0
point translate(point p , point v){
     return p + v ;
}

//! x' = x * cos(theta) - y * sin(theta) 
//! y' = x * sin(theta) + y * cos(theta)
//! line' = (A * cos(theta) - B * sin(theta))x' + (A * sin(theta) + B * cos(theta))y' + C = 0
point rotate(point p , double A){
      return p * polar(1.0 , A);
}

point rotate(point p , double A , point center){
      return rotate(vec(center , p) , A) + center ;
}

//! x' = x * cos(2*theta) + y * sin(2*theta) 
//! y' = x * sin(2*theta) - y * cos(2*theta)
point reflect(point v , point m){
     return conj(v/m) * m ;
}

//! reflect point p around p0p1
point reflect(point p , point p0 , point p1){
     point z = p - p0 , w = p1 - p0 ;
     return conj(z/w)*w + p0;
}

point scale(point center , double factor , point p){
      return center + (p - center) * factor ;
}

//! F(p) = a * p + b , F(q) = a * q + b , (a == 1 ? "translation" : "combination of a scaling and a rotation")
point linearTransform(point p , point q , point r , point fp , point fq){
      return fp + (r - p) * (fq - fp) / (q - p) ;
}
