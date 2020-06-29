//leetcode graph problem
//( Reconstruct Itinerary)
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string> >adj;
        vector<string >ans;
        stack<string>s;
        int n=tickets.size();
        for(int i=0;i<n;i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        s.push("JFK");
        while(!s.empty()){
            string ros=s.top();
            if(adj[ros].size()==0){
                ans.push_back(ros);
                s.pop();                
            }
            else{
                auto df=adj[ros].begin();
                s.push(*df);
                adj[ros].erase(df);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;       
    }
};