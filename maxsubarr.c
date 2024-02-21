
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct ra{
int low;
int high;
int sum;
};
struct array {
    int size;
    int *arr;
};

struct array* MaxArray(struct array *s, int l, int r) {
    struct array *minmax = (struct array*)malloc(sizeof(struct array));
    minmax->size = 2;
    minmax->arr = (int*)malloc(minmax->size * sizeof(int));

    int min, max;
    if (l == r) {
        
        return(l,r,s->arr[l]);
    } 
    else{
    
     
        int m = l + (r - l) / 2;

        struct array *ra1 = MaxArray(s, l, m);
        struct array *ra2 = MaxArray(s, m + 1, r);
        if(ra1.maxSum)>=ra2.maxSum
       
    
    }
    return minmax;
}
void MaximumCrossing(struct array*s,int l,int m,int r){
    int i,j;
int leftsum=0;
int maxleft=0;
int sum=0;
for(i=m;i>l;i--){
    sum=sum+s->arr[i];
    if(sum>leftsum){
        leftsum=sum;
        maxleft=i;
    }
}
int rightsum=0;
sum=0;
int maxright=0;
for(j=m+1;j<r;j++){
sum=sum+s->arr[j];
if(sum>rightsum){
    rightsum=sum;
    maxright=j;
}
}
int maxsum=leftsum+rightsum;
struct ra *rac=(struct ra*)malloc(sizeof(struct ra));
rac->low=maxleft;
rac->
return()
}