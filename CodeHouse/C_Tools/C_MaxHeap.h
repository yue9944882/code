#ifndef C_MAXHEAP_H_INCLUDED
#define C_MAXHEAP_H_INCLUDED

//////////////////
/*int*create_maxheap(size_t);
void destroy_maxheap(int*);
void filterDown_maxheap(int*);
void filterUp_maxheap(int*);
void insert_maxheap(int*,int);
void remove_maxheap(int*);
int top_maxheap(int*);*/
#define ASSERT_MODE

#ifdef NO_ASSERT_MODE
#undef ASSERT_MODE
#endif

//////////////////

int max_heap_size=0;
int max_heap_top=0;


void swap(int*l,int*r){
    int tmp=*l;
    *l=*r;
    *r=tmp;
}

int* create_maxheap(int size){
    max_heap_size=size;
    max_heap_top=0;
    return (int*)malloc(size*sizeof(int));
}

void destroy_maxheap(int*heap){
    free(heap);
    max_heap_size=0;
    max_heap_top=0;
}

void filterDown_maxheap(int*heap){
    int parent=0;
    int child=0;
    if(parent*2+2>max_heap_top){
        return;
    }else if(parent*2+2==max_heap_top){
        child=parent*2+1;
    }else{
        child=heap[parent*2+1]>heap[parent*2+2]?parent*2+1:parent*2+2;
    }
    while(heap[parent]<heap[child]){
        swap(&heap[parent],&heap[child]);
        parent=child;
        if(parent*2+2>max_heap_top){
            break;
        }else if(parent*2+2==max_heap_top){
            child=parent*2+1;
        }else{
            child=heap[parent*2+1]>heap[parent*2+2]?parent*2+1:parent*2+2;
        }
    }
}

void filterUp_maxheap(int*heap){
    int child=max_heap_top-1;
    int parent=(child-1)/2;
    while(heap[child]>heap[parent]){
        if(child==0&&parent==0)break;
        swap(&heap[parent],&heap[child]);
        child=parent;
        parent=(child-1)/2;
    }
}


void insert_maxheap(int*heap,int value){
#ifdef ASSERT_MODE
    assert(max_heap_top<max_heap_size);
#endif
    heap[max_heap_top]=value;
    max_heap_top++;
    filterUp_maxheap(heap);
}

void remove_maxheap(int*heap){
#ifdef ASSERT_MODE
    assert(max_heap_top>0);
#endif
    heap[0]=heap[--max_heap_top];
    filterDown_maxheap(heap);
}

int top_maxheap(int*heap){
#ifdef ASSERT_MODE
    assert(max_heap_top>0);
#endif
    return heap[0];
}

#endif // C_MAXHEAP_H_INCLUDED
