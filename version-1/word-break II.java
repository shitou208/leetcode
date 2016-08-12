/*
��������DP�����Ĵ���ʵ�ʸ��Ӷȶ����ߣ�������˵���޷�AC��TLE����
ԭ����LeetCode����һ���ǳ�tricky�Ĳ���case����ʵ�ǲ���break�ģ�
�����ֺܳ������ִ����ļ�¼�ͻ��ݣ����һ��ͨ������Ľⷨ�ǰ�Word Break����һ�飬
�ж��ǲ�����break�����������������Ĵ��롣����������ʵ�Ƚ�ɵ������Ϊ�˹����ֻ�������ˣ�
��һ���Ҿ���LeetCodeû��Ҫ�ѳ�ʱ�����ô�ϸ�ʵ�����岻��ֻ�ǰ�AC�ʸ�������������
*/


public class Solution {
    public List<String> wordBreak(String s, Set<String> wordDict) {
          ArrayList<String> ay=new ArrayList<String>();
          //�ж�ֻ��һ��Ԫ�ص����
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
        // ��̬�滮˼�룬��ǰ����
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