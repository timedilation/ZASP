class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        vector <int> answer(T.size());
        stack <int> stk;
        
        for(int i = 0; i< T.size(); ++i){
            while(!stk.empty()){
                if(T[stk.top()] >= T[i]){
                    break;
                } else{
                    answer[stk.top()] = i - stk.top();
                    stk.pop();
                }
            }
            stk.push(i);
        }
        while(!stk.empty()){
            answer[stk.top()] = 0;
            stk.pop();
        }
        
        return answer;
    }
};
