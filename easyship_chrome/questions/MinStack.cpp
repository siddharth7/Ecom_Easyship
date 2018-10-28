  stack<int> s1;
stack<int> min_stk;

MinStack::MinStack() {
    while(!s1.empty())
        s1.pop();
    while(!min_stk.empty())
        min_stk.pop();
}

void MinStack::push(int x) {
    s1.push(x);
    if(min_stk.empty())
        min_stk.push(x);
    else
    {
        if(x < min_stk.top())
            min_stk.push(x);
        else
            min_stk.push(min_stk.top());
    }
}

void MinStack::pop() {
    if(s1.empty())
        return;
    s1.pop();
    min_stk.pop();
}

int MinStack::top() {
    if(s1.empty())
        return -1;
    return s1.top();
    
}

int MinStack::getMin() {
    if(s1.empty())
        return -1;
    return min_stk.top();
    
}

