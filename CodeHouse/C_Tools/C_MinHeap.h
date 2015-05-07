#ifndef C_MINHEAP_H_INCLUDED
#define C_MINHEAP_H_INCLUDED

//////////////////
/*int*create_minheap(size_t);
void destroy_minheap(int*);
void filterDown_minheap(int*);
void filterUp_minheap(int*);
void insert_minheap(int*,int);
void remove_minheap(int*);
int top_minheap(int*);*/
#define ASSERT_MODE

#ifdef NO_ASSERT_MODE
#undef ASSERT_MODE
#endif

//////////////////

int min_heap_size=0;
int min_heap_top=0;


void swap(int*l,int*r){
    int tmp=*l;
    *l=*r;
    *r=tmp;
}

int* create_minheap(int size){
    min_heap_size=size;
    min_heap_top=0;
    return (int*)malloc(size*sizeof(int));
}

void destroy_minheap(int*heap){
    free(heap);
    min_heap_size=0;
    min_heap_top=0;
}

void filterDown_minheap(int*heap){
    int parent=0;
    int child=0;
    if(parent*2+2>min_heap_top){
        return;
    }else if(parent*2+2==min_heap_top){
        child=parent*2+1;
    }else{
        child=heap[parent*2+1]<heap[parent*2+2]?parent*2+1:parent*2+2;
    }
    while(heap[parent]>heap[child]){
        swap(&heap[parent],&heap[child]);
        parent=child;
        if(parent*2+2>min_heap_top){
            break;
        }else if(parent*2+2==min_heap_top){
            child=parent*2+1;
        }else{
            child=heap[parent*2+1]<heap[parent*2+2]?parent*2+1:parent*2+2;
        }
    }
}

void filterUp_minheap(int*heap){
    int child=min_heap_top-1;
    int parent=(child-1)/2;
    while(heap[child]<heap[parent]){
        if(child==0&&parent==0)break;
        swap(&heap[parent],&heap[child]);
        child=parent;
        parent=(child-1)/2;
    }
}


void insert_minheap(int*heap,int value){
#ifdef ASSERT_MODE
    assert(min_heap_top<min_heap_size);
#endif
    heap[min_heap_top]=value;
    min_heap_top++;
    filterUp_minheap(heap);
}

void remove_minheap(int*heap){
#ifdef ASSERT_MODE
    assert(min_heap_top>0);
#endif
    heap[0]=heap[--min_heap_top];
    filterDown_minheap(heap);
}

int top_minheap(int*heap){
#ifdef ASSERT_MODE
    assert(min_heap_top>0);
#endif
    return heap[0];
}



#endif // C_MINHEAP_H_INCLUDED
