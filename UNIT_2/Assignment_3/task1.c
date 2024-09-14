#include <stdio.h>
int main()
{
    char ch;
    float arr1[2][2] ,arr2[2][2],sum[2][2]={0};
    printf("Enter elements of 1st matrix\n");
    for(int i =0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            printf("Enter a%d%d: ",1+i,1+j);
            scanf("%f",&arr1[i][j]);
        }
    }
    printf("Enter elements of 2nd matrix\n");
    for(int i =0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            printf("Enter a%d%d: ",i+1,j+1);
            scanf("%f",&arr2[i][j]);
        }
    }
    for(int i =0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
            printf("%.1f ",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
