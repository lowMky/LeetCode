//±©Á¦Ä£Äâ O(n^2) ¸´ÔÓ¶È

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        flag=false;
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
    }

    /** Push element x onto stack. */
    void push(int x) {
        if(!flag) q1.push(x);
        else q2.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret;
        if(!flag){
            while(!q1.empty()){
                if(q1.size()==1){
                    ret = q1.front();
                    q1.pop();break;
                }
                q2.push(q1.front());
                q1.pop();
            }
        }
        else{
            while(!q2.empty()){
                if(q2.size() == 1){
                    ret = q2.front();
                    q2.pop();break;
                }
                q1.push(q2.front());
                q2.pop();
            }
        }
        flag=!flag;
        return ret;
    }

    /** Get the top element. */
    int top() {
        int ret;
        if(!flag){
            while(!q1.empty()){
                if(q1.size()==1)
                    ret = q1.front();
                q2.push(q1.front());
                q1.pop();
            }
        }
        else{
            while(!q2.empty()){
                if(q2.size() == 1)
                    ret = q2.front();
                q1.push(q2.front());
                q2.pop();
            }
        }
        flag=!flag;
        return ret;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        if(!flag) return q1.empty();
        else return q2.empty();
    }

    bool flag;
    queue<int> q1,q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
