#ifndef C_QUICKSORTING_H_INCLUDED
#define C_QUICKSORTING_H_INCLUDED

#define ASSERT_MODE

#ifdef NO_ASSERT_MODE
#undef ASSERT_MODE
#endif

void ascend_quicksort(int*,int);
void descend_quicksort(int*,int);

////////////////////////////////////

void swap(int*l,int*r){
    int tmp=*l;
    *l=*r;
    *r=tmp;
}


void _desc_partition_quicksort(int*data,int low,int high){
    if(low>=high)return;
    int pivotpos=low;
    int pivot=data[low];
    int i=low+1;
    for(;i<=high;i++){
        if(data[i]>pivot){
            pivotpos++;
            swap(&data[pivotpos],&data[i]);
        }
    }
    data[low]=data[pivotpos];
    data[pivotpos]=pivot;
    _desc_partition_quicksort(data,low,pivotpos-1);
    _desc_partition_quicksort(data,pivotpos+1,high);
}



void _asc_partition_quicksort(int*data,int low,int high){
    if(low>=high)return;
    int pivotpos=low;
    int pivot=data[low];
    int i=low+1;
    for(;i<=high;i++){
        if(data[i]<pivot){
            pivotpos++;
            swap(&data[pivotpos],&data[i]);
        }
    }
    data[low]=data[pivotpos];
    data[pivotpos]=pivot;
    _asc_partition_quicksort(data,low,pivotpos-1);
    _asc_partition_quicksort(data,pivotpos+1,high);
}



void ascend_quicksort(int*data,int size){
#ifdef ASSERT_MODE
    assert(0<size);
#endif
    _asc_partition_quicksort(data,0,size-1);
}


void descend_quicksort(int*data,int size){
#ifdef ASSERT_MODE
    assert(0<size);
#endif
    _desc_partition_quicksort(data,0,size-1);
}


#endif // C_QUICKSORTING_H_INCLUDED
