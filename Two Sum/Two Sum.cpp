#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*���ÿ⺯�����п��ţ�Ȼ�����üбƷ������в��� 
���ǣ���������ͨ���ύ��ȥ��ʱ���Ȼ�� RE �������������� j = num.size()Խ���ˡ����ѵ����dev-c++��鲻�������� 
*/
vector<int> twoSum(vector<int> &numbers, int target) 
{
	vector<int> result;
	vector<int> num = numbers;
	sort(num.begin(), num.end());
	int i = 0;
	int j = num.size()-1;
	while (i < j)
	{
		if ( (num[i] + num[j]) == target )
		{
			int left, right;
			for (int k = 0; k < numbers.size(); ++k)
			{
				if (numbers[k] == num[i])
				{
					left = k + 1;
				}
			}
			for (int k = 0; k < numbers.size(); ++k)
			{
				if (k == left-1)
					continue; 
				if (numbers[k] == num[j])
				{
					right = k + 1;
				}
			}
			if (left < right)
			{
				result.push_back(left);
				result.push_back(right);
			}
			else
			{
				result.push_back(right);
				result.push_back(left);
			}
			break; 
		}
		else if ( (num[i] + num[j]) > target )
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	return result; 
}

/*���������ύ�����ѳ�ʱ 
*/ 
/* 
vector<int> twoSum(vector<int> &numbers, int target) 
{
	vector<int> result;
	for (int i = 0; i < numbers.size(); ++i)
	{
		for (int j = i + 1; j < numbers.size(); ++j)
		{
			if ( (numbers[i] + numbers[j]) == target )
			{
				result.push_back(i+1);
				result.push_back(j+1);
				return result;
			}
		}
	}
	return result; 
}
*/
int main()
{
	vector<int> vec;
	int target = 0;
	vec.push_back(-3);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(90);
	vector<int> result = twoSum(vec, target);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	
	return 0;
} 
