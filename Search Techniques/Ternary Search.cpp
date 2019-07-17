
double ternaryReal(){

	   double left, right; // set your range
	   while(right - left > eps){
	   	     double g = left + (right - left) / 3 , h = left + 2 * (right - left) / 3 ; 

	   	     if(f(g) < f(h)) // use > if f increase the decrease 
	   	     	right = h;
	   	     else
	   	     	left = g;
	   }

	   return f(left);
}

int ternaryInt(){

	int left, right; // set your range
	while(right - left > 3){
		  int g = left + (right - left) / 3, h = left + 2 * (right - left) / 3;

		  if(f(g) < f(h)) // use > if f increase the decrease 
		  	 right = h; 
		  else 
		  	 left = g; 
	}

	int ans = f(left++);
	for(int i = left ; i <= right ; i++)
		  ans = min(ans , f(i));

	return ans;
}