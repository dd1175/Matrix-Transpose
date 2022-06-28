#ifndef _MATRIX_C
#define _MATRIX_C

#include "matrix.h"

Matrix new_matrix(int row_count, int col_count) {
  Matrix return_matrix = {.size = {.row = row_count, .col = col_count}};
  return_matrix.element_ptr =
      (Scalar *)calloc(sizeof(Scalar), row_count * col_count);
  return return_matrix;
};

Matrix matrix_scale(Matrix *matrix, Scalar scalar) {
  Matrix return_matrix = new_matrix(matrix->size.row, matrix->size.col);
  for (int i = 0; i < return_matrix.size.row; i++) {
    for (int j = 0; j < return_matrix.size.col; j++) {
      set_matrix_element(&return_matrix,
                         get_matrix_element(matrix, i, j) * scalar, i, j);
    }
  }
  return return_matrix;
};

Matrix matrix_transpose(Matrix *matrix) {
  Matrix return_matrix = new_matrix(matrix->size.col, matrix->size.row);
  for (int i = 0; i < return_matrix.size.row; i++) {
    for (int j = 0; j < return_matrix.size.col; j++) {
      set_matrix_element(&return_matrix, get_matrix_element(matrix, j, i), i,
                         j);
    }
  }
  return return_matrix;
};

void set_matrix_element(Matrix *matrix, Scalar value, int row_index,
                        int col_index) {
  *(matrix->element_ptr + row_index * matrix->size.col + col_index) = value;
};

Scalar get_matrix_element(Matrix *matrix, int row_index, int col_index) {
  return *(matrix->element_ptr + row_index * matrix->size.col + col_index);
}

void print_matrix(Matrix *matrix) {
  int value_percision = 3;
  log_("Matrix data: ");
  print_dashes((value_percision + 3) * matrix->size.col + 2);
  for (int i = 0; i < matrix->size.row; i++) {
    printf("| ");
    for (int j = 0; j < matrix->size.col; j++) {
      printf("%.*f", value_percision, get_matrix_element(matrix, i, j));
      printf(" ");
    }
    printf("|\n");
  }
  print_dashes((value_percision + 3) * matrix->size.col + 2);
};

#endif
