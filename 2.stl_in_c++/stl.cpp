/*This is the part of the striver stl teaching video*/
/*There is a  error which is experienced due to the "#include<bits/stdc++.h> file", it can be solve by following this link https://github.com/microsoft/vscode-cpptools/discussions/11279*/
/*Tried ChatGPT 4.0 it didn't give the right answer, Google is still the boss 😎[2024]*/

#include<bits/stdc++.h>
//#include<unordered_set>
using namespace std;

// void my_unordered_set(){
//     unordered_set <int> s;
//     for (int i = 1; i <= 10 ; i++){
//         s.insert(i);
//     }

//     cout<<"Print the elements of the unordered list";
//     for(auto it = s.begin(); it != s.end(); it++){
//         cout<< * it << " ";
//     }
//     cout << endl;

//     int n = 2;
//     if( s.find(2) != s.end())
//         cout<<n<<"It is present in the unorderd set"<<endl;

//     s.erase(s.begin());
//     cout << "Elements after deleting the first element: ";
//     for(auto it = s.begin(); it != s.end(); it++){
//         cout<< * it << " ";
//     }
//     cout << endl;

//     cout<<"The size of the unordered set is: "<<s.size()<<endl;

//     if(s.empty() == false){
//         cout<<"The unordered set is not empty"<<endl;
//     }
//     else
//         cout<<"The unordered set is empty"<<endl;
//     s.clear();
//     cout << "Size of the unordered set after clearing all the elements: "<<s.size()<<endl;
//     cout<<"--------------------------------------------------------------"<<endl;
// }

// void my_vectors(){
//     vector <int> v;

//     for(int i = 0; i <10; i++){
//         v.push_back(i); //Used to insert the elements
//     }

//     cout << "The elements in the vector: ";
//     for (auto it = v.begin(); it != v.end(); it++)
//         cout<< * it << " ";

//     cout<< "\nThe front element of the vector: "<<v.front();
//     cout<<"\nThe last element of the vector: "<<v.back();
//     cout<<"\nThe size of the vector: "<<v.size();
//     cout<<"\nDeleting element from the end: "<<v[v.size() - 1];
//     v.pop_back();

//     cout<<"\nPrinting the vector after removing the last element: "<<endl;
//     for(int i = 0;i<v.size();i++){
//         cout<<v[i]<< " ";
//     }
//     cout<<endl;

//     cout<<"Size of the vector after clearing the vector: "<<v.size()<<endl;
//     cout<<"----------------------------------------------"<<endl;
// }

// void my_set(){
//     set <int> s;
//     for(int i = 0; i<=5; i++){
//         s.insert(i);
//     }

//     cout<<"The elements of the set are :";
//     for(auto it = s.begin(); it != s.end(); it++){
//         cout<< *it << " ";
//     }

//     cout<<endl;

//     int n = 2;
//     if(s.find(2) != s.end())
//     cout<<n<<"is present in set"<<endl;

//     s.erase(s.begin());
//     cout<< "Elements after deleating the first element: ";
//     for(auto it = s.begin(); it != s.end(); it++){
//         cout<< *it << " ";
//     }
//     cout<<endl;

//     cout << "The size of the set is: "<<s.size()<<endl;
//     if(s.empty() == false)
//         cout<<"The set is not empty"<<endl;
//     else
//         cout<<"The set is empty"<<endl;
//     s.clear();
//     cout<<"Size of the set after clearing all the elements: "<<s.size();
// }

// void my_unordered_multiset(){
//     unordered_multiset<int> s;
//     for (int i = 1;i<=10;i++){
//         s.insert(i);
//     }

//     s.insert(5);
//     cout<<"Elements present in the unordered multiset: ";
//     for(auto it = s.begin();it != s.end();it++){
//         cout<<*it<<" ";
//     }
//     cout<<endl;

//     int n = 5;
//     if(s.find(5) != s.end())
//         cout<<n<<"is present in unordered multiset"<<endl;
    
//     cout<<"No.of elements of the 5 in the multiset"<<s.count(5);

//     s.erase(s.begin());
//     cout<<"Elements after deleting the first element:";
//     for(auto it = s.begin(); it != s.end();it++){
//         cout<<*it<<" ";
//     }
//     cout<<endl;

//     cout<<"The size of the unordered multiset is: "<<s.size()<<endl;

//     if(s.empty() == false)
//         cout<<"The unordered multiset is not empty"<<endl;
//     else
//         cout<<"The unordered multiset is empty"<<endl;
//     s.clear();
//     cout<<"Size of the unordered multiset after clearing all the elements: "<<s.size();

// }

// void my_multiset(){
//     multiset < int > s;
//   for (int i = 1; i <= 10; i++) {
//     s.insert(i);
//   }
//   s.insert(5);
//   cout << "Elements present in the multiset: ";
//   for (auto it = s.begin(); it != s.end(); it++) {
//     cout << * it << " ";
//   }
//   cout << endl;
//   int n = 2;
//   if (s.find(2) != s.end())
//     cout << n << " is present in multiset" << endl;

//   s.erase(s.begin());
//   cout << "Elements after deleting the first element: ";
//   for (auto it = s.begin(); it != s.end(); it++) {
//     cout << * it << " ";
//   }
//   cout << endl;

//   cout << "The size of the multiset is: " << s.size() << endl;

//   if (s.empty() == false)
//     cout << "The multiset is not empty " << endl;
//   else
//     cout << "The multiset is empty" << endl;
//   s.clear();
//   cout << "Size of the multiset after clearing all the elements: " << s.size();
// }

void my_maps(){
    map<int,int> mp; //It's like a dictionary
    for(int i = 1; i<=5;i++){
        mp.insert({i,i*10});
    }

    cout<< "Elements present in the map: "<<endl;
    cout<<"key\tElement"<<endl;
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<< it -> first << "\t" << it->second<<endl;
    }

    int n = 2;
    if(mp.find(2) != mp.end())
        cout<<n<<"is present in map"<<endl;
    
    mp.erase(mp.begin());
    cout << "Elements after deleting the first element: "<<endl;
    cout << "Key\tElement" <<endl;
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<<it -> first << "\t"<<it->second<<endl;
    }

    cout<<"The size of the map is:"<<mp.size()<<endl;

    if(mp.empty() == false)
    cout<<"The map is not empty"<<endl;
    else
    cout<<"The map is empty"<<endl;
    mp.clear();

    cout<<"Size of the map after clearing all the elements: "<<mp.size();
    
}

void my_unorderedmap(){
    unordered_map<int,int> mp; //It's like a dictionary
    for(int i = 1; i<=5;i++){
        mp.insert({i,i*10});
    }

    cout<< "Elements present in the unorderd map: "<<endl;
    cout<<"key\tElement"<<endl;
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<< it -> first << "\t" << it->second<<endl;
    }

    int n = 2;
    if(mp.find(2) != mp.end())
        cout<<n<<"is present in unordered map"<<endl;
    
    mp.erase(mp.begin());
    cout << "Elements after deleting the first element: "<<endl;
    cout << "Key\tElement" <<endl;
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<<it -> first << "\t"<<it->second<<endl;
    }

    cout<<"The size of the unordered map is:"<<mp.size()<<endl;

    if(mp.empty() == false)
    cout<<"The map is not empty"<<endl;
    else
    cout<<"The map is empty"<<endl;
    mp.clear();

    cout<<"Size of the map after clearing all the elements: "<<mp.size();
    
}


int main(){
    // my_unordered_set();
    // my_vectors();
    // my_set();
    // my_unordered_multiset();
    // my_multiset();
    my_maps();
    my_unorderedmap();
}


