#include <stdio.h>

int main() {

  int n;
  scanf("%d", &n);

  int x[n], y[n], i;

  float sum_x = 0.0, sum_y = 0.0;
  printf("\n");
  for(i=0; i<n; i++) {
    scanf("%d", &x[i]);
    sum_x += (float)x[i];
  }
  printf("\n");
  for(i=0; i<n; i++) {
    scanf("%d", &y[i]);
    sum_y += (float)y[i];
  }

  float mean_x = sum_x/n;
  float mean_y = sum_y/n;

  float mean_diff_x[n], mean_diff_x_squared[n], mean_diff_y[n];
  float sum_squared_diff_x = 0.0;

  for(i=0; i<n; i++) {
    mean_diff_x[i] = (float)x[i] - mean_x;
    mean_diff_x_squared[i] = mean_diff_x[i] * mean_diff_x[i];
    sum_squared_diff_x += mean_diff_x_squared[i];
  }
  for(i=0; i<n; i++)
    mean_diff_y[i] = (float)y[i] - mean_y;

  float multiply[n];
  float sum_multiply = 0.0;

  for(i=0; i<n; i++) {
    multiply[i] = mean_diff_x[i] * mean_diff_y[i];
    sum_multiply += multiply[i];
  }

  float b1 = sum_multiply/sum_squared_diff_x;
  float b0 = mean_y - b1 * mean_x;

  const char martini[5] = {0xF0, 0x9F, 0x98, 0x8D, '\0'};
  printf("Learnt parameters %s\n", martini);

  printf("Enter value for prediction: ");

  float user_x;
  scanf("%f", &user_x);

  printf("The predicted value is: %.2f", b0 + (b1 * user_x));

  return 0;
}

/*

TODO:

1) Read input from csv, remove user input, user cannot possibly enter the entire dataset.
2) Try to use as low memory as possible, remove unnecessary arrays.
3) Test with larger toy datasets and find the speed.
4) Speeden up the process as much as possible.

*/
