int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    int max_left[m], max_right[m];
    int result[m], sum = 0;

    max_left[0] = A[0];
    for(int i = 1; i < m; i++)
    {
        max_left[i] = max(max_left[i-1], A[i]);
    }


    max_right[m-1] = A[m-1];
    for(int i = m-2; i >=0; i--)
    {
        max_right[i] = max(max_right[i+1], A[i]);
    }

    for(int i = 0; i < m; i++)
    {
        result[i] = min(max_left[i], max_right[i]) - A[i];
        sum += result[i];
    }
    return sum;
    
}
