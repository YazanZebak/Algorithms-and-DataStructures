
//! get the next greater element for all elements
void NGE(){
    stack < pair < int , int > > s;
    for(int i = n - 1 ; i >= 0 ; i--){
        nextBig[i] = -1;
        while(!s.empty() && s.top().first < arr[i]) s.pop();
        if (!s.empty())
            nextBig[i] = s.top().second;
        s.push(make_pair(arr[i] , i));
    }
}

//! get the previous greater element for all elements
void PGE(){
    stack < pair < int , int > > s;
    for (int i = 0; i < n; i++){
        prevBig[i] = -1;
        while (!s.empty() && s.top().first < arr[i]) s.pop();
        if (!s.empty())
            prevBig[i] = s.top().second;
        s.push(make_pair(arr[i], i));
    }
}

//! function to count the number of next greater numbers to the right
void countNGE(){

    memset(next, -1 , sizeof(next));
    NGE();

    for(int i = n - 2; i >= 0 ; i--){
        if(next[i] == -1)
            dp[i] = 0;
        else
            dp[i] = 1 + dp[next[i]];
    }
}

//! find the maximum rectangular area under given histogram with n bars
int getMaxArea(){

    stack < int > s;

    int max_area = 0;

    int i = 0;
    while(i < n){

        if(s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);

        else{
            int tp = s.top();
            s.pop();
            int area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            max_area = max(max_area , area_with_top);
        }

    }

    while(!s.empty()){
        int tp = s.top();
        s.pop();
        int area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        max_area = max(max_area , area_with_top);
    }

    return max_area;
}
