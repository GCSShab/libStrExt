#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

 int length(char *str);
 void toUpperCase(char *str);
 bool isEmpty(char *str);
 char charAt(char *str,int index);
 void toLowerCase(char *str);
 void capitalize(char *str);
 void double_quotes(const char *input, char *output);
 void pad_left_zeros(const char *input, char *output, int total_length);
 void pad_right_zeros(const char *input, char *output, int total_length);
 void convert_date_format(const char *input, char *output);
 void replace(char *str, char from, char to);
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
 int indexOf(char *str, char *rch);
 int lastIndexOf(char *str, char *rch);
 void replaceAll(char *str, const char *src, const char *dst);
 void replaceFirst(char *str, const char *src, const char *dst);
 bool contains(const char *str, const char *find);
 bool isBlank(const char *str);
 char *repeat(char c, int nb);
 char **splitWithDelimiters(const char *str, char separateur);
 void strip(char *str);


#endif // TOOLS_H_INCLUDED
