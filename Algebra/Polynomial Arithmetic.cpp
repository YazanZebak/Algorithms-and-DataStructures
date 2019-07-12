
struct Polynomial {

    vector < int > factor ;
    
    Polynomial(int n) {
        factor = vector < int > (n , 0) ;
    }

    Polynomial(vector < int > factor) : factor(factor) {}

    Polynomial operator + (const Polynomial &P) {
        
        vector < int > Fx = factor , Hx = factor , Gx = P.factor ;
        
        for(int j = 0 ; j < Gx.size() ; j++)
            if(j >= Fx.size()) 
                Hx.push_back(Gx[j]);
            else 
                Hx[j] += Gx[j] ;

        return Polynomial(Hx);
    }

    Polynomial operator - (const Polynomial &P) {
        vector < int > Fx = factor , Hx = factor , Gx = P.factor ;
        
        for(int j = 0 ; j < Gx.size() ; j++)
            if(j >= Fx.size()) 
                Hx.push_back(-Gx[j]) ;
            else 
                Hx[j] -= Gx[j] ;
        
        return Polynomial(Hx);
    }

    Polynomial operator * (const Polynomial &P) {

        vector < int > Fx = factor ,  Gx = P.factor ;
        vector < int > Hx = vector < int > (Gx.size() + Fx.size() - 1 , 0) ;
        
        for(int i = 0 ; i < Fx.size() ; i++)
            for(int j = 0 ; j < Gx.size() && Fx[i] ; j++)
                Hx[i + j] += Fx[i] * Gx[j] ;
        
        return Polynomial(Hx);
    }

    Polynomial operator / (const Polynomial &P) {
        
        vector < int > Fx = factor ,  Gx = P.factor , Hx ;
        
        while(Fx.size() > Gx.size()) Gx.push_back(0) ;
        
        Hx.push_back(Fx[0] / Gx[0]) ;
        
        for(int i = 1 ; i < Fx.size() ; i++) {
            int sum = 0 ;
            for(int j = 1 ; j <= i ; j++) {
                sum += Gx[j] * Hx[i - j] ;
            }
            Hx.push_back((Fx[i] - sum) / Gx[0]) ;
        }
        
        while(!Hx.empty() && Hx.back() == 0) Hx.pop_back() ;
        
        return Polynomial(Hx) ;
    }
};
