/** This header file is written to manage string data safely under C programming language.
* Copyright Tushar Chaurasia 2021 - 2022.
* Commit to this repository at https://github.com/Dark-CodeX/SafeString.git
* You can use this header file. Do not modify it locally, instead commit it on github.com
* File: "sstring.h" under "sstring" directory
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define true 0
#define false 1

typedef struct __str__
{
    /* Do not modify it directly (segfault), most probably and use 'str.destructor(&str);' at the end */
    char *src;
    /* Do not change this value. */
    int init;
} __str__;

typedef struct __string__ string;
struct __string__
{
    /* Do not use this. */
    __str__ str;

    /** Sets `src` to `a`.
     * @param a pointer to struct string
     * @param src string to assign
     */
    void (*set)(string *a, const char *src);

    /** Sets random data to `a`. Note: length should be greater than 0, (not equal to 0). Well, no error and result if assigned 0.
     * @param a pointer to struct string
     * @param len size of random string
     */
    void (*set_random)(string *a, const long long int len);

    /** @brief Sets `src` array to `a`. Note: `from`, `till` belongs to [0, sizeof(`src`)]. 
     * Set `char_between` to 0 if you want nothing to append in-between. 
     * Note: `src[till]` is not included in resultant string.
     * @param a pointer to struct string
     * @param src string array to assign
     * @param char_between character to append between `src[x]` and `src[x + 1]`
     * @param from point to start assigning `src[from]`
     * @param till assign till `src[till]`
     * @param len length of `src` array
     */
    void (*set_array)(string *a, const char *src[], char char_between, size_t from, size_t till, size_t len);

    /** Returns `a` as `char *`.
     * @param a pointer to struct string
     * @returns return `a` as `char *`
     */
    char *(*get)(string *a);

    /** Appends `src` to `a` at end.
     * @param a pointer to struct string
     * @param src string to append
     */
    void (*append)(string *a, const char *src);

    /** Appends `src` to `a` at start.
     * @param a pointer to struct string
     * @param src string to append
     */
    void (*append_start)(string *a, const char *src);

    /** Checks whether `a` is empty or not.
     * @param a pointer to struct string
     * @returns return 0 if empty, otherwise return 1
     */
    int (*empty)(string *a);

    /** Linear time complexity, O(n), where n is the length of the char array.
     * Replaces `old` to `new`.
     * @param a pointer to struct string
     * @param old old character (character to be replaced)
     * @param new_ new character (character to be replaced with)
    */
    void (*replace_char)(string *a, const char old, const char new_);

    /**
     * Sets `what` at `where` in `a`.
     * Only sets if `where` is less than size of `a`.
     * @param a pointer to struct string
     * @param what character to set
     * @param where sets `what` at a fixed position
     */
    void (*char_set)(string *a, const char what, size_t where);

    /**
     * Returns character from `a` at `where`.
     * Only returns if `where` is less than size of `a`.
     * @param a pointer to struct string
     * @param where get an element from where in `a`
     * @returns character from `a` at `where`.
     */
    char (*char_get)(string *a, size_t where);

    /**
     * Returns length of `a`, if `a` != NULL.
     * @param a pointer to struct string
     * @returns length of `a`
     */
    size_t (*length)(string *a);

    /**
     * Compares `a` against `T1`.
     * @param a pointer to struct string
     * @param T1 string to compare with
     * @returns return 0 if true, otherwise return 1
     */
    int (*compare)(string *a, const char *T1);

    /**
    * Prints `a`.
    * @param a pointer to struct string
    * @param add_next_line set 0 if append next line, otherwise set 1
    * @param __format__ arguments for ...
     */
    void (*print)(string *a, int add_next_line, const char *__format__, ...);

    /**
     * Replaces `old` in `a` with `new_`.
     * @param a pointer to struct string
     * @param old what to replace
     * @param new_ replace with
     */
    void (*replace)(string *a, const char *old, const char *new_);

    /**
     * Free `a->str.src`.
     * Do not forget to use this function at the end.
     * @param a pointer to struct string
     * @returns 0 if freed successfully, otherwise return 1
     */
    int (*destructor)(string *a);

    /** 
     * Returns `a` as `const char *`.
     * @param a pointer to struct string
     * @returns return `a` as `const char *`
     */
    const char *(*c_str)(string *a);

    /**
     * Saves `a` at `location`.
     * @param a pointer to struct string
     * @param location where to save
     * @returns 0 if save successfully, otherwise return 1
     */
    int (*save)(string *a, const char *location);

    /**
     * Opens file at `location` and then sets `a` the contents of the file.
     * @param a pointer to struct string
     * @param location file to open
     * @returns 0 if opened successfully, otherwise return 1
     */
    int (*open)(string *a, const char *location);

    /**
     * Clears `a` using `calloc` function defined in <stdlib.h> header.
     * @param a pointer to struct string
     * @returns 0 if cleared successfully, otherwise return 1
     */
    int (*clear)(string *a);

    /**
     * Converts `a` to upper case.
     * @param a pointer to struct string
     */
    void (*to_upper)(string *a);

    /**
     * Converts `a` to lower case.
     * @param a pointer to struct string
     */
    void (*to_lower)(string *a);

    /**
     * Returns whether `a` is initialized or not using `init_str` function.
     * @param a pointer to struct string
     * @returns 0 if initialized, otherwise return nothing because this method have to be initialized using `init_str` function.
     */
    int (*is_initialized)(string *a);

    /** 
     * Converts `a` (as string) to base 2 (as binary).
     * @param a pointer to struct string
    */
    void (*to_binary)(string *a);

    /** 
     * Converts `a` from base 2 (as binary) to string. Not executed if `a` is not in binary form i.e, [1, 0].
     * @param a pointer to struct string
    */
    int (*from_binary)(string *a);

    /**
     * Calculates the entropy using `Shannon's entropy` formula, which was introduced in his 1948 paper "A Mathematical Theory of Communication". For more information https://en.wikipedia.org/wiki/Entropy_(information_theory)
     * @param a pointer to struct string
     * @returns entropy of `a`.
     */
    long double (*entropy)(string *a);
} __string__;

void _set(string *a, const char *src)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        free(a->str.src);
        a->str.src = (char *)malloc(sizeof(char) * (strlen(src) + 1));
        strcpy(a->str.src, src);
    }
}

void _set_random(string *a, const long long int len)
{
    if (a && a->str.init == true && a->str.src && len > 0)
    {
        char *buff = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        strcpy(buff, "\0");
        srand((unsigned int)(time(NULL) * getpid() * getpid() + getpid())); // getpid() is used to generate a random number so that if process runs rapidly is should produce a random number.
        // random ascii character betweem 32 and 126, inclusive
        for (size_t i = 0; i < len; i++)
            buff[i] = (rand() % (126 - 32 + 1)) + 32;
        free(a->str.src);
        a->str.src = (char *)malloc((sizeof(char) * len) + 1);
        strcpy(a->str.src, (const char *)buff);
        free(buff);
    }
}

void _set_array(string *a, const char *src[], char char_between, size_t from, size_t till, size_t len)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        int valid = true;
        if (from < 0 || till > len)
        {
            valid = false;
            return;
        }
        size_t cnt_t = 0;
        if (valid == true)
        {
            for (size_t i = from; i < till; i++)
            {
                if (src[i] == NULL)
                {
                    valid = false;
                    break;
                }
                else
                    cnt_t += strlen(src[i]);
            }
        }
        if (valid == true)
        {
            if (char_between != '\0')
                cnt_t += len + 1;
            char *buff = (char *)malloc((sizeof(char) * cnt_t) + 1);
            strcpy(buff, "\0");
            for (size_t i = from; i < till; i++)
            {
                strcat(buff, src[i]);
                if (i < till - 1 && char_between != '\0')
                    strncat(buff, &char_between, 1);
            }
            free(a->str.src);
            a->str.src = (char *)malloc(sizeof(char) * (strlen((const char *)buff) + 1));
            strcpy(a->str.src, (const char *)buff);
            free(buff);
        }
    }
}

char *_get(string *a)
{
    if (a && a->str.init == true && a->str.src)
        return a->str.src;
    return (char *)NULL;
}

void _append(string *a, const char *src)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        if (strlen((const char *)a->str.src) == 0) // string is empty
        {
            free(a->str.src); // used malloc in `init_str` function
            a->str.src = (char *)malloc(sizeof(char) * (strlen(src) + 1));
            strcpy(a->str.src, src); // copy `src` it.
        }
        else
        {
            a->str.src = (char *)realloc(a->str.src, sizeof(char) * (strlen(src) + strlen(a->str.src) + 1));
            strcat(a->str.src, src);
        }
    }
}

void _append_start(string *a, const char *src)
{
    if (a && src && a->str.init == true && a->str.src)
    {
        if (strlen((const char *)a->str.src) == 0) // string is empty
        {
            free(a->str.src); // used malloc in `init_str` function
            a->str.src = (char *)malloc(sizeof(char) * (strlen(src) + 1));
            strcpy(a->str.src, src); // copy `src` it.
        }
        else
        {
            char *buff = (char *)malloc(sizeof(char) * (strlen(src) + strlen(a->str.src) + 1));
            strcpy(buff, src);
            strcat(buff, (const char *)a->str.src);
            free(a->str.src);
            a->str.src = (char *)malloc((sizeof(char) * strlen((const char *)buff)) + 1);
            strcpy(a->str.src, (const char *)buff);
            free(buff);
        }
    }
}

int _empty(string *a)
{
    if (a && a->str.src && a->str.init == true)
        if (strlen((const char *)a->str.src) == 0)
            return true;
    return false;
}

void _replace_char(string *a, const char old, const char new_)
{
    if (a && a->str.src && a->str.init == true)
    {
        for (size_t i = 0; a->str.src[i] != '\0'; ++i)
            if (a->str.src[i] == old)
                a->str.src[i] = new_;
    }
}

void _char_set(string *a, const char what, size_t where)
{
    if (a && a->str.src && a->str.init == true)
    {
        if (strlen((const char *)a->str.src) > where)
            a->str.src[where] = what;
    }
}

char _char_get(string *a, size_t where)
{
    if (a && a->str.src && a->str.init == true)
    {
        if (strlen((const char *)a->str.src) > where)
            return a->str.src[where];
    }
    return (char)'\0';
}

size_t _length(string *a)
{
    if (a && a->str.src && a->str.init == true)
        return strlen((const char *)a->str.src);
    return (size_t)0;
}

int _compare(string *a, const char *T1)
{
    if (a && T1 && a->str.init == true && a->str.src)
    {
        if (strcmp((const char *)a->str.src, T1) == true)
            return true;
    }
    return false;
}

void _print(string *a, int add_next_line, const char *__format__, ...)
{
    if (a && __format__ && a->str.init == true && a->str.src)
    {
        va_list ar;
        va_start(ar, (const char *)__format__);
        printf("%s", a->str.src);
        vprintf((const char *)__format__, ar);
        va_end(ar);
        if (add_next_line == true)
        {
#ifdef _WIN32
            printf("\r\n");
#elif defined __unix__
            printf("\n");
#elif defined __APPLE__
            printf("\n");
#endif
        }
        fflush(stdout);
    }
}

void _replace(string *a, const char *old, const char *new_)
{
    if (a && old && new_ && a->str.init == true && a->str.src)
    {
        size_t i, count_old = 0, len_o = strlen(old), len_n = strlen(new_);
        for (i = 0; a->str.src[i] != '\0'; ++i)
        {
            if (strstr((const char *)&a->str.src[i], old) == &a->str.src[i])
            {
                count_old++;
                i += len_o - 1;
            }
        }
        char *r = (char *)calloc(sizeof(char) * (i + count_old * (len_n - len_o) + 1), sizeof(char));
        i = 0;
        while (*a->str.src)
        {
            if (strstr(a->str.src, old) == a->str.src)
            {
                strncpy(&r[i], new_, len_n + 1);
                i += len_n;
                a->str.src += len_o;
            }
            else
                r[i++] = *a->str.src++;
        }
        r[i] = '\0';
        a->str.src = (char *)calloc(sizeof(char) * (strlen((const char *)r) + 1), sizeof(char));
        strcpy(a->str.src, (const char *)r);
        free(r);
    }
}

int _destructor(string *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        free(a->str.src);
        return true;
    }
    return false;
}

const char *_c_str(string *a)
{
    if (a && a->str.init == true && a->str.src)
        return (const char *)a->str.src;
    return (const char *)NULL;
}

int _save(string *a, const char *location)
{
    if (a && a->str.src && location && a->str.init == true)
    {
        FILE *f = fopen(location, "wb");
        if (f != NULL)
        {
            fwrite((const char *)a->str.src, strlen((const char *)a->str.src), sizeof(char), f);
            fclose(f);
            return true;
        }
    }
    return false;
}

int _open(string *a, const char *location)
{
    if (a && location && a->str.init == true)
    {
        FILE *f = fopen(location, "rb");
        if (f != NULL)
        {
            fseek(f, 0, SEEK_END);
            size_t len = ftell(f);
            fseek(f, 0, SEEK_SET);
            free(a->str.src);
            a->str.src = (char *)calloc(len + 1, sizeof(char));
            fread(a->str.src, sizeof(char), len, f);
            fclose(f);
            return true;
        }
    }
    return false;
}

int _clear(string *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        free(a->str.src);
        a->str.src = (char *)calloc(1, sizeof(char));
        return true;
    }
    return false;
}

void _to_upper(string *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        for (size_t i = 0; a->str.src[i] != '\0'; ++i)
        {
            if (a->str.src[i] <= 122 && a->str.src[i] >= 97)
                a->str.src[i] -= 32;
        }
    }
}

void _to_lower(string *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        for (size_t i = 0; a->str.src[i] != '\0'; ++i)
        {
            if (a->str.src[i] <= 90 && a->str.src[i] >= 65)
                a->str.src[i] += 32;
        }
    }
}

int _is_initialized(string *a)
{
    if (a)
        if (a->str.init == true)
            return true;
    return false; // never reaches this point by the way
}

void _to_binary(string *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        size_t len = strlen((const char *)a->str.src);
        char *buff = (char *)malloc(((2 * (len * 8)) + 1) * sizeof(char));
        strcpy(buff, "\0");
        char c = '\0';
        for (size_t i = 0; i < len; ++i)
        {
            c = a->str.src[i];
            for (int j = 7; j >= 0; --j)
            {
                if (c & (1 << j))
                    strcat(buff, "1");
                else
                    strcat(buff, "0");
            }
            if (i < len - 1)
                strcat(buff, " ");
        }
        free(a->str.src);
        a->str.src = (char *)malloc(sizeof(char) * (strlen((const char *)buff) + 1));
        strcpy(a->str.src, (const char *)buff);
        free(buff);
    }
}

int _from_binary(string *a)
{
    int valid = true;
    if (a && a->str.src && a->str.init == true)
    {
        size_t len = strlen((const char *)a->str.src);
        // test 1 for checking binary input format
        for (size_t i = 0; i < len; i++)
        {
            switch (a->str.src[i])
            {
            case '1':
            case '0':
            case ' ':
                break;

            default:
                valid = false;
                break;
            }
            if (valid == false)
                break;
        }
        // test 2 for checking binary input format
        if (valid == true)
        {
            size_t cnt = 0;
            for (size_t i = 0; i < len; i++)
            {
                if (a->str.src[i] == ' ')
                    cnt++;
            }
            if ((len - cnt) % 8 == 0 && ((len - cnt) / 8) == (cnt + 1))
                valid = true;
            else
                valid = false;
        }
        if (valid == true)
        {
            char *buff = (char *)malloc((len / 8) + 1);
            char bin[9] = "\0";
            strcpy(buff, "\0");
            char c = '\0';
            for (size_t i = 0, j = 0; i < len; ++i, ++j)
            {
                if (a->str.src[i] == ' ')
                {
                    c = strtol(bin, (char **)NULL, 2);
                    strncat(buff, &c, 1);
                    j = 0;
                }
                if (i == len - 1)
                {
                    bin[j] = a->str.src[i]; // append last character
                    c = strtol(bin, (char **)NULL, 2);
                    strncat(buff, &c, 1);
                }
                bin[j] = a->str.src[i];
            }
            free(a->str.src);
            a->str.src = (char *)malloc(sizeof(char) * (strlen((const char *)buff) + 1));
            strcpy(a->str.src, (const char *)buff);
            free(buff);
        }
    }
    return valid;
}

long double _entropy(string *a)
{
    if (a && a->str.src && a->str.init == true)
    {
        size_t len = strlen((const char *)a->str.src);
        size_t cnt = 0, map_append = 0, o = 0;
        int check = false;
        char *map_char = (char *)calloc((sizeof(char) * len) + 1, sizeof(char));
        size_t *map_cnt = (size_t *)calloc((sizeof(size_t) * len) + 1, sizeof(size_t));
        for (cnt = 0; cnt < len; cnt++)
        {
            check = false;
            for (o = 0; map_char[o] != '\0'; o++)
            {
                if (map_char[o] == a->str.src[cnt])
                {
                    check = true;
                    break;
                }
            }
            if (check == false)
            {
                map_char[map_append] = a->str.src[cnt];
                map_cnt[map_append] = 1;
                map_append++;
            }
            else
                map_cnt[o] += 1;
        }
        long double result = 0.0f;
        long double freq = 0.0f;
        for (size_t i = 0; map_char[i] != '\0'; i++)
        {
            freq = (long double)map_cnt[i] / len;
            result -= freq * (log10l(freq) / log10l(2.0f));
        }
        free(map_char);
        free(map_cnt);
        return result;
    }
    return 0.0f;
}

void init_str(string *a)
{
    /** 
     * Here 1 means no memory leak, and 0 means memory leak was found.
     * Working means function works as expected.
    */
    if (a)
    {
        a->set = _set;                       /// working 1
        a->set_random = _set_random;         /// working 1
        a->set_array = _set_array;           /// working 1
        a->get = _get;                       /// working 1
        a->append = _append;                 /// working 1
        a->append_start = _append_start;     /// working 1
        a->empty = _empty;                   /// working 1
        a->replace_char = _replace_char;     /// working 1
        a->char_set = _char_set;             /// working 1
        a->char_get = _char_get;             /// working 1
        a->length = _length;                 /// working 1
        a->compare = _compare;               /// working 1
        a->print = _print;                   /// working 1
        a->replace = _replace;               /// working 0
        a->destructor = _destructor;         /// working 1
        a->c_str = _c_str;                   /// working 1
        a->save = _save;                     /// working 1
        a->open = _open;                     /// working 1
        a->clear = _clear;                   /// working 1
        a->to_upper = _to_upper;             /// working 1
        a->to_lower = _to_lower;             /// working 1
        a->is_initialized = _is_initialized; /// working 1
        a->to_binary = _to_binary;           /// working 1
        a->from_binary = _from_binary;       /// working 1
        a->entropy = _entropy;               /// working 1
        a->str.src = (char *)malloc(1 * sizeof(char));
        strcpy(a->str.src, "\0"); // default init instead of some `garbage value`
        a->str.init = true;       // initialized properly
    }
}

void init_str_array(string *a[], size_t len)
{
    if (a)
    {
        for (size_t i = 0; i < len; ++i)
            init_str(a[i]);
    }
}
