#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
/*
�����û��Ҫ�����Ǵ����쳣��������so easy��
1.����ע�⣺�������ǡ�-�������ǡ�/����ʱ��ע���ջ������Ԫ�أ�Ҫ�������op2-op1��������op1-op2. 
2.�����Ŀ��չһ�£�����ȥѧϰ��ν�һ����׺���ʽת����һ����׺���ʽ 
*/
using namespace std;

int evalRPN(vector<string> &tokens) 
{
    int i = 0;
    int len = tokens.size();
    stack<int> number;
    for (i = 0; i < len; ++i)
    {
        int op1, op2, op3;
        if (tokens[i] == "+")
        {
             //if (number.size() < 2) break;
             op1 = number.top();
             number.pop();
             op2 = number.top();
             number.pop();
             op3 = op2 + op1;
             number.push(op3); 
             //cout << op3 << "=" << op1 << "+" << op2 << endl;
        }
        else if (tokens[i] == "-")
        {
             //if (number.size() < 2) break;
             op1 = number.top();
             number.pop();
             op2 = number.top();
             number.pop();
             op3 = op2 - op1;
             number.push(op3); 
             //cout << op3 << "=" << op1 << "-" << op2 << endl;
        }
        else if (tokens[i] == "*")
        {
             //if (number.size() < 2) break;
             op1 = number.top();
             number.pop();
             op2 = number.top();
             number.pop();
             op3 = op2 * op1;
             number.push(op3); 
             //cout << op3 << "=" << op1 << "*" << op2 << endl;
        }
        else if (tokens[i] == "/")
        {
             //if (number.size() < 2) break;
             op1 = number.top();
             number.pop();
             op2 = number.top();
             number.pop();
             op3 = op2 / op1;
             number.push(op3); 
             //cout << op3 << "=" << op1 << "/" << op2 << endl;
        }
        else //if (tokens[i] >= "0" && tokens[i] <= "9")
        {
             //number.push((int)tokens[i]);//atoi()
             number.push( atoi( tokens[i].c_str() ) );
        }
        /*
        else
        {
            break;
        }*/
    }
    if (number.size() == 1 && i == len)
    {
        int result = number.top();
        number.pop();
        return result;
    }
}

int main()
{
    //tokens = ["4", "13", "5", "/", "+"]
    string tokens[] = {"4", "13", "5", "/", "+"};
    size_t tokens_count=sizeof(tokens)/sizeof(string);
    vector<string> vec(tokens, tokens+tokens_count);
    
    int result = evalRPN(vec);
    cout << result << endl;
    
    system("pause");
    return 0;
}
