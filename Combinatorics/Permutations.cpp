// Permutations : N!
// k-Permutations : N! / (N - K)!
// Permutations with repetition : N! / (c1! * c2! * ... * cm!) where c is count of repeated element
// A Derangement is a permutation of n elements, such that no element appears in its original position


// https://www.geeksforgeeks.org/rencontres-number-counting-partial-derangements/ 
// https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/
ll der(ll n){
   if(n == 1) return 0 ;
   if(n <= 2) return 1 ;
   return (n - 1) * (der(n - 1) + der(n - 2)) ;
}
