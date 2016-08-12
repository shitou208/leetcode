/*
暴力法和DP方法的代码实际复杂度都蛮高，据网友说都无法AC（TLE），
原因是LeetCode中有一个非常tricky的测试case，其实是不能break的，
但是又很长，出现大量的记录和回溯，因此一般通过这个的解法是把Word Break先跑一遍，
判断是不是能break，如果可以再跑上面的代码。这样做法其实比较傻，但是为了过这个只能这样了，
这一点我觉得LeetCode没必要把超时设得这么严格，实际意义不大，只是把AC率给拉了下来哈。
*/


public class Solution {
    public List<String> wordBreak(String s, Set<String> wordDict) {
          ArrayList<String> ay=new ArrayList<String>();
          //判断只有一个元素的情况
          if(wordDict.size()==1 && wordDict.contains(s)){
        	  ay.add(s);
          }
          else{
              if(checkwordBreak(s,wordDict)){
                  fun(s,wordDict,"",ay);
              }
          }     
          return ay;
    }
static void fun(String s,Set<String> dict,String profix,ArrayList<String> ay){
		int len=s.length();
		for(int i=0;i<len;i++){
			String temp=s.substring(0, i+1);
			if(dict.contains(temp)){
				if(i==len-1){
					String total=profix.equals("")?temp:profix+" "+temp;
					ay.add(total);
				}else{
					String new_profix=profix.equals("")?temp:profix+" "+temp;
					fun(s.substring(i+1),dict,new_profix,ay);
				}
			}
		}
	}
	static public boolean checkwordBreak(String s, Set<String> wordDict) {
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