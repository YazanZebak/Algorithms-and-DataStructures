struct trie{

    trie* child[MAX_CHAR];
    bool isLeaf;

    trie(){
        memset(child, 0, sizeof(child));
        isLeaf = 0;
    }

    void insert(char *str){
        
        if(*str == '\0') isLeaf = 1;
        
        else{
            int cur = *str - 'a';
            
            if(child[cur] == 0)
            	 child[cur] = new trie();
            
            child[cur]->insert(str + 1);
        }
    }

    bool wordExist(char* str){
        
        if(*str == '\0')
            return isLeaf;

        int cur = *str - 'a';
        
        if(child[cur] == 0 )
            return false;	// such path don't exist

        return child[cur]->wordExist(str + 1);
    }

    bool prefixExist(char* str){
        if(*str == '\0')
            return true;
        
        int cur = *str - 'a';
        
        if(child[cur] == 0 )
            return false;	// such path don't exist

        return child[cur]->prefixExist(str+1);
    }

    void clear(trie* cur){

        for(int i = 0 ; i < MAX_CHAR ; i++)
            if(cur->child[i] != NULL)
               clear(cur->child[i]);

        delete cur ;
    }
};

struct binaryTrie{

    trie *child[2];

    trie(){
        child[0] = child[1] = 0 ;
    }

    void insert(ll num , int i = 63){
        if(i == -1) return ;

        bool bit = ( num & (1LL << i) );

        if(child[bit] == 0)
            child[bit] = new trie() ;

        child[bit]->insert(num , i - 1);
    }

    // find a number P from array A such that (P^X  <=  A[I]^X) for each (1 <= I <= N).  
    ll min(ll x , int i = 63){
        if(i == -1) return 0 ;

        bool bit = ( x & (1LL << i ) );

        if(child[bit])
            return child[bit]->min(x , i - 1) | (bit * (1LL << i));

        return child[!bit]->min(x , i - 1) | (!bit * (1LL << i)) ;
    }

    // find a number P from array A such that (P^X  >=  A[I]^X) for each (1 <= I <= N).
    ll max(ll x , int i = 63){
        if(i == -1) return 0 ;

        bool bit = ( x  & (1LL << i ) );

       if(child[!bit])
            return child[!bit]->max(x , i - 1) | (!bit * (1LL << i)) ;

       return child[bit]->max(x , i - 1) | (bit * (1LL << i));
    }
};


