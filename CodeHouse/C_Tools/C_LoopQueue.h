#ifndef C_LOOPQUEUE_H_INCLUDED
#define C_LOOPQUEUE_H_INCLUDED
#define ASSERT_MODE
#ifdef NO_ASSERT_MODE
#undef ASSERT_MODE
#endif

int size_loopqueue;

typedef struct LinkNode{
    struct LinkNode*next;
    struct LinkNode*prev;
    void*data_p;
}LoopQueueNode;

LoopQueueNode*create_loopqueue(void*dataptr){
    size_loopqueue=1;
    LoopQueueNode*newNode=(LoopQueueNode*)malloc(sizeof(LoopQueueNode));
    newNode->next=newNode;
    newNode->prev=newNode;
    newNode->data_p=dataptr;
    return newNode;
}


int push_loopqueue(LoopQueueNode**r,void*dataptr){
    LoopQueueNode*newNode=(LoopQueueNode*)malloc(sizeof(LoopQueueNode));
#ifdef ASSERT_MODE
    assert(newNode!=NULL);
#endif
    if(size_loopqueue==0){
        newNode->next=newNode;
        newNode->prev=newNode;
        newNode->data_p=dataptr;
        *r=newNode;
        size_loopqueue++;
        return size_loopqueue;
    }else{
        newNode->data_p=dataptr;
        newNode->next=(*r);
        newNode->prev=(*r)->prev;
        (*r)->prev->next=newNode;
        (*r)->prev=newNode;
        size_loopqueue++;
        return size_loopqueue;
    }
}

void*pop_loopqueue(LoopQueueNode**r){
#ifdef ASSERT_MODE
    assert(size_loopqueue>0);
#endif
    if(size_loopqueue==1){
        LoopQueueNode*ret=(*r)->data_p;
        free(*r);
        *r=(LoopQueueNode*)NULL;
        size_loopqueue--;
        return ret;
    }else{
        void*ret=(*r)->data_p;
        LoopQueueNode*tmp=*r;
        (*r)->prev->next=(*r)->next;
        (*r)->next->prev=(*r)->prev;
        (*r)=(*r)->next;
        free(tmp);
        size_loopqueue--;
        return ret;
    }
}

void next_loopqueue(LoopQueueNode**r){
    *r=(*r)->next;
}

void prev_loopqueue(LoopQueueNode**r){
    *r=(*r)->prev;
}

void scan_loopqueue(LoopQueueNode**r,void(*op)(void*)){
    int i;
    for(i=0;i<size_loopqueue;i++){
        op((*r)->data_p);
        (*r)=(*r)->next;
    }
}

void*search_loopqueue(LoopQueueNode**r,void*dataptr){
    int i;
    for(i=0;i<size_loopqueue;i++){
        if((*r)->data_p==dataptr)return (*r)->data_p;
        (*r)=(*r)->next;
    }
    return NULL;
}


#endif // C_LOOPQUEUE_H_INCLUDED
