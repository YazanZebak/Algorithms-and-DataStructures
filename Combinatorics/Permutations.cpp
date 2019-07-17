// Permutations : N!
// k-Permutations : N! / (N - K)!
// Permutations with repetition : N! / (c1! * c2! * ... * cm!) where c is count of repeated element
// A Derangement is a permutation of n elements, such that no element appears in its original position


// https://www.geeksforgeeks.org/rencontres-number-counting-partial-derangements/ 
// https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/
ll der(int n, int m){
   
   if(n == 0 && m == 0)
   	 return 1;

   if(n == 1 && m == 0)
   	return 0;

   if(m == 0)
   	return (n - 1) * (der(n - 1 , 0) + der(n - 2 , 0));

   return C[n][m] * der(n - m, 0);
}

// https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
bool nextPermutation(vector<int> arr) {
	
    // Find longest non-increasing suffix
    int i = arr.length() - 1;
    while (i > 0 && arr[i - 1] >= arr[i])
        i--;
    // Now i is the head index of the suffix
    
    // Are we at the last permutation already?
    if (i <= 0)
        return false;
    
    // Let arr[i - 1] be the pivot
    // Find rightmost element that exceeds the pivot
    int j = arr.length - 1;
    while (arr[j] <= arr[i - 1])
        j--;
    // Now the value arr[j] will become the new pivot
    // Assertion: j >= i
    
    // Swap the pivot with j
    int temp = arr[i - 1];
    arr[i - 1] = arr[j];
    arr[j] = temp;
    
    // Reverse the suffix
    j = arr.length - 1;
    while (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    
    // Successfully computed the next permutation
    return true;
}