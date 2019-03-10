#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
  int **result = (int **)malloc(sizeof(int *) * numRows);
  int i, j;

  *columnSizes = (int *)malloc(sizeof(int) * numRows);
  *returnSize = numRows;

  for (i = 0; i < numRows; ++i) {
    *(*columnSizes + i) = i + 1;
    int *row = (int *)malloc(sizeof(int) * (i + 1));
    row[0] = row[i] = 1;

    for (j = 1; j < i; ++j) {
      row[j] = result[i - 1][j - 1] + result[i - 1][j];
    }
    result[i] = row;
  }

  return result;
}

int main() {
  int *columnSizes;
  int returnSize;

  int **result = generate(10, &columnSizes, &returnSize);

  for (int i = 0; i < returnSize; ++i) {
    for (int j = 0; j < columnSizes[i]; ++j) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  if (columnSizes != NULL) {
    free(columnSizes);
  }

  if (result != NULL) {
    for (int i = 0; i < returnSize; ++i) {
      if (*(result + i) != NULL) {
        free(*(result + i));
      }
    }
    free(result);
  }
}
