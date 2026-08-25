class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n = nums.size();
      unordered_set<int>st;
      if(n==0) return 0;
      for(int i =0;i<n;i++){
        st.insert(nums[i]);
      }
      int longest = 1;
      for(auto it :st)
       {
         if(st.find(it-1)==st.end())
         {
           int count =1;
           int x =it;
           while(st.find(x+1)!=st.end())
           {
               x=x+1;
               count++;
            }
           longest = max(longest,count);
          }
        } 
        return longest;
    }
};