#include<stdio.h>
int main(){
    float W[50],P[50],r[50],cap,temp;
    float Totalvalue=0;
    int n,i,j;
    printf("Enter total no of items");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("Enter Weight and Profit for item [%d]",i);
        scanf("%f%f",&W[i],&P[i]);
    }
    printf("Enter total capacity of knapsack");
    scanf("%f",&cap);
    for(i=0; i<n; i++){
        r[i]=P[i]/W[i];
    }
    for(i=0; i<n; i++){

        for(j=i+1; j<n; j++){
            if(r[i]<r[j]){
            temp=r[i];
            r[i]=r[j];
            r[j]=temp;

            temp=P[i];
            P[i]=P[j];
            P[j]=temp;

            temp=W[i];
            W[i]=W[j];
            W[j]=temp;
        }
        }
    }

    for(i=0; i<n; i++){
        if(W[i]>cap)
        break;
        else{
            Totalvalue=Totalvalue+P[i];
            cap=cap-W[i];
        }
    }
    if(i<n){
        Totalvalue=Totalvalue+(r[i]*cap);
    }
    printf("\n Maximum Value of Knapsack: %f\n",Totalvalue);
    return 0;
}