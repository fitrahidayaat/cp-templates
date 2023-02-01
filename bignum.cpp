#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXDIGITS 5000       /* maximum length bignum */
#define PLUS 1              /* positive sign bit */
#define MINUS -1            /* negative sign bit */

typedef struct {
    char digits[MAXDIGITS]; /* represent the number */
    int signbit;            /* PLUS or MINUS */
    int lastdigit;          /* index of high-order digit */
} bignum;

void zero_justify(bignum *n);
ll compare_bignum(bignum *a, bignum *b);
void subtract(bignum *a, bignum *b, bignum *c);
void add(bignum *a, bignum *b, bignum *c);
void print_bignum(bignum *n);
void string_to_bignum(string s);
void multiply(bignum *a, bignum *b, bignum *c);
void digit_shift(bignum *n, ll d);
void divide(bignum *a, bignum *b, bignum *c);
void initialize_bignum(bignum *n);
void int_to_bignum(ll s, bignum *n);
void modulo(bignum *a, bignum *b, bignum *c);

void int_to_bignum(ll s, bignum *n){
    ll i;
    ll t;

    if(s>=0) n->signbit = PLUS;
    else n->signbit = MINUS;

    memset(n->digits, 0, sizeof n->digits);

    n->lastdigit = -1;

    t = abs(s);
    while(t > 0){
        n->lastdigit++;
        n->digits[n->lastdigit] = t%10;
        t /= 10;
    }
    if(s == 0) n->lastdigit = 0;
}

void initialize_bignum(bignum *n){
    memset(n->digits, 0, sizeof n->digits);
    n->signbit = PLUS;
    n->lastdigit = -1;
}

void divide(bignum *a, bignum *b, bignum *c){
    bignum row;
    bignum tmp;
    ll i,j;
    initialize_bignum(c);
    c->signbit = a->signbit * b->signbit;
    ll signa = a->signbit, signb = b->signbit;
    a->signbit = PLUS;
    b->signbit = PLUS;
    initialize_bignum(&row);
    initialize_bignum(&tmp);

    c->lastdigit = a->lastdigit;

    for(i = a->lastdigit; i >= 0; i--){
        digit_shift(&row, 1);
        row.digits[0] = a->digits[i];
        c->digits[i] = 0;
        while(compare_bignum(&row, b) != PLUS){
            c->digits[i]++;
            subtract(&row, b, &tmp);
            row = tmp;
        }
    }
    zero_justify(c);
    a->signbit = signa;
    b->signbit = signb;
}
void digit_shift(bignum *n, ll d){
    ll i;
    if((n->lastdigit==0) && (n->digits[0] == 0)) return;
    for(i = n->lastdigit; i >= 0; i--){
        n->digits[i+d] = n->digits[i];
    }
    for(i = 0; i < d; i++) n->digits[i] = 0;
    n->lastdigit = n->lastdigit + d;

}

void multiply(bignum *a, bignum *b, bignum *c){
    bignum row;
    bignum tmp;
    int i, j;
    initialize_bignum(c);
    row = *a;
    for(i = 0; i <= b->lastdigit; i++){
        for(j = 1; j <= b->digits[i]; j++){
            add(c, &row, &tmp);
            *c = tmp;
        }
        digit_shift(&row, 1);
    }
    c->signbit = a->signbit * b->signbit;
    zero_justify(c);
}

void string_to_bignum(string s, bignum *n){
    ll i;
    string t;
    initialize_bignum(n);
    if(s[0] == '-'){
        n->signbit = MINUS;
        t = s.substr(1);
    } else{
        n->signbit = PLUS;
        t = s;
    }
    n->lastdigit = -1;
    for(i = t.size() - 1; i >= 0; i--){
        n->lastdigit++;
        n->digits[n->lastdigit] = t[i] - '0';
    }
    if(s == "0") n->lastdigit = 0;
}

void zero_justify(bignum *n){
    while((n->lastdigit > 0) && (n->digits[n->lastdigit] == 0)){
        n->lastdigit--;
    }
    if((n->lastdigit == 0) && (n->digits[0] == 0)){
        n->signbit = PLUS;      /* hack to avoid -0 */
    }
}

ll compare_bignum(bignum *a, bignum *b){
    ll i;
    
    if((a->signbit == MINUS) && (b->signbit == PLUS)) return PLUS;
    if((a->signbit == PLUS) && (b->signbit == MINUS)) return MINUS;

    if(b->lastdigit > a->lastdigit) return (PLUS * a->signbit);
    if(a->lastdigit > b->lastdigit) {
        return (MINUS * a->signbit);
    }

    for(i = a->lastdigit; i >= 0; i--){
        if(a->digits[i] > b->digits[i]){
            return (MINUS * a->signbit);
        }
        if(b->digits[i] > a->digits[i]){
            return (PLUS * a->signbit);
        }
    }
    return 0;
}

void subtract(bignum *a, bignum *b, bignum *c){
    ll borrow;
    ll v;
    ll i;
    if((a->signbit == MINUS) || (b->signbit == MINUS)){
        b->signbit = -1 * b->signbit;
        add(a,b,c);
        b->signbit = -1*b->signbit;
        return;
    }

    if(compare_bignum(a,b) == PLUS){
        subtract(b,a,c);
        c->signbit = MINUS;
        return;
    }

    c->lastdigit = max(a->lastdigit, b->lastdigit);
    borrow = 0;
    for(i = 0; i <= (c->lastdigit); i++){
        v = (a->digits[i] - borrow - b->digits[i]);
        if(a->digits[i] > 0){
            borrow = 0;
        }
        if(v < 0){
            v = v + 10;
            borrow = 1;
        }
        c->digits[i] = (char) v%10;
    }
    zero_justify(c);
}

void print_bignum(bignum *n){
    ll i;

    if (n->signbit == MINUS) cout << "-";
    for(i = n->lastdigit; i >= 0; i--){
        cout << (ll)n->digits[i];
    }
    cout << " ";
}

void add(bignum *a, bignum *b, bignum *c){
    ll carry;
    ll i;
    initialize_bignum(c);
    if(a->signbit == b->signbit) c->signbit = a->signbit;
    else{
        if(a->signbit == MINUS){
            a->signbit = PLUS;
            subtract(b,a,c);
            a->signbit = MINUS;
        } else{
            b->signbit = PLUS;
            subtract(a,b,c);
            b->signbit = MINUS;
        }
        return;
    }
    
    c->lastdigit = max(a->lastdigit, b->lastdigit)+1;
    carry = 0;
    for(i = 0; i <= (c->lastdigit); i++){
        c->digits[i] = (char)(carry+a->digits[i]+b->digits[i])%10;
        carry = (carry + a->digits[i] + b->digits[i])/10;
    }
    zero_justify(c);
}

void modulo(bignum *a, bignum *b, bignum *c){
    initialize_bignum(c);
    bignum x; divide(a,b,&x);
    bignum y; multiply(&x, b, &y);
    subtract(a, &y, c);
}

void fpb(bignum *a, bignum *b, bignum *c){
    bignum aa,bb,nol,tmp,amodb; int_to_bignum(0, &nol);
    aa = *a;
    bb = *b;
    while(compare_bignum(&bb, &nol) != 0){
        tmp = bb;
        modulo(&aa, &bb, &amodb);
        bb = amodb;
        aa = tmp;
    }
    *c = aa;
}
void kpk(bignum *a, bignum *b, bignum *c){
    bignum ab; multiply(a,b,&ab);
    bignum fpbab; fpb(a,b,&fpbab);
    divide(&ab, &fpbab, c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,x; cin >> n;
    bignum res, num, tmp; int_to_bignum(1, &res);
    while(n--){
        cin >> x;
        int_to_bignum(x, &num);
        kpk(&res,&num, &res);
    }
    print_bignum(&res);
    return 0;
}
