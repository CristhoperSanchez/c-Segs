#include <iostream>


using namespace std;




struct Vector {
    double * elem;
    int sz;
};


void vector_init(Vector&v, int s){
    v.elem = new double[s];
    v.sz = s;
};


double read_and_sum(int s){
    Vector v;

    vector_init(v,s);

    for(int i=0; i!=s; ++i) cin >> v.elem[i];

    double sum = 0;

    for(int i=0; i!=s; ++i) sum +=v.elem[i];
    

    return sum;
}




int main(){

    double mySum;

    mySum = read_and_sum(6);
    std::cout << "My sum: " << mySum << std::endl;

    return 0;
};