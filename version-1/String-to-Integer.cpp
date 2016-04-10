/*
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

int myAtoi(char *str)
{
  int size = strlen(str);
    int i = 0, j = 0, sum = 0;
    char temp[] = "2147483648";
    int flag = 0;
    /*字符串转为整数，输入存在以下几种情况*/
    //1、首字符是除整数外的其他字符,或者字符串为空，返回0
    //2、考虑最后得到的整数不能超出最大整数范围,如果超过，就返回+-上限的最大值，
    //   正数为+2147483647，负数为-2147483648（负数多1）
    //3、如果首字符是+-号，那么视为有效字符，而且+-可以抵消
    //4、如果前面有连续空字符

    if(size == 0 || !(str[0] <= '9' && str[0] >= '0'))
    {
        if(str[0] != '+' && str[0] != '-'&&str[0]!=' ')
        {
            return 0;
        }
        else
        {
            //如果首字符是+或-，则视为有效字符
            
            //如果连续出现+-，retrun 0
            if(size >= 2)
            {
                if(str[0] == '+' && str[1] == '-')
                {
                    return 0;
                }
                if(str[0] == '-' && str[1] == '+')
                {
                    return 0;
                }
            }
            //如果是连续空字符
            while(str[0]==' '){
            	str=str+1;
            }

            if(str[0] == '+')
            {
                flag = 1;
                str = str + 1;
            }
            if(str[0] == '-')
            {
                flag = -1;
                str = str + 1;
            }
            while(i < size && str[i] >= '0' && str[i] <= '9')
            {
                if(i > 9)
                {
                    return 0;
                }
                if(i == 9)
                {
                    while(j < 10)
                    {
                        if(str[j] < temp[j])
                        {
                            j++;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
                sum = sum * 10 + (int) str[i] - 48;
                i++;
            }
            return flag == -1 ? -sum : sum;
        }
    }
    else{
         while(i < size && str[i] >= '0' && str[i] <= '9')
            {
                if(i > 9)
                {
                    return 0;
                }
                if(i == 9)
                {
                    while(j < 10)
                    {
                        if(str[j] < temp[j])
                        {
                            j++;
                        }
                        else
                        {
                            return 2147483647;
                        }
                    }
                }
                sum = sum * 10 + (int) str[i] - 48;
                i++;
            }
            return flag == -1 ? -sum : sum;
    }
}