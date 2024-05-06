#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>
#include "D:\Test\string\String\tasks\string_.h"
#include "files.h"

bool assert_file(char *file_name, char **true_data){
    FILE *file;
    file = fopen(file_name, "r");

    if(file == NULL){
        perror(file_name);
        fclose(file);
        return false;
    }

    size_t size = 0;

    while(!feof(file)){
        char string[MAX_STRING_SIZE];
        fgetc(string, MAX_STRING_LENGTH, file);

        if(strcmp_(string, true_data[size]) != 0){
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

void test_files() {
    test_make_matrix_storage_by_columns();
}