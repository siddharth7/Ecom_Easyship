int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    stack<int> s;
    int max_area = 0, top = 0, present_area = 0;
    int n = A.size();
    
    //Go through all bars in hostogram
    int i = 0;
    while(i < n)
    {
        //If stack is empty , OR, this bar is higher than the one at top of stack, 
        //push the index i and increment i.
        if(s.empty() || A[i] >= A[s.top()])
            s.push(i++);
        
        //else consider bar at present stack top as smallest , and calculate 
        //area using its height as height as width as 
        // 1 if stack is empty , else i - s.top() - 1 , i.e.( difference in the index )
        else
        {
            top = s.top();
            s.pop(); //remove the grater height bar , since future heights will be bound
                     //by the present height , which is lesser than the one which is popped
            present_area = A[top] *(s.empty() ? i : i  - s.top() -1);
            
            if(max_area < present_area)
                max_area = present_area;
        }
    }
    
    while(!s.empty())
    {
        top = s.top();
        s.pop(); //remove the grater height bar , since future heights will be bound
                 //by the present height , which is lesser than the one which is popped
        present_area = A[top] *(s.empty() ? i : i  - s.top() -1);
        
        if(max_area < present_area)
            max_area = present_area;
    }
    return max_area;
}    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

