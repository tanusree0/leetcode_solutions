class Solution {
public:
//we have to maintain longest increasing order
    int maxEnvelopes(vector<vector<int>>& a) {
      sort(a.begin(),a.end(),[](const vector<int>&p, const vector<int>&q){
           if(p[0]==q[0]) return p[1]>q[1]; // same width -> higher height first
            return p[0]<q[0]; // otherwise sort by width
      });
       vector<vector<int>>temp;
      int x=a[0][0]; int y=a[0][1];
      temp.push_back({x,y});
      for(int i=1;i<a.size();i++){
         int p=a[i][0]; int q=a[i][1];
         vector<int>curr={p,q};
         if(curr[0]>temp.back()[0] && curr[1]>temp.back()[1]){
            temp.push_back(curr);
         }else {
            int j=lower_bound(temp.begin(),temp.end(),curr, [](const vector<int>&x,const vector<int>&y){
                return x[1]<y[1];
            })-temp.begin();
            temp[j]=curr;
         }
      }
      return temp.size();
    }
};
