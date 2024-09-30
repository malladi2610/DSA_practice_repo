#include<iostream>
#include<bits/stdc++.h>
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
   
    for(int i = 0; i<c-1; i++){
       int mme = i;
        for(int j = i+1; j<c; j++){
            if(arr_c[j] < arr_c[mme]){
                mme = j;
            }
        }
            int temp = arr_c[i];
            arr_c[i] = arr_c[mme];
            arr_c[mme] = temp;
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

/*This code fails because of the selection  sort used which has the time complexity of O(n+m)^2*/

/* std::vector<int> remove_duplicates(int arr_c[], int c){
        
        int unique_element = 1;
        std::vector<int> result;
        for(int i = 1; i<c; i++){
            if(arr_c[i] != arr_c[i-1]){
                arr_c[unique_element] = arr_c[i];
                unique_element++;
            }
        }
        
        for(int i = 0; i < unique_element; i++) {
            result.push_back(arr_c[i]);
        }
    return result;

    }

    void selection_sort(int arr_c[], int c){
        for(int i = 0; i<c-1; i++){
            int mme = i;
            for(int j = i+1; j<c; j++){
                if(arr_c[j] < arr_c[mme]){
                    mme = j;
                }
            }
            int temp = arr_c[i];
            arr_c[i] = arr_c[mme];
            arr_c[mme] = temp;
        }
    }   

    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        int arr_c[500];
        int c;
        vector<int> res;
        c = n+m;
        
        for(int i = 0; i<n;i++){
            arr_c[i] = arr1[i];
        }
        for(int i = 0;i<m; i++){
            arr_c[i+n] = arr2[i];
        }
        selection_sort(arr_c, c);
        res = remove_duplicates(arr_c,c);
        return res;
    }*/

   /*The best simplification for this code is as follows
   1. There is no need to have any sorting mechnism and then remove the duplicates
   
   2. A direct simplification can be done at the initial stage itself, where in the process of creation of the array itself the filtering can be done*/

   vector<int> findunion(int arr1[], int arr2[], int n, int m){
        vector<int> res;
        int i = 0, j = 0;
        while(i < n && j < m){
            while(i > 0, i < n && arr1[i] == arr1[i-1]) i++;
            while(j > 0, j < m && arr2[j] == arr2[j-1]) j++;

            if(i < n && j < m){
                //This is done to make sure that the elements are pushed in ascending order
                if(arr1[i] < arr2[j]){
                    res.push_back(arr1[i]);
                    i++;
                }
                else if(arr1[i] > arr2[j]){
                    res.push_back(arr2[j]);
                }

                else{
                    res.push_back(arr1[i]);
                    i++;
                    j++;
                }
            }
        }

        while (i < n){
            while (i > 0 && i < n && arr1[i] == arr1[i-1]) i++;
            if(i < n){
                res.push_back(arr1[i]);
                i++;
            }
        }

        while (j < n){
            while ( j > 0 && j< m && arr2[j] == arr2[j-1]) j++;
            if(j < n){
                res.push_back(arr2[i]);
                j++;
            }

        }

        return res;


   }