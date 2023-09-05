#include <stdio.h>

int length;

float avg(int n[length])
{
    int x = 0;
    for(int i = 0 ; i < length ; i++)
    {
        x = x + n[i];
    }
    return x/(float)length;
}

int main(void)
{
    printf("Enter the length of numbers to get the Average : ");
    scanf("%d", &length);
    int nums[length];
    for(int i = 0 ; i < length ; i++)
    {
        printf("Enter Number %d : ", i + 1);
        scanf("%d", &nums[i]);
    }
    float x = avg(nums);
    printf("The Average is %.2f : \n", x);
}
