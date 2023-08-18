#include <stdlib.h>

void rotate(int* nums, int numsSize, int k){
    // int tmp;
    // k %= numsSize;
    // for (int i = 0; i < k; i++)
    // {
    //     tmp = nums[numsSize - 1];
    //     memmove(nums + 1, nums, sizeof(int) * (numsSize - 1));
    //     nums[0] = tmp;
    // }

    int loc = k % numsSize;
    int *arr;
    arr = malloc((numsSize + 1) * sizeof(int));
    for (int i = 0; i < loc; i++)
        arr[i] = nums[i];
    for (int i = 0; i < numsSize - loc; i++)
        nums[i] = nums[loc + i];
    for (int i = loc; i < numsSize - 2; i++)
        nums[i] = arr[loc - i];
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    rotate(arr, 7, 3);
}