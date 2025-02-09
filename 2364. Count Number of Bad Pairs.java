class Solution {
    public long countBadPairs(int[] nums) {
      long badPairs = 0;
      Map<Integer,Integer> diffCount = new HashMap<>();
      for(int pos = 0;pos<nums.length;pos++){
        int diff = pos-nums[pos];
        int goodPairCount = diffCount.getOrDefault(diff,0);
        badPairs += pos-goodPairCount;
        diffCount.put(diff,goodPairCount+1);
      }
      return badPairs;  
    }
}
