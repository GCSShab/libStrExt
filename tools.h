#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

 int length(char *str);
 void to_uppercase(char *str);
 bool isEmpty(char *str);
 char charAt(char *str,int index);
 void to_lowercase(char *str);
 void capitalize(char *str);
 void double_quotes(const char *input, char *output);
 void pad_left_zeros(const char *input, char *output, int total_length);
 void pad_right_zeros(const char *input, char *output, int total_length);
 void convert_date_format(const char *input, char *output);
 void replace_all(char *str, char from, char to);
 char *trim(char *s);
 char *substring(const char *s, size_t from, size_t to);
 char *unquote_and_unescape(char *s);
 void now (char *output);
 char **split(const char *line_in, char separateur);
 bool startWith(const char *str, const char *find);
 bool endWith(const char *str, const char *find);
 bool compareToIgnoreCase(const char *str, const char *compare);
 bool compareTo(const char *str, const char *compare);
 void concat(char *sourceA, const char *sourceB);

 /*
getBytes(String)
indexOf(String)
lastIndexOf(String)
replace(char, char)
contains(CharSequence)
replaceFirst(String, String)
replaceAll(String, String)
split(String, int)
splitWithDelimiters(String, int)
join(CharSequence, CharSequence...)
toLowerCase()
toUpperCase()
strip()
isBlank()
repeat(char,int)
*/

#endif // TOOLS_H_INCLUDED
