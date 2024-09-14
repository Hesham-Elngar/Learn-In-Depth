#include <stdio.h>
int main()
{
    int n;
    printf("Enter no of elements:");
    scanf("%d",&n);
    int arr[n];
    for(int i =0;i<n;++i)
    {
            printf("Enter element: ");
            scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched:");
    int num;
    scanf("%d",&num);
    for(int i =0;i<=n;++i)
    {
        if(num==arr[i])
        {
            printf("found in location %d ",(i+1));
            break;
        }
    }

    return 0;
}
