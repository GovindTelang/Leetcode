class Solution {
    private int calculateDigitSum(int num){
        int digitSum = 0;
        while(num>0){
            digitSum += num%10;
            num /= 10;
        }
        return digitSum;
    }
    public int maximumSum(int[] nums) {
        Pair<Integer,Integer> [] digitSumPairs = new Pair[nums.length]; //.length is a method of arrays class                                         //class ka naam toh Pair hi hain
        for(int i=0;i<nums.length;i++){
            int digitSum = calculateDigitSum(nums[i]);
            digitSumPairs[i] = new Pair<>(digitSum,nums[i]);
        }
        Arrays.sort(digitSumPairs,Comparator.comparing(Pair<Integer,Integer> :: getKey).thenComparing(Pair<Integer,Integer>::getValue));
        int ans = -1;
        for(int ind = 1;ind<digitSumPairs.length;ind++){
            int currsum = digitSumPairs[ind].getKey();
            int presum = digitSumPairs[ind-1].getKey();
            //if two consecutive have the same digit sum
            if(currsum == presum){
                int currentSum = digitSumPairs[ind].getValue()+digitSumPairs[ind-1].getValue();
                ans = Math.max(ans,currentSum);
            }
        }
        return ans;
    }
}
