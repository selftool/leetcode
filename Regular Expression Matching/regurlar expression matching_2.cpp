/**
 * c����û��bool���ͣ�ֻ��c++������
 * ���������õݹ���������ͻ�д������lengthy���룬����һ��bug 
**/

#include <stdio.h>
#include <string.h>

bool isMatch(const char *s, const char *p) {
	if (*p == '\0') return *s == '\0';
	if (*(p+1) != '*'){
		if (*s != '\0' && (*s == *p || *p == '.') ){
			return isMatch(s+1, p+1); 
		}
		else {
			return false;
		}
	}
	else {  // *(p+1) == '*'
		if (*s != '\0' && (*p == *s || *p == '.')) {
			while (*s != '\0' && (*p == *s || *p == '.')) {
				if (isMatch(s, p+2)) {
					return true;
				} 
				s++;
			}
			return isMatch(s, p+2); 
		}
		else {
			return isMatch(s, p+2);
		}
	}
} 

int main(){
	char* s = "aaa";
	char* p = "a*a"; 
	
	if (isMatch(s, p)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
	
	return 0;
}
 
