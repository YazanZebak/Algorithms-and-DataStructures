string letters = "0123456789ABCDEF" ; 

int toInt(char c){
    return letters.find(c);
}

int baseToDecimal(string in , int base){
    int res = 0 ;
    for(int i = 0 ; i < (int)in.size() ; i++)
           res *= base , res += toInt(in[i]) ;
    return res ;
}

string decimalToBase(int number , int base){
       if(!number) return "0" ;
       
       string res = "" ;
       // Warning : if base does not have zero : number = (number - 1) / base , letters[(number - 1) % base]
       for( ; number ; number /= base)
             res.push_back(letters[number % base]);
         
       reverse(res.begin() , res.end());
       return res ;
}
