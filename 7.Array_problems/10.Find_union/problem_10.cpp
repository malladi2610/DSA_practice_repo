#include<iostream>
using namespace std;
// void selection_sort(int arr_c, int c);
// void remove_duplicates(int arr_c, int c);

void remove_duplicates(int arr_c[], int c){

    int unique_element = 1;
    for(int i = 1; i<c; i++){
        if(arr_c[i] != arr_c[i-1]){
            arr_c[unique_element] = arr_c[i];
            unique_element++;
        }
        
    }

    cout<<"The new array is:";
    for(int i = 0; i<unique_element;i++){
        cout<<arr_c[i]<<" ";
    }
    cout<<endl;

}

void selection_sort(int arr_c[], int c){
    int mme = 0;
    for(int i = 0; i<c-1; i++){
        mme = i;
        for(int j = i+1; j<c; j++){
            if(arr_c[j] < arr_c[i]){
                mme = j;
            }
            int temp = arr_c[i];
            arr_c[i] = arr_c[mme];
            arr_c[mme] = temp;
        }
    }

    cout<<"The sorted array is as follows";
    for(int i = 0;i<c;i++){
        cout<<arr_c[i]<<" ";
    }
    cout<<endl;
}

void find_union(int arr_n[], int arr_m[], int n, int m){
    int arr_c[500];
    int c;
    c = n+m;
cout<<"The combined arrays is as follows : ";
    for(int i = 0; i<n;i++){
        arr_c[i] = arr_n[i];
    }
    for(int i = 0;i<m; i++){
        arr_c[i+n] = arr_m[i];
    }
    for(int i = 0; i<c; i++){
        cout<<arr_c[i]<<endl;
    }
    selection_sort(arr_c, c);
    remove_duplicates(arr_c,c);

}






int main(){
    int arr_n[100];
    int arr_m[100];
    int n,m;

    cout<<"Enter the no.of elements of the first array : ";
    cin>>n;

    cout<<"Enter the no.of elements of the second array :";
    cin>>m;

    cout<<"Enter the elements of the first array";
    for(int i = 0; i<n; i++){
        cin>>arr_n[i];
    }

    cout<<"Enter the elements of the second array";
    for(int i = 0; i< m; i++){
        cin>>arr_m[i];
    }

    find_union(arr_n, arr_m, n, m);

}