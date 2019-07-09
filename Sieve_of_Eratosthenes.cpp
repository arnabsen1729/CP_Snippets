#include<bits/stdc++.h>
using namespace std;
/* SIEVE OF ERATOSTHENES:-

    It is used to check for prime, involves precomputation.
    SIZE: The largest number to be checked
    N.B make sure the data types used are compatible with SIZE
        and avoid overflow

    Time complexity : O(n*log(log(n)))
*/

//-------------------------------------------------------
#define SIZE 100

bool is_prime[SIZE];

void sieve(){
    is_prime[0]=false;
    is_prime[1]=false;
    for(int i=2; i*i<=SIZE; i++){
        if(is_prime[i]){
            for(int p=i*i; p<SIZE; p+=i)
                is_prime[p]=false;
        }
    }
}

//-------------------------------------------------------

main(){
    memset(is_prime, true, sizeof(is_prime));
    sieve();
    return 0;
}
