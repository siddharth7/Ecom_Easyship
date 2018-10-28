vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    deque<int> dq;
    int n = A.size();
    vector<int> result;
    // Processing the first k elements
    int i = 0;
    for(i = 0; i<B; i++)
    {
        while(!dq.empty() && A[i] >= A[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    } 

    // i is at k now.
    //Processing the rest of the elements
    for(; i< n; i++ )
    {
        //First of all, store the present max in result vector
        result.push_back(A[dq.front()]);

        //Now pop all elements that do not belong witin the window.
        // Corerction < to <=
        while(!dq.empty() && dq.front() <= i - B)
            dq.pop_front();

        //Now insert the present element (i) if it is "USEFUL"
        while(!dq.empty() && A[i] >= A[dq.back()] )
            dq.pop_back();
        dq.push_back(i);
    }
    // n - k elements have been pushed so far in the result vector
    // whereas it should contain n - k + 1, this is because the last element of the 
    // sliding window has not been considered yet.
    result.push_back(A[dq.front()]);

    return result;
    
    
}
