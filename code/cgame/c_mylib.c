/*
===========================================================================

为了方便汉化，一些特殊的字符串操作函数将在该文件中定义。

===========================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "c_mylib.h"


// 判断字符串是否全为空格
int c_isStrAllSpaces( const char *str ) {
    while (*str) {
        if (!isspace(*str)) {
            return 0;
        }
        str++;
    }

    return 1;
}


// 字符串切片函数
char *c_strcut( const char *string, int start, int length ) {
	int len = strlen(string);
	char *back = (char *) string;
	if (start < 0 || start >= len || length <= 0) {
		// return NULL;
		return back;
	}

	char *result = (char *)malloc(length + 1);
	if (result == NULL) {
		// return NULL;
		return back;
	}

	strncpy(result, string + start, length);
	result[length] = '\0';

	return result;
}


// 字符串切片函数，类似python索引可取负数
char *c_strcutpy( const char *string, int start, int end ) {
	int len = strlen(string);
	char *back = (char *) string;
	if (start > len || end > len || start < -len || end < -len) {
		printf("Out of Index!");
		// return NULL;
		return back;
	}


	if (start < 0) {
		start = len + start;
	}
	if (end < 0) {
		end = len + end;
	}
	if (start > end) {
		int t;
		t = start;
		start = end;
		end = t;
	}


	int length = end - start + 1;
	char *result = (char *)malloc(length + 1);
	if (result == NULL) {
		printf("Failed to Apply for Memory!");
		// return NULL;
		return back;
	}

	//if (start == end) {
	//	strncpy(result, string + start, 1);
	//	return result;
	//}

	strncpy(result, string + start, length);
	result[length] = '\0';

	return result;
}


// 字符串间隔切片
char *c_strcutn( const char *string, int start, int n ) {
	int len = strlen(string);
	int s;
	char *back = (char *) string;
	if (start > len || start < -len) {
		printf("Out of Index!");
		// return NULL;
		return back;
	}

	if (start < 0) {
		start = len + start;
	}
	if (n == 0) {
		return c_strcut(string, start, len - start);
	}

	if (n < 0) {
		s = len / -n;
	} else {
		s = len / n;
	}

	int index;
	char *c;
	char *result = (char *)malloc(s + 1);
	sprintf( result, "%c", string[start] );

	index = (start + n) % len;
	for (int i = 1; i < s; i++) {
		c = c_strcutpy(string, index, index);
		sprintf( result, "%s%s", result, c );
		index = (index + n) % len;
	}


	return result;
}


// 数值字符串转浮点数值（字符串中含'.'）
float c_atoif( const char *string ) {
	int sign, c;
	float value, cof_1, cof_2;
	const char *str = string;

	while ( *str <= ' ' ) {
		if ( !*str ) {
			return 0.0;
		}
		str++;
	}

	if ( *str ) {
		switch ( *str ) {
			case '+':
				sign = 1;
				str++;
				break;
			case '-':
				sign = -1;
				str++;
				break;
			default:
				sign = 1;
				break;
		}
	} else {
		return 0.0;
	}

	value = 0.0;
	cof_1 = 10.0;
	cof_2 = 1.0;
	while (1) {
		if ( *str ) {
			c = *str;
			if ( c >= '0' && c <= '9' ) {
				c -= '0';
				value = (cof_1 * value) + (cof_2 * c);
			}
			if ( c == '.' || cof_1 == 1.0) {
				cof_1 = 1.0;
				cof_2 *= 0.1;
			}
		} else {
			break;
		}
		str++;
	}

	return value * sign;
}


// 检测函数中某字符，并返回其索引，否则返回-1
int c_strchk( char c, const char *string ) {
	int len = strlen(string);
	int i = 1, index = -1;
	char *back = (char *) string;
	char *p = back;

	while ( *p != '\0' ) {
		index = i;
		if ( *p == c ) {
			index = i - 1;
			break;
		} else if (i >= len) {
			index = -1;
			break;
		}

		i++;
		p++;
	}

	return index;
}


// 数字长度
int c_intlen( int num ) {
	int length = 0;
	int n = num;

	if (n<=0) {
		length += 1;
	}

	while (n != 0) {
		n /= 10;
		length++;
	}

	return length;
}


// 字符串简单映射
char *c_strmap( const char *string ) {
	char *p;
	int c, sum, mean, len;
	char *back = (char *) string;

	len = strlen(string);
	p = back;
	sum = 0;
	while ( *p != '\0' ) {
		c = *p - ' ';
		sum += c;
		p++;
	}

	mean = sum / len;
	char *result = (char *)malloc(c_intlen(sum) + c_intlen(mean) + 1);
	if (result == NULL) {
		return back;
	}
	// result = itoa( temp );
	sprintf( result, "%d%d", sum, mean);

	return result;
}
