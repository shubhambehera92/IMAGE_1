#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[],int st,int mid,int end){
    vector<int> temp;
    int i=st,j=mid+1;
    while(i<=mid&&j<=end){
        if(arr[i]<=arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=end) temp.push_back(arr[j++]);
    for(int idx=0;idx<temp.size();idx++)
        arr[st+idx]=temp[idx];
}

void mergeSort(int arr[],int st,int end){
    if(st<end){
        int mid=st+(end-st)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
}

int main(){
    int *arr=NULL,n,choice;
    do{
        cout<<"\n------MENU------\n";
        cout<<"1. Create Dynamic Array\n";
        cout<<"2. Display Array\n";
        cout<<"3. Merge Sort\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
        case 1:
            if(arr!=NULL) delete[] arr;
            cout<<"Enter number of elements: ";
            cin>>n;
            arr=new int[n];
            cout<<"Enter "<<n<<" Numbers\n";
            for(int i=0;i<n;i++) cin>>arr[i];
            break;

        case 2:
            if(arr==NULL) cout<<"Array not created\n";
            else display(arr,n);
            break;

        case 3:
            if(arr==NULL) cout<<"Array not created\n";
            else{
                mergeSort(arr,0,n-1);
                cout<<"Array sorted successfully\n";
                display(arr,n);
            }
            break;

        case 4:
            cout<<"Exiting.......\n";
            break;

        default:
            cout<<"Invalid Choice\n";
        }
    }while(choice!=4);

    delete[] arr;
    return 0;
}
