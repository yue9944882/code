#ifndef C_PTRSTACK_H_INCLUDED
#define C_PTRSTACK_H_INCLUDED
#define ASSERT_MODE
#ifdef NO_ASSERT_MODE
#undef ASSERT_MODE
#endif


int size_ptrstack=0;
int top_ptrstack=0;

void**create_ptrstack(int size){
    size_ptrstack=size;
    top_ptrstack=0;
    return (void**)malloc(sizeof(void*)*size);
}

void destroy_ptrstack(void**stack){
    top_ptrstack=0;
    size_ptrstack=0;
    free(stack);
    stack=NULL;
}

void insert_ptrstack(void***stack,void* v){
    (*stack)[top_ptrstack++]=v;
    if(top_ptrstack==size_ptrstack){
        size_ptrstack*=2;
        *stack=(void**)realloc(*stack,size_ptrstack*sizeof(void*));
    }
}

void* remove_ptrstack(void***stack){
#ifdef ASSERT_MODE
    assert(top_ptrstack>=0);
#endif
    void* tmp=(*stack)[--top_ptrstack];
    return tmp;
}


#endif // C_PTRSTACK_H_INCLUDED
