class MyQueue {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = q.front();
        q.pop();
        
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return q.front();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(!q.empty())
            return false;
        
        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */