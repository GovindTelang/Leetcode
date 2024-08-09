class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {
            {0,1}, //east
            {1,0}, //south
            {0,-1},//west
            {-1,0} //north
        };
        vector<vector<int>> result;
        int dir = 0;  //which direction
        int steps = 0; //how many steps to move
        result.push_back({rStart,cStart});
        while(result.size() < rows*cols){
        if(dir==0 || dir==2) steps++; //when we move east or west we need to increase our steps by one
        for(int i=0;i<steps;i++){
            rStart += directions[dir][0];
            cStart += directions[dir][1];
            if(rStart>=0 && rStart<rows && cStart < cols && cStart>=0){
                result.push_back({rStart,cStart});
            }
        }
        dir = (dir+1)%4 ; //turn to the next direction
        }
        return result;
    }
};
