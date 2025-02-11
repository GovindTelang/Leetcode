class Solution {
    public String removeOccurrences(String s, String part) {
        while(s.contains(part)){
            int partStartInd = s.indexOf(part);
            s = s.substring(0,partStartInd)+s.substring(partStartInd+part.length());
        }
        return s;
    }
}
