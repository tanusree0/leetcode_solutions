class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
       vector<int>dp(n,1);
       for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(a[prev]<a[i]){
                dp[i]=max((1+dp[prev]),dp[i]);
            }
        }
       }
       int maxi=1;
       for(int i=0;i<n;i++){
        maxi=max(maxi,dp[i]);
       }
       return maxi;
    }
};
