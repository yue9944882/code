#ifndef C_STACK_H_INCLUDED
#define C_STACK_H_INCLUDED

#define ASSERT_MODE
#ifdef NO_ASSERT_MODE
#undef ASSERT_MODE
#endif


int size_stack=0;
int top_stack=0;

int*create_stack(int size){
    size_stack=size;
    top_stack=0;
    return (int*)malloc(sizeof(int)*size);
}

void destroy_stack(int*stack){
    top_stack=0;
    size_stack=0;
    free(stack);
    stack=NULL;
}

void insert_stack(int**stack,int v){
    (*stack)[top_stack++]=v;
    if(top_stack==size_stack){
        size_stack*=2;
        *stack=(int*)realloc(*stack,size_stack*sizeof(int));
    }
}

int remove_stack(int**stack){
#ifdef ASSERT_MODE
    assert(top_stack>=0);
#endif
    int tmp=(*stack)[--top_stack];
    return tmp;
}

#endif // C_STACK_H_INCLUDED
