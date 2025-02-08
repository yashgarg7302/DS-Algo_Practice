class NumberContainers {
public:
    unordered_map<int, int> nums;
    unordered_map<int, set<int>> indices;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(nums[index])
            indices[nums[index]].erase(index);
        nums[index] = number;
        indices[number].insert(index);
    }
    
    int find(int number) {
         if(indices.find(number) != indices.end())
        {
            if(*indices[number].begin() != 0)
                return *indices[number].begin();
        }
        
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */