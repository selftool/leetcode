#include <iostream>
#include <string>
using namespace std;  
/*�������ԭ����΢��绰���Ե�ʱ�������ˣ�������leetcode��Ҫȥ���ǲ�ֻ��26��Ӣ����ĸ������Ҫ����һЩ�ɴ�ӡ���ַ���
��ˣ�����ҽ���־����Ĵ�С���䵽��256����Ϊascii���Ҳ��ֻ��256���ַ���
���ܹ���ӡ���ַ��Ǵӿո�space����ʼ�ģ��ո��asciiֵ��32,����С�ġ� 
*/

int lengthOfLongestSubstring(string s) 
{
     int f[256];//���������־���������һ����ĸ�Ƿ���ֹ������Ե�ʱ����ǿ��������ˣ�֮ǰ���ñ�������� 
     int  i, j;
     for(i = 0; i < 256; i++)
     {
           f[i] = 0;
     }
     int  maxi = 0, maxlen = 1;//��������ظ��ִ��Ŀ�ͷλ�ã����� 
     int  len = s.size();
     if (len <= 0)
        return len; 
     i = 0;
     f[ s[i]-' ' ] = 1;
     j = i + 1;
     while (j < len)
     {
           if ( f[ s[j]-' ' ] == 0 )
           {
                f[ s[j]-' ' ] = 1;
                if (j-i+1 > maxlen)
                {
                        maxlen = j-i+1;
                        maxi = i;
                }
                j++; 
           }
           else
           {
               while (s[i] != s[j] )
               {
                     f[ s[i]-' ' ] = 0;
                     i++;
               }
               i++;
               j++;
           }
     }
     /* 
     for (i = maxi; i < maxi+maxlen; i++)
     {
         printf("%c", s[i]);
     }
     printf("\n");
     */
     return maxlen;
}

int main()
{
    //string s = "abcdedabcdef";
    string s = "aaaaa"; 
    cout << lengthOfLongestSubstring(s) << endl;
    
    system("pause");
    return 0;
}
