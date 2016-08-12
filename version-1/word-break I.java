public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        // 动态规划思想，从前往后
		int len = s.length();
		boolean[] dp=new boolean[len];
		dp[0]=wordDict.contains(s.charAt(0)+"");
		for(int i=1;i<len;i++){
			if(wordDict.contains(s.substring(0,i+1))){
				dp[i]=true;
				continue;
			}			
			for(int j=0;j<i;j++){
				if(dp[j] && wordDict.contains(s.substring(j+1, i+1))){
					dp[i]=true;
					break;
				}
			}
		}
        return dp[len-1];
    }
}