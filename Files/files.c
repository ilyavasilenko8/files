#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>
#include "D:\Test\string\String\tasks\string_.h"
#include "files.h"

bool assert_file(char *file_name, char **true_data) {
    FILE *file;
    file = fopen(file_name, "r");

    if (file == NULL) {
        perror(file_name);
        fclose(file);
        return false;
    }

    size_t size = 0;

    while (!feof(file)) {
        char string[MAX_STRING_SIZE];
        fgetc(string, MAX_STRING_LENGTH, file);

        if (strcmp_(string, true_data[size]) != 0) {
            fclose(file);
            return false;
        }
        size++;
    }
    fclose(file);
    return true;
}

void make_matrix_storage_by_columns(char *file_name) {
    FILE *file;
    file = fopen(file_name, "r");

    if (file == NULL) {
        perror(file_name);
        return;
    }

    char strings[MAX_STRINGS_NUMBER][MAX_STRING_LENGTH];
    size_t size = 0;

    while (!feof(file)) {
        fgets(strings[size], MAX_STRING_LENGTH, file);
        size++;
    }

    fclose(file);
    file = fopen(file_name, "w");

    for (size_t i = 0; i < size; i++) {
        int matrix_size = atoi(strings[i]);

        if (i == 0) {
            fprintf(file, "%d", matrix_size);
        } else {
            fprintf(file, "\n%d", matrix_size);
        }

        BagOfWords elements[matrix_size];

        for (size_t j = 0; j < matrix_size; j++) {
            getBagOfWords(&elements[j], strings[i + j + 1]);

        }

        for (size_t j = 0; j < matrix_size; j++) {
            for (size_t g = 0; g < matrix_size; g++) {
                int element = atoi(elements[g].words[j].begin);

                if (g == 0) {
                    fprintf(file, "\n%d", element);
                } else {
                    fprintf(file, " %d", element);
                }
            }
        }

        i += matrix_size;
    }

    fclose(file);
}

void test_make_matrix_storage_by_columns() {
    FILE *test;
    test = fopen("test.txt", "w");
    fprintf(test, "3\n1 2 3\n4 5 6\n7 8 9\n0\n2\n11 15\n3 70\n1\n54");
    fclose(test);
    make_matrix_storage_by_columns("test.txt");
    char *true_data[] = {"3\n", "1 4 7\n", "2 5 8\n", "3 6 9\n", "0\n", "2\n", "11 3\n", "15 70\n", "1\n", "54"};
    assert(assert_file("test.txt", true_data));
}

void represent_as_floating_point_numbers(char *file_name) {
    FILE *file;
    file = fopen(file_name, "r");

    double numbers[MAX_STRINGS_NUMBER];
    size_t size = 0;

    while (fscanf(file, "%lf", &numbers[size]) != EOF) {
        size++;
    }

    fclose(file);
    file = fopen(file_name, "w");

    for (size_t i = 0; i < size; i++) {
        if (i == 0) {
            fprintf(file, "%.2f", numbers[i]);
        } else {
            fprintf(file, "\n%.2f", numbers[i]);
        }
    }

    fclose(file);
}

void test_represent_as_floating_point_numbers() {
    FILE *test;
    test = fopen("test.txt", "w");
    fprintf(test, "12343.3\n332.253\n4322.32\n2.32523");
    fclose(test);
    represent_as_floating_point_numbers("test.txt");
    char *true_data[] = {"12343.30\n", "332.25\n", "4322.32\n", "2.33"};
    assert(assert_file("test.txt", true_data));
}

void calculate_expression(char *file_name) {
    FILE *file;
    file = fopen(file_name, "r");
    char expression[MAX_STRING_LENGTH];
    fgets(expression, MAX_STRING_LENGTH, file);
    fclose(file);
    double expression_result;
    BagOfWords elements;
    getBagOfWords(&elements, expression);

    if (elements.size == 3) {
        double a = atof(elements.words[0].begin);
        double b = atof(elements.words[2].begin);

        if (*elements.words[1].begin == '+') {
            expression_result = a + b;
        } else if (*elements.words[1].begin == '-') {
            expression_result = a - b;
        } else if (*elements.words[1].begin == '*') {
            expression_result = a * b;
        } else {
            expression_result = a / b;
        }
    } else {
        double a = atof(elements.words[0].begin);
        double b = atof(elements.words[2].begin);
        double c = atof(elements.words[4].begin);

        if ((*elements.words[1].begin == '+' || *elements.words[1].begin == '-') && (*elements.words[3].begin == '*' || *elements.words[3].begin == '/')) {
            if (*elements.words[3].begin == '*') {
                expression_result = b * c;
            } else {
                expression_result = b / c;
            }

            if (*elements.words[1].begin == '+') {
                expression_result += a;
            } else {
                expression_result = a - expression_result;
            }
        } else {
            if (*elements.words[1].begin == '+') {
                expression_result = a + b;
            } else if (*elements.words[1].begin == '-') {
                expression_result = a - b;
            } else if (*elements.words[1].begin == '*') {
                expression_result = a * b;
            } else {
                expression_result = a / b;
            }

            if (*elements.words[3].begin == '+') {
                expression_result += c;
            } else if (*elements.words[3].begin == '-') {
                expression_result -= c;
            } else if (*elements.words[3].begin == '*') {
                expression_result *= c;
            } else {
                expression_result /= c;
            }
        }
    }

    file = fopen(file_name, "a");
    fprintf(file, " = %.3lf", expression_result);
    fclose(file);
}

void test_calculate_expression() {
    FILE *test;
    test = fopen("test.txt", "w");
    fprintf(test, "3 + 2");
    fclose(test);
    calculate_expression("test.txt");
    char *true_data[1] = {"3 + 2 = 5.000"};
    assert(assert_file("test.txt", true_data));

    test = fopen("test.txt", "w");
    fprintf(test, "3 - 6");
    fclose(test);
    calculate_expression("test.txt");
    char *true_data_2[1] = {"3 - 6 = -3.000"};
    assert(assert_file("test.txt", true_data_2));

    test = fopen("test.txt", "w");
    fprintf(test, "2 * 2");
    fclose(test);
    calculate_expression("test.txt");
    char *true_data_3[1] = {"2 * 2 = 4.000"};
    assert(assert_file("test.txt", true_data_3));

    test = fopen("test.txt", "w");
    fprintf(test, "5 / 2");
    fclose(test);
    calculate_expression("test.txt");
    char *true_data_4[1] = {"5 / 2 = 2.500"};
    assert(assert_file("test.txt", true_data_4));

    test = fopen("test.txt", "w");
    fprintf(test, "2 + 5 - 3");
    fclose(test);
    calculate_expression("test.txt");
    char *true_data_5[1] = {"2 + 5 - 3 = 4.000"};
    assert(assert_file("test.txt", true_data_5));

    test = fopen("test.txt", "w");
    fprintf(test, "2 * 2 - 1");
    fclose(test);
    calculate_expression("test.txt");
    char *true_data_6[1] = {"2 * 2 - 1 = 3.000"};
    assert(assert_file("test.txt", true_data_6));

    test = fopen("test.txt", "w");
    fprintf(test, "2 * 2 * 2");
    fclose(test);
    calculate_expression("test.txt");
    char *true_data_7[1] = {"2 * 2 * 2 = 8.000"};
    assert(assert_file("test.txt", true_data_7));

    test = fopen("test.txt", "w");
    fprintf(test, "2 + 2 * 2");
    fclose(test);
    calculate_expression("test.txt");
    char *true_data_8[1] = {"2 + 2 * 2 = 6.000"};
    assert(assert_file("test.txt", true_data_8));
}

void test_files() {
    test_make_matrix_storage_by_columns();
    test_represent_as_floating_point_numbers();
    test_calculate_expression();
}