#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
  int m1, m2, m1_count, m2_count;

  m1 = m2 = m1_count = m2_count = 0;

  for (int i = 0; i < numsSize; ++i) {
    if (m1 == nums[i]) {
      ++m1_count;
    } else if (m2 == nums[i]) {
      ++m2_count;
    } else if (m1_count == 0) {
      m1 = nums[i];
      m1_count = 1;
    } else if (m2_count == 0) {
      m2 = nums[i];
      m2_count = 1;
    } else {
      --m1_count;
      --m2_count;
    }
  }

  m1_count = m2_count = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == m1) {
      ++m1_count;
    } else if (nums[i] == m2) {
      ++m2_count;
    }
  }

  int *res2 = (int *)malloc(2 * sizeof(int));
  int *res1 = (int *)malloc(sizeof(int));

  *returnSize = 0;
  if (m1_count > (numsSize / 3)) {
    res1[*returnSize] = res2[*returnSize] = m1;
    ++(*returnSize);
  }
  if (m2_count > (numsSize / 3)) {
    res1[*returnSize] = res2[*returnSize] = m2;
    ++(*returnSize);
  }
  if (*returnSize == 1) {
    free(res2);
    return res1;
  } else {
    free(res1);
    return res2;
  }
}

int main(void)
{
  int arr[10] = {3, 2, 3, 5, 5, 5, 5, 3, 2, 2};
  int size;

  int *res = majorityElement(arr, 10, &size);
  for (int i = 0; i < size; ++i) {
    printf("%d\n", res[i]);
  }
  if (res != NULL) {
    free(res);
  }
  return 0;
}
