/*
 * Copyright(C) 2012, Tim Detwiler <tdetwile@andrew.cmu.edu>
 * Copyright(C) 2012, Tim Shields <tshield1@andrew.cmu.edu>
 *
 *  This file is part of the Timix Kernel.
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
#ifndef TIMIX_STRING_IMPL_H_
#define TIMIX_STRING_IMPL_H_

#include <string.h>

static inline char *_strcat(char *str1, const char *str2)
{
    while (*str1) str1++;
    while ((*str1++ = *str2++));

    return str1;
}

static inline int _strlen(const char *s)
{
    register int len=0;

    while (s[len]) len++;

    return len;
}

static inline char* _strcpy(char *dest, const char *src)
{
    while ((*dest++ = *src++) != '\0');

    return dest;
}

static inline char* _strncpy(char *dest, const char *src, size_t n)
{
    register int i = 0;

    while ((*dest++ = *src++) != '\0' && i++ < n);

    return dest;
}

static inline char *_strdup(const char *s)
{
    register char *new;

    new = (char*)malloc(_strlen(s));
    if (new)
      _strcpy(new, s);

    return new;
}

static inline int _strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2++ && *s1);

    return *s1 - *s2;
}

static inline int _strncmp(const char *s1, const char *s2, size_t n)
{
    register int i = 0;

    while (*s1 == *s2 && i++ < n);

    return *s1 - *s2;
}

static inline void *_memset(void *to_, int c, size_t len)
{
    register char* to = to_;

    while(len-- > 0)
      *to++ = c;

    return to_;
}

static inline char *_strtok(char *str, const char *delim)
{
    static char *tok;
    register char* delimp;
    char *ret;
    int  c;

    if (str) tok = str;
    if (!tok) return NULL;

    //
    // Find start of token
    //
find_tok:
    c = *tok++;
    for (delimp=delim; *delimp; delimp++) {
        if (c == *delimp)
            goto find_tok;
    }
    ret = tok-1;

    //
    // Find end of token
    //
    do {
        for (delimp=delim; *delimp; delimp++) {
            if (c == *delimp) {
                *(tok-1) = '\0';
                return ret;
            }
        }
    } while((c = *tok++));

    tok = NULL;
    return ret;
}

static inline const char *_strchr(const char *s_, int c_)
{
    register const char *s = s_;
    register int x, c = c_;

    while ((x = *s++)) {
        if (x == c) return s-1;
    }

    return NULL;
}

#endif // TIMIX_STRING_IMPL_H_
