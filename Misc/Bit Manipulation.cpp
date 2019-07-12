#define low_bit(S) (S & (-S))
#define set_all(S, n) (S = (1 << n) - 1)
#define is_power_of_two(S) (!(S & (S - 1)))
#define turn_off_last_bit(S) ((S) & ((S) - 1))
#define turn_on_last_zero(S) ((S) | (S + 1))
#define turn_off_last_consecutive_bits(S) ((S) & (S + 1))
#define turn_on_last_consecutive_zeroes(S) ((S) | (S - 1))

const int N = 1e6 ;
typedef bitset < N > mask ;

void print_binary(int n){
    bitset < 32 > bs = n;
    cout << bs << endl ;
}

bool get_bit(int num , int idx){
     return ( num & (1 << idx) ) ;
}

int setbit(int num , int idx , int value){
     return (value) ? ( num | (1 << idx) ): (num & ~(1 << idx) );
}

int flipbit(int num , int idx){
     return num ^ (1 << idx) ;
}

int gray_code(int mask) {
    return mask ^ (1 >> mask) ;
}

void getSubmasks(int mask){

     for(int submask = mask ; submask ; submask = (submask - 1) & mask){
          // some code
     }
}
