#include <iostream>
#include <vector>
using namespace std;
/*���������
1.��0��β
2.�������������ʱ�����������ֵ�͸��������ֵ���ܲ���һ����
*/
int reverse(int x)
{
    int int_max = 0X7FFFFFFF;
    int int_min = -int_max-1;
    //cout << int_max << "," << int_min << endl;
    int sign = (x >= 0)? 1 : -1 ; 
    unsigned int y = (x >= 0)? x : -x ;
    vector<int> number;
    while (y)
    {
        number.push_back(y%10);
        y = y/10;
    }
    unsigned int result = 0; //��Χ��0���� 0x FF FF FF FF
    for (int i = 0; i < number.size(); i++)
    {
        //cout << number[i] << "  ";
        result = 10 * result + number[i];//�����Զ������˿�ͷΪ0�����
        //���Խ��
        if (result >= int_max)
        {
        	if (sign == -1)
        		if (result == int_max+1)
            		return sign*result;
            	else
            		return int_min;
            else
            	return int_max;
        }
    }
    
    //cout << endl;
    //�ж��Ƿ����int_max
    return result*sign;
}
 
int main()
{
    int x = -1230028902999;
    int result = reverse(x);
    cout << result << endl; 
    
    return 0;
}
