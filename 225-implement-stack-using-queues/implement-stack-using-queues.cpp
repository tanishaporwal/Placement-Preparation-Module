class MyStack {
private:
    deque<int>dq; //declare the deque in private scope
public:
    MyStack() {
    }
    
    void push(int x) {
        dq.push_back(x); //in deque u can push_front or push_back (here we will push_back for stack like usage)
    }
    
    int pop() {
        int x =  dq.back(); //store the back element in a variable
        dq.pop_back(); //remove the back element (top of stack)
        return x; //return the variable
    }
    
    int top() {
        return dq.back(); 
    }
    
    bool empty() {
        return dq.empty(); // check if deque is empty!
    }
};