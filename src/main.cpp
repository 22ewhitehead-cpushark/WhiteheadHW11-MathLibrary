//Accidently didn't make a template first, so had to paste code over from previous depository.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename a>

a absolute(a x){
    if (x>=0){
        return x;
    }
    else{
        return -1*x;
    }
}

template <typename p1>
p1 power(p1 x, int n){
    p1 y = x;
    if (n == 0){
        return 1;
    }
    else if (x == 0){
        return 0;
    }
    else{
        for (int i = 1; i < n; i++){
            y = y * x;
        }
        return y;
    }
}

long long factorial(int n){
    long long y = n;
    if (n==0){
        return 1;
    }
    else{
        for (int i = 1; i < n; i++){
            y = y * (n - i);
        }
        return y;
    }
}

template <typename s>
double squareRoot(s x){
    double a = x;
    bool done = false;
    if (x == 0){
        return 0;
    }
    else if(x<0){
        cout << "nan";
        return 0;
    }
    else{
        int i = 0;
        while(!done){
            a = (0.5)*(a+(x/a));
            if(a * a == x){
                done = true;
            }
            else if (i == 100){
                done = true;
            }
            else{
                done = false;
            }
            i++;
        }
        return a;
    }
}

double pi(){
    double n = 0.0;
    for (int i = 0; i < 16; i++){
        n = n + ((1/(power(16.0, i)))*
        ((4.0/((8*i)+1))
        -(2.0/((8*i)+4))
        -(1.0/((8*i)+5))
        -(1.0/((8*i)+6))));
    }
    return n;
}

template <typename T>
double sine(T x){
    double xd = static_cast<double>(x);
    double sinx = 0.0;
    int change;
    if (xd >= 0){
            change = 1;
        }
        else{
            change = -1;
        }
    xd = xd * change;
    while(xd > pi()){
        xd = (xd - pi())*-1;
    }
    for (int n = 0; n < 9; n++){
        sinx = sinx + (((power(-1.0, n))/(factorial((2*n)+1)))* power(xd, ((2*n)+1)));
    }
    return sinx * change;
}

template <typename T1>
double cosine(T1 x){
    double cosx = sine((pi() / 2.0) - x);
    return cosx;
}

template <typename T2> 
double tangent(T2 x){
    double tangentx = (sine(x) / cosine(x));
    return tangentx;
}

int main(){


    // absolute test
    cout << "my absolute(-2): " << absolute(-2)<< endl;
    cout << "std:: abs(-2): "<< abs(-2) << endl;
    cout << "my absolute(-3.9): " << absolute(-3.9)<< endl;
    cout << "std:: abs(-3.9): "<< abs(-3.9) << endl;
    cout << endl;

    //power test
    cout << "my power(1.5, 3): " << power(1.5, 3) << endl;
    cout << "std::pow(1.5, 3): " << pow(1.5,3) << endl;
    cout << "my power(3, 5): " << power(3,5) << endl;
    cout << "std::pow(3, 5): " << pow(3,5) << endl;
    cout << endl;

    //factorial test
    cout << "my factorial(0): " << factorial(0) << endl;
    cout << "my factorial(1): " << factorial(1) << endl;
    cout << "my factorial(6): " << factorial(6) << endl;
    cout << "my factorial(5): " << factorial(5) << endl;
    cout << endl;

    //square root test
    cout << "my squareRoot(0): " << squareRoot(0) << endl;
    cout << "std::sqrt(0): " << sqrt(0) << endl;
    cout << "my squareRoot(5): " << squareRoot(5) << endl;
    cout << "std::sqrt(5): " << sqrt(5) << endl;
    cout << "my squareRoot(-9): " << squareRoot(-9) << endl;
    cout << "std::sqrt(-9): " << sqrt(-9) << endl;
    cout << endl;

    //pi
    double pie;
    pie = pi();
    cout << "pi(): " << pi() << endl << endl;

    //sine
    cout << "my sine(-3): " << sine(-3) << endl;
    cout << "std::sin(-3): " << sin(-3) << endl;
    cout << "my sine(6): " << sine(6) << endl;
    cout << "std::sin(6): " << sin(6) << endl;
    cout << "my sine(5): " << sine(5) << endl;
    cout << "std::sin(5): " << sin(5) << endl << endl;

    //cosine
    cout << "my cosine(-4): " << cosine(-4) << endl;
    cout << "std::cos(-4): " << cos(-4) << endl;
    cout << "my cosine(0): " << cosine(0) << endl;
    cout << "std::cos(0): " << cos(0) << endl;
    cout << "my cosine(2): " << cosine(2) << endl;
    cout << "std::cos(2): " << cos(2) << endl << endl;

    //tangent
    cout << "my tangent(-2): " << tangent(-2) << endl;
    cout << "std::tan(-2): " << tan(-2) << endl;
    cout << "my tangent(0): " << tangent(0) << endl;
    cout << "std::tan(0): " << tan(0) << endl;
    cout << "my tangent(4): " << tangent(4) << endl;
    cout << "std::tan(4): " << tan(4) << endl;

    //provided tests
    cout << endl << endl;
    std::cout << std::setprecision(20);
    // pi() uses power(x, n)
    std::cout << "pi(): " << pi() << std::endl << std::endl;
    // squareRoot(x) uses absolute(x)
    std::cout << "squareRoot(2): " << squareRoot(2) << std::endl;
    std::cout << "squareRoot(6.75f): " << squareRoot(6.75f) << std::endl; std::cout << "squareRoot(15.99): " << squareRoot(15.99) << std::endl; std::cout << "squareRoot('a'): " << squareRoot('a') << std::endl;
    std::cout << "squareRoot(0): " << squareRoot(0) << std::endl;
    std::cout << "squareRoot(-1): " << squareRoot(-1) << std::endl << std::endl;
    // sine(x) uses factorial(n)
    std::cout << "sine(1): " << sine(1) << std::endl;
    std::cout << "sine(5.25f): " << sine(5.25f) << std::endl; std::cout << "sine(pi()): " << sine(pi()) << std::endl;
    std::cout << "sine(-5*pi()/2): " << sine(-5*pi()/2) << std::endl; std::cout << "sine('a'): " << sine('a') << std::endl << std::endl;
    std::cout << "cosine(1): " << cosine(1) << std::endl;
    std::cout << "cosine(5.25f): " << cosine(5.25f) << std::endl;
    std::cout << "cosine(pi()): " << cosine(pi()) << std::endl;
    std::cout << "cosine(-5*pi()/2): " << cosine(-5 * pi() / 2) << std::endl; std::cout << "cosine('a'): " << cosine('a') << std::endl << std::endl;
    std::cout << "tangent(1): " << tangent(1) << std::endl;
    std::cout << "tangent(5.25f): " << tangent(5.25f) << std::endl;
    std::cout << "tangent(pi()): " << tangent(pi()) << std::endl;
    std::cout << "tangent(-5*pi()/2): " << tangent(-5 * pi() / 2) << std::endl; std::cout << "tangent('a'): " << tangent('a') << std::endl;

return 0;
}
