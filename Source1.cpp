#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
//#include <_USE_MATH_DEFINES>
using namespace std;

long long goes =0, num1 =1;
static int fab(int n) { //((1+5^0.5)^n -(1-5^0.5)^n))/2^n *5^0.5
    ++goes;
    if (n == 2) {
        return 1;
    }
    else if (n < 2) {
        return 0;
    }
    else {
        return fab(n - 1) + fab(n - 2);
    }
}

static void fib(int n) {
    for (int i = 1; i <= n; i++) {
        ++goes;
        cout << ((pow((1 + sqrt(5)), i)) - pow((1 - sqrt(5)), i)) / (pow(2, i) * sqrt(5)) << i << endl;
    }
}

static int nSum(int n) {
    ++goes;
    cout << goes << "\n";
    if (n < 1) {
        return 0;
    }
    else {
        num1 = nSum(static_cast<long long>(n) - 1) + static_cast<long long>(n);
        cout << num1 << "\n";
        return num1;
    }
}

static void isPrime(long long n) {
    vector<long long> primes = {2};
    for (long long i = 3; i <= n; i++) {
        bool prime = true;
        int index = 0;
        for(long long primeN: primes) {
            goes++;
            if (primeN >= i / 2) {
                break;
            }
            if (i % primeN == 0) {
                prime = false;
                cout << i << " Not prime " << primeN << endl;
                break;
               // index++;
        }
        
        //for (long long a = 2; a <= (i / 2); a++) {
            //goes++;
            //if (i % a == 0) {
                //prime = false;
                //cout << i << " Not prime " << a << endl;
                //break;
            //}
        }
        if (prime) {
            primes.push_back(i);
            cout << i << " Prime" << endl;
        }
        }
    }

static int gamble(int n) {
    //wager 30%, get it back plus 50%, 'even' chance
    double money = n;
    double payout = 0;
    srand((unsigned)time(NULL));
    while (money > 10 and goes<1000) {
        goes++;
        //cout << payout << endl;
        double bet = money * 0.2;
        money = money - bet;
        int random = rand();
        cout << random << endl;
        if (random % 2 == 0 or true) {
           payout = payout + bet*1.50;
           cout << "win" << endl;
        }
        else {
          // money = money - bet;
            cout << "loss" << endl;
        }
    }
    return payout;
}

static int monty(int n) {
    for (int i; i < n; i++) {
        srand((unsigned)time(NULL));
        int random = rand();
        int door_picked = random % 3;
        srand((unsigned)time(NULL));
        random = rand();
        int car = random % 3;
    }
    
  
}

static long double zval(double z) {
    long double pi = 3.141592653589793238462643383279502884197169399375105820974944;
    long double ans = (1 / sqrt(2 * pi)) * ((sqrt(pi) * (erf(0.5 * sqrt(2) * z)) / sqrt(2))-(sqrt(pi)*(-1/sqrt(2))));
    return ans;
}

static void dice_checker(long sims, long trys) {
    srand((unsigned)time(NULL));
    //RAND_MAX = 5;
    long within = 0;
    long below = 0;
    long above = 0;
    for (long i = 0; i < sims; i++) {
        int num = rand() % 6+1;
        long hit = 0;
        for (long t = 0; t < trys; t++) {
            int num_2 = rand() % 6+1;
            if (num == num_2) {
                hit++;
            }
        }
        long double p_hat = static_cast<long double>(hit) / trys;
        long double expected = trys / static_cast<long double>(6);
        long double low_val = p_hat - 1.96 * (sqrt((p_hat * (1 - p_hat) / trys)));
        long double high_val = p_hat + 1.96 * (sqrt((p_hat * (1 - p_hat) / trys)));
        if (p_hat >= low_val and p_hat <= high_val) {
            within++;
        }
        else {
            if (p_hat < low_val) {
                below++;
            }
            else {
                above++;
            }
        }
    }
    cout << "Within:" << within << ", Below:" << below << ", Above:" << above;
}
int main() {
    //long long result = fab(20);
    //long long result = nSum(3000);
    //cout << result << "\n";
    //long long num1 = 1;
    //while (num1 > 0){
      //  ++goes;
        //num1 = num1 + goes;
        //cout << num1 << "\n";
    //}
    //isPrime(1000000000);
    //cout << gamble(1200) << endl;
    //fib(1000);
    //while (true){
        //long double z;
        //cout << "Please entre a z value: ";
        //cin >> z;
        //cout << zval(z) << endl;
    //}
    //for (long double z = -3; z <= 3; z += 0.0001) {
        //cout << z << ": " << zval(z) << endl;
    //}
    dice_checker(100000, 60000);
    //cout << goes;
    return 1;
}
