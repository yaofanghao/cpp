// 翁恺C语言p120-p123
// 可变数组的应用

#include <stdio.h>
#include <stdlib.h>

const BLOCK_SIZE = 20; // 每次扩增的数组大小

typedef struct{
    int *array;
    int size;
}Array;

Array array_create(int init_size){
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size);
    return a;
}

void array_free(Array *a){
    free(a->array);
    a->array = NULL;    
    a->size = 0;
}

// 封装
int array_size(const Array *a){
    return a->size;
}

int* array_at(Array *a, int index){
    
    // 考虑数组越界情况
    if( index >= a->size){
        // array_inflate(&a, index-(a->size)+1);
        array_inflate(&a, (index/BLOCK_SIZE+1)*BLOCK_SIZE-(a->size));
    }
    return &(a->array[index]);
}

// 扩增数组
void array_inflate(Array *a, int more_size){
    int *p = (int*)malloc(sizeof(int)*(a->size + more_size));
    int i;
    for(i=0; i<a->size; i++){
        p[i] = a->array[i];
    }  // 可以用memcpy替换这个循环
    free(a->array);
    a->array = p;
    a->size += more_size;
}

int main(int argc, char const *argv[])
{   
    Array a = array_create(100);
    printf("%d\n", array_size(&a));
    printf("%d\n", a.size);
    *array_at(&a, 0) = 10;  // 把值写到数组第0个
    printf("%d\b", *array_at(&a, 0));

    int number;
    int cnt = 0;
    while(number != -1){
        scanf("%d", &number);
        if (number != -1){
            *array_at(&a, cnt++) = number;
        }
    }

    array_free(&a);

    return 0;
}
