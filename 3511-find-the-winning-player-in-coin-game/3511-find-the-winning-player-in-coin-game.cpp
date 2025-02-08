class Solution {
public:
    string winningPlayer(int x, int y) {
        int turn=0;
        while(true){
            if(x>0 && y>=4){
                x=x-1;
                y=y-4;
                turn++;
            }
            else break;
        }        
        if(turn%2==0) return "Bob";
        return "Alice";
    }
};