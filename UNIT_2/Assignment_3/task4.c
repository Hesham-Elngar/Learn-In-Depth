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
    printf("Enter the element to be inserted:");
    int num,location;
    scanf("%d",&num);
    printf("Enter the element location:");
    scanf("%d",&location);
    int flag =0;
    for(int i =n;i>=0;--i)
    {
         arr[i+1] = arr[i];
        if(location==(i+1))
        {
            arr[i--] = num;
        }
    }
    for(int i =0;i<=n;++i)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}
