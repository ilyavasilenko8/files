#ifndef LABORATORY_FILES_FILES_H
#define LABORATORY_FILES_FILES_H

#define MAX_STRINGS_NUMBER 100
#define MAX_STRING_LENGTH 100

#include <stdio.h>
#include <stdbool.h>

bool assert_file(char *file_name, char **true_data);

void make_matrix_storage_by_columns(char *file_name);

void test_make_matrix_storage_by_columns();

void test_files();

#endif //LABORATORY_FILES_FILES_H
