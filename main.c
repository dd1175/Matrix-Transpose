#include <stdio.h>
#include <stdlib.h>

#include "matrix.c"

int main() {
  int row_count, col_count;
  printf("Enter row count: ");
  scanf("%d", &row_count);
  printf("Enter col count: ");
  scanf("%d", &col_count);
  Matrix input_matrix = new_matrix(row_count, col_count);
  for (int i = 0; i < row_count; i++) {
    for (int j = 0; j < col_count; j++) {
      printf("Enter element (%d, %d): ", i + 1, j + 1);
      float user_input;
      scanf("%f", &user_input);
      set_matrix_element(&input_matrix, user_input, i, j);
    }
  }
  Matrix transposed_matrix = matrix_transpose(&input_matrix);
  print_matrix(&transposed_matrix);
  exit(EXIT_SUCCESS);
}
