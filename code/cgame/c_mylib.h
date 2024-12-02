/*
===========================================================================

为了方便汉化，一些特殊的字符串操作函数将在该文件中声明。

===========================================================================
*/

#ifndef C_MYLIB_H
#define C_MYLIB_H


int c_isStrAllSpaces( const char *str );
char *c_strcut( const char *string, int start, int length );
char *c_strcutpy( const char *string, int start, int end );
char *c_strcutn( const char *string, int start, int n );
float c_atoif( const char *string );
int c_strchk( char c, const char *string );
int c_intlen( int num );
char *c_strmap( const char *string );


#endif
