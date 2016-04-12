/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
int lengthOfLongestSubstring(char *s)
{
    bool flag(char *str, int ii, int jj);
    int length = strlen(s);
    if(length == 0 || length == 1)
    {
        return length ? 1 : 0;
    }
    int i = 0, j, count = 0, result = 0;
    while(i < length)
    {
        j = i;
        while(j < length)
        {
            if(!flag(s, i, j))
            {
                count++;
            }
            else
            {
                result = (result > count) ? result : count;
                count = 0;
                break;
            }
            j++;
        }
        result = (result > count) ? result : count;
        count = 0;
        i++;
        if(result >= (length - i))
        {
            break;
        }
    }
    result = (result > count) ? result : count;
    return result;
}
bool flag(char *str, int ii, int jj)
{
    int n;
    if(ii == jj)
    {
        return false;
    }
    for(n = ii; n < jj; n++)
    {
        if(str[n] == str[jj])
        {
            return true;
            break;
        }
    }
    return false;
}