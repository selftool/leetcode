#include "iostream"
#include "string"
using namespace std;

class Solution {
public:
	//���������Ϊ���Ĺ��ܣ�����һ���ַ�����ȫ��ת��
	//�ո�����reverseWords������ʵ�� 
    void reverseCore(string &s, int l, int r)
	{
		int i = l;
		int j = r;
		while(i < j)
		{
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
		}
	}
void reverseWords(string &s)
{
	//cout << s << endl;
	reverseCore (s, 0, s.length()-1);
	//cout << s << endl;
	 
	int i, j = 0; //����ָ�룬�ֱ��¼һ���������ߵĿո�λ��
	while (i < s.length())
	{
		if (s[i] == ' ')
		{
			i++;
			j++;
		}
		else if (j == s.length() || s[j] == ' ')
		{
			int l = i;
			int r = j-1;
			reverseCore(s, l, r);
			i = j++;
		}
		else
		{
			j++;
		}
	}
	//���ｫ�м����Ŀո����
	string rs;
	for (i = 0; i < s.length(); ++i)
	{
		int space;
		if (s[i] == ' ')
		{
			space = 1;
			continue;
		}
		if (space == 1)
		{
			rs += " " ;
			rs += s[i];
			space = 0;
		}
		else
		{
			rs += s[i];
		}
	}
	s = rs;
	//cout << s << endl;
	//
	i = 0;
	j = s.length()-1;
	//cout << i << "," << j <<endl;
	while ( i <= s.length()-1 )
	{
		if (i == s.length()-1)
		{
			break;
		}
		if (s[i] == ' ')
		{
			i++;
		}
		else
		{
			break;
		}
	}
	//cout << i << endl;
	while ( j >= 0 )
	{
		if (j == 0)
			break;
		if (s[j] == ' ')
		{
			j--;
		}
		else
		{
			break;
		}
	}
	//cout << j << endl;
	
	rs = "";
	while (i <= j)
	{
		rs += s[i++];	
	}
	s = rs;
	//cout << s << endl;
}
};
/*��Ŀ��Ҫ��
1.��������Կո�ͷ���߽�β
2.���ʱ����ͷ����β����Ϊ�ո񣻶���ո�����Ϊһ���ո�
3.�����ţ����ı�λ�� ???�ڱ��ض����Ѿ�����ȷ���ˣ�����Ϊɶ����ȥ˵����hi����������ǡ���ih�� ���Լ��������ܵĽ�����ǡ�hi������ 
*/
int main()
{
	//string s = " the  sky is blue  ";
	string s = "hi!";
	//cout << s.length() << endl;
	Solution* mySolution =  new Solution(); 
	mySolution->reverseWords(s);
	cout << s << endl;
	
	return 0;
} 
