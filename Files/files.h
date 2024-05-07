#ifndef LABORATORY_FILES_FILES_H
#define LABORATORY_FILES_FILES_H

#define MAX_STRINGS_NUMBER 100
#define MAX_STRING_LENGTH 100

#include <stdio.h>
#include <stdbool.h>

bool assert_file(char *file_name, char **true_data);

void make_matrix_storage_by_columns(char *file_name);

void test_make_matrix_storage_by_columns();

void save_only_longest_word_in_string(char *file_name);

void test_save_only_longest_word_in_string();

void represent_as_floating_point_numbers(char *file_name);

void test_represent_as_floating_point_numbers();

void calculate_expression(char *file_name);

void test_calculate_expression();

void save_only_words_with_sequence(char *file_name, char *sequence);

void test_save_only_words_with_sequence();

void test_files();

#endif //LABORATORY_FILES_FILES_H
