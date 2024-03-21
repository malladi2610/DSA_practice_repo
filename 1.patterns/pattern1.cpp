#include<iostream>

using namespace std;

/*A pattern of this form is needs to be generated is as follows
*****                       
*****
*****
*****
*****
*****

To generate this pattern we will be needing a for loop that print in rows of 5 and then another for loop that prints in column of 5
*/
int main(){
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cout<< "*";
        }
cout<<"\n";
    }

}