/*Implement pow(x, n).*/

double myPow(double x, int n) {
    double max= 9223372036854775799;
    double min=-9223372036854775800;
    double result=1;
    bool neg=false;
    bool point=false;
    //检查参数的合法性
    if(n==0) {//实数零次幂为1
    	return 1;
    }
    if(x==0){//分母不能为0
    	return 0;
    }
    if(x==1){
    	return 1;
    }
    if(n>0){
    	if(x>0){
    	 if(x<1){point=true;x=1.0/x;}
         while(n--){
         	result*=x;
         	if(result<0){return point?0:max;}
         }
         
        return point?(1.0/result):result;
     }
     else{
     	if(n%2){neg=true;x=-x;}
     	if(abs(x)<1){point=true;x=1.0/x;}
     	while(n--){
         	result*=x;
         	if(result<0){
         		if(point){return 0;}
         		return neg?min:max;
         	}
         }
        if(point){return 1.0/result;}
        return neg?-result:result;
     }
    }
    else{
    	n=-n;
       	if(x>0){
    	 if(x<1){point=true;x=1.0/x;}
         while(n--){
         	result*=x;
         	if(result<0){return point?max:0;}
         }
         
        return !point?(1.0/result):result;
     }
     else{
     	if(n%2){neg=true;x=-x;}
     	if(abs(x)<1){point=true;x=1.0/x;}
     	while(n--){
         	result*=x;
         	if(result<0){
         		if(!point){return 0;}
         		return neg?min:max;
         	}
         }
        if(!point){return 1.0/result;}
        return neg?-result:result;
     }
    }


}