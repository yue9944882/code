#ifndef C_MERGESORTING_H_INCLUDED
#define C_MERGESORTING_H_INCLUDED

#define ASSERT_MODE
#include<memory.h>

#ifdef NO_ASSERT_MODE
#undef ASSERT_MODE
#endif
void ascend_mergesort(int*,int);
void descend_mergesort(int*,int);

/////////////////////////////////////////

void _asc_merge(int*data,int*tmp,int low,int mid,int high){
    int i,j,pos;
    for(pos=low,i=low,j=mid+1;i<=mid&&j<=high;pos++){
        if(data[i]<=data[j])tmp[pos]=data[i++];
        else tmp[pos]=data[j++];
    }
    if(i<=mid){
        for(;i<=mid;pos++)tmp[pos]=data[i++];
    }
    if(j<=high){
        for(;j<=high;pos++)tmp[pos]=data[j++];
    }
    memcpy(data+low,tmp+low,(high-low+1)*sizeof(int));
}

void _desc_merge(int*data,int*tmp,int low,int mid,int high){
    int i,j,pos;
    for(pos=low,i=low,j=mid+1;i<=mid&&j<=high;pos++){
        if(data[i]>=data[j])tmp[pos]=data[i++];
        else tmp[pos]=data[j++];
    }
    if(i<=mid){
        for(;i<=mid;pos++)tmp[pos]=data[i++];
    }
    if(j<=high){
        for(;j<=high;pos++)tmp[pos]=data[j++];
    }
    memcpy(data+low,tmp+low,(high-low+1)*sizeof(int));
}


void _ascend_mergesort(int*data,int*tmp,int low,int high){
    if(low==high)return;
    else{
        int mid=(low+high)/2;
        _ascend_mergesort(data,tmp,low,mid);
        _ascend_mergesort(data,tmp,mid+1,high);
        _asc_merge(data,tmp,low,mid,high);
    }
}


void _descend_mergesort(int*data,int*tmp,int low,int high){
    if(low==high)return;
    else{
        int mid=(low+high)/2;
        _descend_mergesort(data,tmp,low,mid);
        _descend_mergesort(data,tmp,mid+1,high);
        _desc_merge(data,tmp,low,mid,high);
    }
}

void ascend_mergesort(int*data,int size){
#ifdef ASSERT_MODE
    assert(0<size);
#endif
    int*tmp=(int*)malloc(sizeof(int)*size);
    _ascend_mergesort(data,tmp,0,size-1);
    int p=0;
    for(p=0;p<=size-1;p++)data[p]=tmp[p];
    free(tmp);
}


void descend_mergesort(int*data,int size){
#ifdef ASSERT_MODE
    assert(0<size);
#endif
    int*tmp=(int*)malloc(sizeof(int)*size);
    _descend_mergesort(data,tmp,0,size-1);
    int p=0;
    for(p=0;p<=size-1;p++)data[p]=tmp[p];
    free(tmp);
}


#endif // C_MERGESORTING_H_INCLUDED
