class Solution {
public:
    int scoreOfParentheses(string S) {
        
        stack <char> stk;
        int answer = 0;
        
        for (auto &c : S){
            
            if(c == '('){
                stk.push(c);
            } else{
                int score = 0;
                bool flag = false;
                
                while(!stk.empty()){
                    
                    if(stk.top() == '('){
                        stk.pop();
                        if(flag){
                            score *= 2; 
                        } else {
                            score = 1;
                        }
                        stk.push(score);
                        break;
                        
                    } else{
                        flag = true;
                        score += stk.top();
                        stk.pop();
                    }
                }
                
            }
        }
        
        while(!stk.empty()){
            answer += stk.top();
            stk.pop();
        }
        
        return answer;
    }
};
