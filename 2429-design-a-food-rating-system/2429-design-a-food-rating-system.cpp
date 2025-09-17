struct Comp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first == b.first) {
            return a.second > b.second; 
        }
        return a.first < b.first; 
    }
};

class FoodRatings {
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Comp>> cuisineToHeap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToHeap[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        foodToRating[food] = newRating;
        cuisineToHeap[cuisine].push({newRating, food});
    }

    string highestRated(string cuisine) {
        auto& pq = cuisineToHeap[cuisine];
        while (!pq.empty()) {
            auto [rating, food] = pq.top();
            if (foodToRating[food] == rating) {
                return food;
            }
            pq.pop(); 
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */