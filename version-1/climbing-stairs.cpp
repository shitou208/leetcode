/***
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
**/
//重要思想：递归！！！！！
//上n阶，可以看作是在上了n-1阶的基础上再上一阶，或者是在n-2阶基础上直接上两阶
int climbStairs(int n) {
   
   //可以用递归思想解决，但超出时间限制
   /*
   if(n==0||n==1) {return n?1:0;}
   if(n==2) {return 2;}
   return climbStairs(n-1)+climbStairs(n-2);
   */
   //递归本质就是：s(n)=s(n-1)+s(n-2),也就是斐波那契数列
   if(n==0||n==1) {return n?1:0;}
   if(n==2) {return 2;}
   int sum[n];//why?为什么可以把数组大小用变量指明
   sum[0]=1;
   sum[1]=2;
   for(int i=2;i<n;i++){
   	sum[i]=sum[i-1]+sum[i-2];
   }
   return sum[n-1];
}