class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         int n = position.size();
    vector<pair<int, double>> cars; 
    
    for (int i = 0; i < n; i++) {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }
    sort(cars.rbegin(), cars.rend());
    int fleets = 0;
    double cur = 0.0;
    
    for (auto& car : cars) {
        if (car.second > cur) { 
            fleets++;
            cur = car.second;
        }
    }
    return fleets;
    }
};