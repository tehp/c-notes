#include <stdio.h>
#include <stddef.h>
#define CHECK(PRED) printf("%s . . . %s\n", (PRED) ? "passed" : "failed", #PRED)

int arr_min(const int a[], size_t n){
    int min = a[0];
    size_t i;
    for(i=1; i<n; i++)
        if (a[i]<min)
            min=a[i];
    return min;
}

size_t arr_count(const int a[], size_t n, int x){
    size_t count = 0, i;
    for(i = 0; i < n; i++)
        if(a[i]==x)
            count++;
    return count;
}

int arr_all_even(const int a[], size_t n){
    size_t i;
    for (i=0; i<n; i++)
        if (a[i] % 2 != 0)
            return 0;
    return 1;
    }

size_t arr_find_last(const int a[], size_t n, int x){
    size_t last = (size_t) -1;
    size_t i;
    for (i=0;i<n;i++)
        if (a[i]==x)
            last=i;
    return last;
}

int main(void){

    int a[]={78,123,333,333,123123,1233,777};
    int b[]={11,22,33,44,55,66,77,99,99};
    int c[]={88,66,44};
    printf("%s\n", "tests for arr_min");
    CHECK(arr_min(a,7)==78);
    CHECK(arr_min(b,9)==11);
    CHECK(arr_min(c,3)==44);
    printf("%s\n", "test for arr_count");
    CHECK(arr_count(a,7,333)==2);
    CHECK(arr_count(b,9,77)==1);
    CHECK(arr_count(c,3,5)==0);
    printf("%s\n", "tests for arr_all_even");
    CHECK(arr_all_even(a,7)==0);
    CHECK(arr_all_even(b,9)==0);
    CHECK(arr_all_even(c,3)==1);
    printf("%s\n", "tests for arr_find_last");
    CHECK(arr_find_last(a,7,777)==6);
    CHECK(arr_find_last(c,3,4)==(size_t) -1);
    CHECK(arr_find_last(b,9,99)==8);
    return 0;
}
