#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> my_num{1,2,3,4,5,6};
    for(int i=0;i<my_num.size();i++){
       if(my_num.at(i)==1){  //print the content of the vector
        cout<<"ONE"<<"\n";
        break;
       }
       else{
        cout<<"GOOG"<<"\n";
       }
    }
    return 0;
}
