#include <stdio.h>
int main()
{
    int x,y;
    printf("Enter matrix row and column:");
    scanf("%d",&x);
    scanf("%d",&y);
    int arr[x][y];
    printf("Enter elements of matrix\n");
    for(int i =0;i<x;++i)
    {
        for(int j=0;j<y;++j)
        {
            printf("Enter element a%d%d: ",1+i,1+j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Entered Matrix\n");
     for(int i =0;i<x;++i)
    {
        for(int j=0;j<y;++j)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("Transpose Matrix\n");
    for(int i =0;i<y;++i)
    {
        for(int j=0;j<x;++j)
        {
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}
