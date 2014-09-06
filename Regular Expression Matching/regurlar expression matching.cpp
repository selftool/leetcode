/*
** Regular Expression Matching
** 1����pֻ�������ַ���ʱ��s==p����true
** 2����pֻ����*ʱ�� sֻ���� 
Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "a*") �� true
isMatch("aa", ".*") �� true
isMatch("ab", ".*") �� true
isMatch("aab", "c*a*b") �� true

����2Сʱ�󣬷��ֵݹ���ǺõĽⷨ 
*/ 

#include <stdio.h>
#include <string.h>

using namespace std;

bool isMatch(const char *s, const char *p) {
	int s_len = strlen(s);
	int p_len = strlen(p);
	if (s_len == 0) return true;
	if (s_len != 0 && p_len == 0) return false; 
	
	for (int i = 0; i < p_len; i++) {
		if (*(p+i) == '.' || *(p+i) == *s ) {
			int k = i;
			int j = 0;
			for (j = 0; j < s_len; j++) {
				if (k < p_len) {
					if(*(s+j)==*(p+k) || *(p+k)== '.'){
						k++;
					}
					if (*(p+k)=='*' && k > 0) {
						if (*(p+k-1)=='.' ) {
							return true;
						} 
						if (*(p+k-1)==*s) {
							// ���s�ǲ���һ��"aaaaa...."�ͣ����￼�����д���� 
							int m = 0;
							for(m = 0; m < s_len-1; m++) {
								if (*(s+m)!=*(s+m+1)) {
									break;
								}
							} 
							if (m == s_len-1) {
								return true;
							}
							else {
								return isMatch(s+m+1, p+i+1);
							}
						}
					} 
				} 
				else {
					break;
				}
			}
			if (j == s_len) {
				return true;
			}
			else {
				return false;
			}
		}
		
		if (*(p+i) == '*' && i > 0 ) {
			if (*(p+i-1)=='.') {
			 	return true;
			} 
			if (*(p+i-1)==*s) {
				// ���s�ǲ���һ��"aaaaa...."�ͣ�
				// ���￼�����д���ģ�Ӧ���ǿ���s�ǲ���"aaaa...b"�� 
				int m = 0;
				for(m = 0; m < s_len-1; m++) {
					if (*(s+m)!=*(s+m+1)) {
						break;
					}
				} 
				if (m == s_len-1) {
					return true;
				}
				else {
					//����Ӧ�ÿ�ʼƥ��"...b"�Ĳ����� 
					return isMatch(s+m+1, p+i+1);
				}
			}
		}
	}
	return false; 
}

int main(){
	char* s = "aab";
	char* p = "c*a*b"; 
	if (isMatch(s, p)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
	
	return 0;
}
