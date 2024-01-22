#include <iostream>

int main(){


    int x = [](int a, int b) -> int{
        return a + b;
    }(3, 4);

    std::cout << x << "\n";
    
    return 0;
}

