#include <stdio.h>
#include <stdlib.h>

double **alloc2dArray(int rows, int cols) {
  double **arr = (double **)malloc(rows * sizeof(double *));
  if (arr == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  for (int i = 0; i < rows; i++) {
    arr[i] = (double *)malloc(cols * sizeof(double));
    if (arr[i] == NULL) {
      printf("Memory allocation failed\n");
      exit(1);
    }
  }

  return arr;
}

void read2dArray(double **arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%lf", &arr[i][j]);
    }
  }
}

double **multMatrices(double **arr1, double **arr2, int m, int n, int k) {
  if (n != k) {
    printf("Matrix dimensions not compatible for multiplication\n");
    return NULL;
  }

  double **result = alloc2dArray(m, k);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      result[i][j] = 0;
      for (int p = 0; p < n; p++) {
        result[i][j] += arr1[i][p] * arr2[p][j];
      }
    }
  }

  return result;
}

int main(void) {
  int rows = 3, cols = 3;
  double **arr1 = alloc2dArray(rows, cols);
  double **arr2 = alloc2dArray(cols, rows);

  read2dArray(arr1, rows, cols);
  read2dArray(arr2, cols, rows);

  double **result = multMatrices(arr1, arr2, rows, cols, rows);

  printf("Resultant Matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      printf("%.2lf ", result[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < rows; i++) {
    free(arr1[i]);
    free(arr2[i]);
    free(result[i]);
  }
  free(arr1);
  free(arr2);
  free(result);

  return 0;
}
