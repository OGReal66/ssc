#include <stdio.h>
#include <stdlib.h>

int main() {
    int alloc[10][10],max[10][10],need[10][10],avail[10];
    int order[10]={10}, completed[10]={0};
    int p, r,i,j,k,o=0,flag=0,check=0;
    printf("Enter the total number of process : ");
    scanf("%d",&p);
    printf("\nEnter the total number of resources : ");
    scanf("%d",&r);
    printf("\nEnter the allocation matrix : ");
    for(i=0; i<p; i++){
        for(j=0; j<r; j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\nEnter the max matrix : ");
    for(i=0; i<p; i++){
        for(j=0; j<r; j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nEnter the available resources : ");
    for(i=0;i<r;i++)
        scanf("%d", &avail[i]);
    for(i=0; i<p; i++){
        for(j=0; j<r; j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(i=0;i<p;i++){
        flag=0;  //flag to check if in this process available is greater than need
        if(completed[i] == 0){  //process i is incomplete
            for(j=0;j<r;j++){
                if(avail[j]<need[i][j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                check = 1;   //flag to check if another iteration is needed from the first process
                completed[i]=1;  //the process is now completed
                order[o]=i+1;   //array to maintain the safe sequence
                o++;            //pointer to the above mentioned array
                for(j=0;j<r;j++){
                    avail[j] += alloc[i][j];   //updating the available array, max matrix and allocation matrix
                    max[i][j]=0;
                    alloc[i][j]=0;
                }
                printf("\nMax\tAllocation\n");  //printing the matrices if any update is done
                for(k=0;k<p;k++){
                    for(j=0;j<r;j++){
                        printf("%d ",max[k][j]);
                    }
                    printf("\t");
                    for(j=0;j<r;j++){
                        printf("%d ",alloc[k][j]);
                    }
                    printf("\n");
                }
            }
        }
        if((i == p-1) && check == 1){     //reinitializing the pointer to the start if any changes were made in the current iteration
            i = -1;
            check=0;
        }
    }
    if(o!=p)        //if all processes are not in the safe sequence
        printf("The System is in deadlock");
    else{
        printf("The safe sequence is :->\n< ");
        for(i=0;i<o;i++){
            printf("%d ",order[i]);
        }
        printf(">\n");
    }
    return 0;
}
