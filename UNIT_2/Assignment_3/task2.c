#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of Array:");
    scanf("%d",&n);
    float arr[n],sum=0;
    for(int i=0;i<n;++i)
    {
        printf("Enter number:");
        scanf("%f",&arr[i]);
        sum+=arr[i];
    }
    float avg = sum / n;
    printf("Average: %.2f",avg);
    return 0;
}
