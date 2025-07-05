class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> map;
        for(auto it : arr)
        {
            map[it]++;
        }
        int count =-1; 
        for(auto x : map)
        {
            if(x.first == x.second)
            {
                count = max(count,x.first);
            }
        }
        return count;


    }
};