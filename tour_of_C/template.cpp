



import std;

export
template<typename T>

void print(std::vector<T>& V){
    std::cout<<"{\n";
    for (const T& val: v)
        std::cout << " " << val <<'\n';
        cout << '}';
}