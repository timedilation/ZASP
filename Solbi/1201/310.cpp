class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1){
            return vector <int> (1, 0);
        }
        
        vector <set <int> > neighbors(n);
        
        for(auto &edge : edges){
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }
        
        vector <pair<int, int> > buff;
        
        while(1){
                
            int cnt = 0;
            for(auto &n : neighbors){
                if(n.size() > 0){
                    cnt++;
                }
            }
            if(cnt <= 2){
                break;
            }
            
            buff.clear();
            for(int i = 0; i< n; ++i){
                if(neighbors[i].size() == 1){
                    int j = *(neighbors[i].begin());
                    buff.push_back(make_pair(j, i));
                    neighbors[i].clear();
                }
            }
            
            cnt = 0;
            for(auto &n : neighbors){
                if(n.size() > 0){
                    cnt++;
                }
            }
            if(cnt <= 2){
                break;
            }
             
            for(auto &b: buff){
                neighbors[b.first].erase(b.second);
            }
        } 
        
        vector <int> answer;
        for(int i = 0; i< n; ++i){
            if(neighbors[i].size() > 0){
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};