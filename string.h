/*
 * Copyright(C) 2012, Tim Detwiler <tdetwile@andrew.cmu.edu>
 * Copyright(C) 2012, Tim Shields <tshield1@andrew.cmu.edu>
 *
 *  This file is part of the Timix.
 *
 *  Timix is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Timix is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Timix. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef TIMIX_STRING_H_
#define TIMIX_STRING_H_

#include <stdlib.h>

size_t strlen(const char *str);
char *strcpy(const char *str1, const char *str2);
char *strncpy(const char *str1, const char *str2, size_t n);
char *strdup(const char *str);
char *strcat(const char *str1, const char *str2);
char *strncat(const char *str1, const char *str2, size_t n);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);
char *strchr(const char *str, int c);
char *strrchr(const char *str, int c);
char *strstr(const char *haystack, const char *needle);
char *strtok(char *str, const char *delim);
char *strpbrk(const char *str1, const char *str2);
size_t strspn(const char *str1, const char *str2);
size_t strcspn(const char *str1, const char *str2);

//
// Memory
//
void *memset(void *to, int c, unsigned int n);
int memcmp(const void *s1v, const void *s2v, int size);
void *memcpy(void *to, const void *from, unsigned int n);
void *memmove(void *to, const void *from, unsigned int n);

//
// BSD
//
char *index(const char *str, int c);
char *rindex(const char *str, int c);
void bcopy(const void *from, void * to, unsigned int n);
void bzero(void *to, unsigned int n);

#endif // TIMIX_STRING_H_
