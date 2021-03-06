/**
* This header file is written to solve `prototype` missing error. Do not include this file.
* Author: Tushar Chaurasia (https://github.com/Dark-CodeX/)
* Commit to this repository at https://github.com/Dark-CodeX/sstring.git
* You can use this header file. Do not modify it locally, instead commit it on https://www.github.com
* File: "prototype_err.h" under "sstring" directory
* sstring: version 1.7.0
* 
* MIT License
* 
* Copyright (c) 2022 Tushar Chaurasia
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#ifndef SSTRING_PROTOTYPE_DEFINED
#define SSTRING_PROTOTYPE_DEFINED

void fast_strncat(char *dest, const char *src, size_t *size);

void _sstring_set(sstring *a, const char *src);
void _sstring_set_char(sstring *a, const char c);
void _sstring_set_upto(sstring *a, const char *src, size_t N);
void _sstring_set_random(sstring *a, const size_t len);
void _sstring_set_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len);
char *_sstring_get(sstring *a);
void _sstring_append(sstring *a, const char *src);
void _sstring_append_char(sstring *a, const char c);
void _sstring_append_upto(sstring *a, const char *src, size_t N);
void _sstring_append_start(sstring *a, const char *src);
void _sstring_append_start_char(sstring *a, const char src);
void _sstring_append_start_upto(sstring *a, const char *src, size_t N);
void _sstring_append_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len);
void _sstring_append_start_array(sstring *a, const char **src, char char_between, size_t from, size_t till, size_t len);
bool _sstring_empty(sstring *a);
void _sstring_replace_char(sstring *a, const char old, const char new_);
void _sstring_char_set(sstring *a, const char what, size_t where);
char _sstring_char_get(sstring *a, size_t where);
size_t _sstring_last_index_of(sstring *a, char ch);
size_t _sstring_length(sstring *a);
bool _sstring_compare(sstring *a, const char *T1);
bool _sstring_compare_upto(sstring *a, const char *T1, size_t N);
int _sstring_lexicographical_comparison(sstring *a, const char *str);
void _sstring_print(sstring *a, bool add_next_line, const char *__format__, ...);
void _sstring_replace(sstring *a, const char *old, const char *new_);
bool _sstring_destructor(sstring *a);
const char *_sstring_c_str(sstring *a);
bool _sstring_save(sstring *a, const char *location);
bool _sstring_append_file(sstring *a, const char *location);
bool _sstring_open(sstring *a, const char *location);
bool _sstring_clear(sstring *a);
void _sstring_to_upper(sstring *a);
void _sstring_to_lower(sstring *a);
void _sstring_swap_case(sstring *a);
bool _sstring_is_initialized(sstring *a);
void _sstring_to_binary(sstring *a);
bool _sstring_from_binary(sstring *a);
double _sstring_entropy(sstring *a);
bool _sstring_contains(sstring *a, const char *str);
size_t _sstring_contains_char(sstring *a, const char c);
void _sstring_to_set(sstring *a);
bool _sstring_copy(sstring *a, sstring *dest);
void _sstring_to_hexadecimal(sstring *a);
bool _sstring_from_hexadecimal(sstring *a);
size_t _sstring_find(sstring *a, const char *sub);
void _sstring_in(sstring *a);
char *_sstring_getline(sstring *a, size_t line);
void _sstring_reverse(sstring *a);
size_t _sstring_remove(sstring *a, const char *sub);
size_t _sstring_remove_char(sstring *a, const char c);
size_t _sstring_remove_extra_char(sstring *a, const char c);
size_t _sstring_remove_range(sstring *a, size_t from, size_t till);
bool _sstring_intersect(sstring *a, size_t from, size_t till);
size_t _sstring_distance(sstring *a, const char *src);
size_t _sstring_edit_distance(sstring *a, const char *src);
double _sstring_percentage_matched(sstring *a, const char *src);
size_t _sstring_count(sstring *a, const char *what);
size_t _sstring_count_char(sstring *a, const char what);
char *_sstring_soundex(sstring *a);
char *_sstring_most_used(sstring *a, const char *dl);
char _sstring_most_used_char(sstring *a);
split_t _sstring_split(sstring *a, const char *dl);
void _sstring_sort(sstring *a);
size_t _sstring_open_binary(sstring *a, const char *location);
bool _sstring_save_binary(sstring *a, const char *location, size_t len);
bool _sstring_append_binary(sstring *a, const char *location, size_t len);
size_t _sstring_add_binary(sstring *a, const char *data, size_t len);
bool _sstring_print_binary(sstring *a, size_t len);
bool _sstring_encrypt(sstring *a, const char *key);
bool _sstring_decrypt(sstring *a, const char *key);
size_t _sstring_begin(void);
iter_sstring _sstring_iterator(sstring *a);
iter_sstring __sstring_reverse_iterator(sstring *a);
size_t _sstring_end_sstring(sstring *a);
bool _sstring_to_morse_code(sstring *a);
bool _sstring_from_morse_code(sstring *a);
bool _sstring_is_digit(sstring *a);
bool _sstring_is_decimal(sstring *a);
bool _sstring_is_ascii(sstring *a);
bool _sstring_is_alphabetic(sstring *a);
bool _sstring_format_escape_sequence(sstring *a);
bool _sstring_insert(sstring *a, const char *src, size_t index);
bool _sstring_starts_with(sstring *a, const char *src);
bool _sstring_ends_with(sstring *a, const char *src);
parse_t _sstring_parse(sstring *a);
bool _sstring_from_parse_t(sstring *a, parse_t *toks);
bool _sstring_set_formatted(sstring *a, size_t buffer_length, const char *__format__, ...);
bool _sstring_append_formatted(sstring *a, size_t buffer_length, const char *__format__, ...);
bool _sstring_resize(sstring *a, size_t new_len);
size_t _sstring_hash(sstring *a);

void __advance__iter_sstring(iter_sstring *is, signed long long int move_by);
bool __c_loop__iter_sstring(iter_sstring *is);

int compare_chars(const void *c1, const void *c2);
int strcmp_void(const void *a1, const void *a2);
bool free_parse(parse_t *a);
bool free_split(split_t *a);
sstring new_sstring(size_t alloc_size, const char *src);
bool init_sstr(sstring *a, size_t alloc_size);

#endif