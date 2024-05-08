#ifndef LABORATORY_FILES_FILES_H
#define LABORATORY_FILES_FILES_H

#define MAX_STRINGS_NUMBER 100
#define MAX_STRING_LENGTH 100
#define MAX_ELEMENTS_NUMBER 100

#include <stdio.h>
#include <stdbool.h>

typedef struct polynomial {
    int power;
    int coefficient;
} polynomial;

typedef struct sportsman {
    char *FIO;
    int best_result;
} sportsman;

typedef struct product {
    char *name;
    int unit_price;
    int quantity;
    int total_price;
} product;

typedef struct order {
    char *name;
    int quantity;
} order;

bool assert_file(char *file_name, char **true_data);

void make_matrix_storage_by_columns(char *file_name);

void test_make_matrix_storage_by_columns();

void represent_as_floating_point_numbers(char *file_name);

void test_represent_as_floating_point_numbers();

void calculate_expression(char *file_name);

void test_calculate_expression();

void save_only_words_with_sequence(char *file_name, char *sequence);

void test_save_only_words_with_sequence();

void save_only_longest_word_in_string(char *file_name);

void test_save_only_longest_word_in_string();

int pow_(int a, int b);

void remove_polynomials_if_x_sqrt_root(char *file_name, int *size, int x);

void test_remove_polynomials_if_x_sqrt_root();

void sort_negative_after_positive(char *file_name, size_t size);

void test_sort_negative_after_positive();

void transpose_non_symmetric_matrices(char *file_name, size_t size);

void test_transpose_non_symmetric_matrices();

void sort_sportsmen(sportsman sportsmen[], size_t size);

void make_team(char *file_name, size_t size, size_t players_need);

void test_make_team();

void update_products_information(char *products_file_name, size_t *products_size, char *orders_file_name, size_t orders_size);

void test_update_products_information();

void test_files();

#endif //LABORATORY_FILES_FILES_H
