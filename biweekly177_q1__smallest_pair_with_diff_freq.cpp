class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {

        if(nums.size()<2){
            return {-1,-1};
        }
        
        sort(nums.begin(),nums.end());

        vector<pair<int,int>> val_freq;//val, freq
        //(1,2),(2,2),(3,1),(4,1)
        int cnt=1;
        
        for(int i=1;i<=nums.size();i++){
            if(i==nums.size()||nums[i]!=nums[i-1]){
                val_freq.push_back({nums[i-1],cnt});
                cnt=1;
            }else{
                cnt++;
            }
        }

        int len=val_freq.size();
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(val_freq[j].second!=val_freq[i].second){
                    return {val_freq[i].first, val_freq[j].first};
                }
            }
        }

        return {-1,-1};
    }
};
