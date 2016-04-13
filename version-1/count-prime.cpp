/**
 =============================================
   @Date    : 2016-04-13 09:07:44
   @Author  : shitou
   @Fun     : 统计小于n的质数(素数)个数
   @Version : 1.0
 =============================================
**/

/*最简单原始的算法，检查每个数是否为质数，然后计数。但是超出leetcode的时间限制,O(n*n)*/
int countPrimes(int n) {
	bool isPrime(int num);
    int count=1;
    int j;
    for(j=2;j<n;j++){
    	if(isPrime(j)){
    		count++;
    	}
    }
    return count;
}
bool isPrime(int num){
	int i;
	for(i=2;i<num;i++){
		if(num%i==0){       
			return false;
			break;
		}
	}
	return true;
}

/*改进的算法(符合leetcode的时间限制)*/
int countPrimes(int n) {
    if(n==0||n==1||n==2||n==3){
		return n==3?1:0;
	}
	bool isPrime(int num);
    int count=1;
    int j;
    for(j=3;j<n;j=j+2){//偶数肯定不为质数(2除外)，循环数量减到n/2
    	if(isPrime(j)){
    		count++;
    	}
    }
    return count;
}
bool isPrime(int num){
	int i;
	for(i=3;(i*i)<=num;i=i+2){//判断条件不用一直检查到num，检查到num开平方即可，这样复杂度降为O(n^1.5)
		if(num%i==0){         //判断条件i<=sqrt(num)和i*i<num有和区别？如果使用后者，就会频繁调用sqrt函数，这样也会消耗时间
			return false;
			break;
		}
	}
	return true;
}