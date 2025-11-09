class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        if((num1==0) || (num2==0)) return 0; 
        while(true){
            if(num1 >= num2){
                num1 = num1-num2;
                cnt++;
            } 
            else{
                num2 = num2-num1;
                cnt++;
            } 
            if((num1 == 0) || (num2 ==0)) break;
        }
        return cnt;
    }
};
