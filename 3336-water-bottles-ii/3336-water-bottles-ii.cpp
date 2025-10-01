class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrank = numBottles;   
        int empties = numBottles;    
    
         while (empties >= numExchange) {
  
        empties -= numExchange;
        totalDrank++;  
        empties++;     
        numExchange++;  
        }
    
    return totalDrank;
    }
};