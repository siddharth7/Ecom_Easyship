  int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int diff = INT_MAX;
    
    int i = 0, j = 0, k = 0;
    int final_i = 0, final_j = 0, final_k = 0;
    
    int m = A.size(), n = B.size(), o = C.size();
    int minimum, maximum;
    while(i < m && j < n && k < o)
    {
        //Obtain the maximum and the minimum pf the three numbers
        minimum = min(A[i], min(B[j], C[k]));
        maximum = max(A[i], max(B[j], C[k]));
        
        // abs is not used , since maximum - minimum will always be positive
        if(maximum - minimum < diff)
        {
            diff = maximum - minimum;
            final_i = i; final_j = j; final_k = k;
            
        }
        
        if(diff == 0) break;
        
        //Sinec we aim to derease the max difference, we increase the minimum element
        if(A[i] == minimum) i++;
        else if(B[j] == minimum) j++;
        else k++;
    }
    
    return diff;
    
}
