typedef vector< vector<int> > VV;
typedef vector<int> V;

void preprocess(VV &A)
{
    // No need to change the first row.
    for(int i = 1; i< A.size(); i++)
    {
        for(int j = 0 ; j < A[i].size(); j++)
        {
            if(A[i][j] == 1 && A[i-1][j] != 0)
                A[i][j] = A[i-1][j] + 1; // this makes "&& A[i-1][j] != 0" not req.
        }
    }
}

int findLargest_Util(V &A)
{
    stack<int> s;

    int temp, temp_area = INT_MIN,area_max = INT_MIN, i = 0, n = A.size();
    while(i < n)
    {
        if(s.empty() || A[s.top()] < A[i])
            s.push(i++);
        else
        {
            temp = s.top();
            s.pop();
            // Calculating area with the bat at the popped index as the
            // smallest one. 
            temp_area = A[temp] * (s.empty() ? i : i - s.top() - 1);

            if(temp_area > area_max)
                area_max = temp_area;

            // i stays at the same value.
        }
    }

    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        temp_area = A[temp] * (s.empty() ? i : i - s.top() - 1);

        if(temp_area > area_max)
            area_max = temp_area;
    }
    return area_max;
}

int findLargest(VV &A)
{
    /*
    If the matrix is editable, then
    we change the matrix to have the height of the vertical bar
    at that present cell, mentioned at that cell itself
    i.e. we will preprocess the given matrix.
    eg: 0 1 1                0 1 1
        1 2 0                1 1 0
        2 3 0 instead of    1 1 0
    
    else
    we need to check the height of the vertical bar, at the present cell.
    */
    preprocess(A);
    int area_max = INT_MIN;
    for(int i = 0; i<A.size(); i++)
    {    
        area_max = max(area_max, findLargest_Util(A[i]));
    }
    return area_max;

}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    return findLargest(A);
}
