class Solution {
public:
    int bestTeamScore(vector<int>& s, vector<int>& a) {
      int n=a.size();
      vector<pair<int,int>> play;
      for(int i=0;i<n;i++){
        play.push_back({a[i],s[i]});
      }
      sort(play.begin(),play.end());
         
       vector<int>dp(n);
       int maxi=0;
       for(int i=0;i<n;i++){
         dp[i]=play[i].second;
         for(int prev=0;prev<i;prev++){
            if(play[prev].second<=play[i].second){
                dp[i]=max(dp[i],(dp[prev]+play[i].second));
            }
         }
         maxi=max(maxi,dp[i]);
       }
       return maxi;
    }
};
