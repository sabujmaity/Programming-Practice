#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
#include <cmath>

using int128 = __int128_t;

std::ostream& operator<<(std::ostream& os, int128 val) {
    if (val == 0) return os << "0";
    std::string s;
    bool neg = false;
    if (val < 0) {
        neg = true;
        val = -val;
    }
    while (val > 0) {
        s += (char)('0' + val % 10);
        val /= 10;
    }
    if (neg) os << "-";
    std::reverse(s.begin(), s.end());
    return os << s;
}

int128 abs128(int128 x) {
    return x < 0 ? -x : x;
}

int128 gcd128(int128 a, int128 b) {
    a = abs128(a);
    b = abs128(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

struct Rational {
    int128 p, q;

    Rational(int128 num = 0, int128 den = 1) {
        if (den == 0) {
           p = 0; q = 1; 
           return;
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
        if (num == 0) {
            p = 0;
            q = 1;
        } else {
            int128 common = gcd128(num, den);
            if (common == 0) {
                 p = 0; q = 1;
            } else {
                p = num / common;
                q = den / common;
            }
        }
    }

    bool operator<(const Rational& other) const { return p * other.q < other.p * q; }
    bool operator>(const Rational& other) const { return p * other.q > other.p * q; }
    bool operator==(const Rational& other) const { return p == other.p && q == other.q; }
    bool operator<=(const Rational& other) const { return p * other.q <= other.p * q; }
    bool operator>=(const Rational& other) const { return p * other.q >= other.p * q; }
    bool operator!=(const Rational& other) const { return !(*this == other); }

    Rational operator+(const Rational& other) const {
        int128 common_divisor = gcd128(q, other.q);
        if (common_divisor == 0) return Rational(0,1);
        int128 common_q = (q / common_divisor) * other.q;
        int128 num1 = p * (common_q / q);
        int128 num2 = other.p * (common_q / other.q);
        return Rational(num1 + num2, common_q);
    }
    Rational operator-(const Rational& other) const {
        int128 common_divisor = gcd128(q, other.q);
        if (common_divisor == 0) return Rational(0,1);
        int128 common_q = (q / common_divisor) * other.q;
        int128 num1 = p * (common_q / q);
        int128 num2 = other.p * (common_q / other.q);
        return Rational(num1 - num2, common_q);
    }
     Rational operator*(const Rational& other) const {
        int128 g1 = gcd128(p, other.q);
        int128 g2 = gcd128(other.p, q);
        int128 num_p1 = (g1 == 0) ? 0 : p / g1;
        int128 num_p2 = (g2 == 0) ? 0 : other.p / g2;
        int128 den_q1 = (g2 == 0) ? q : q / g2; 
        int128 den_q2 = (g1 == 0) ? other.q : other.q / g1;
        int128 num = num_p1 * num_p2;
        int128 den = den_q1 * den_q2;
        return Rational(num, den);
    }
    Rational operator/(const Rational& other) const {
        if (other.p == 0) {
             return Rational(0,1); 
        }
        int128 g1 = gcd128(p, other.p);
        int128 g2 = gcd128(other.q, q);
        int128 num_p1 = (g1 == 0) ? 0 : p / g1;
        int128 num_q2 = (g2 == 0) ? 0 : other.q / g2;
        int128 den_q1 = (g2 == 0) ? q : q / g2;
        int128 den_p2 = (g1 == 0) ? other.p : other.p / g1;
        int128 num = num_p1 * num_q2;
        int128 den = den_q1 * den_p2;
        return Rational(num, den);
    }
    
    bool operator==(long long val) const { return p == (int128)val * q; }
    bool operator!=(long long val) const { return !(*this == val); }
    
     Rational operator+(long long val) const { return *this + Rational(val); }
     Rational operator-(long long val) const { return *this - Rational(val); }
     Rational operator*(long long val) const { return *this * Rational(val); }
     Rational operator/(long long val) const { return *this / Rational(val); }
     friend Rational operator+(long long val, const Rational& r) { return Rational(val) + r; }
     friend Rational operator-(long long val, const Rational& r) { return Rational(val) - r; }
     friend Rational operator*(long long val, const Rational& r) { return Rational(val) * r; }
     friend Rational operator/(long long val, const Rational& r) { return Rational(val) / r; }

};

using State = std::tuple<Rational, Rational, long long, long long>;

long long gcd_ll(long long a, long long b) {
    a = std::abs(a);
    b = std::abs(b);
     while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while (t--) {
        long long n_ll, x_ll, y_ll, vx_ll, vy_ll;
        std::cin >> n_ll >> x_ll >> y_ll >> vx_ll >> vy_ll;
       
        Rational N(n_ll), X(x_ll), Y(y_ll);
        long long vx = vx_ll;
        long long vy = vy_ll;

        long long common_v = gcd_ll(std::abs(vx), std::abs(vy)); 
        long long vx_prime = vx / common_v;
        long long vy_prime = vy / common_v;
        int128 D_prime_num = (int128)x_ll * vy_prime - (int128)y_ll * vx_prime;
        
        if (n_ll != 0 && D_prime_num % (int128)n_ll != 0) {
             std::cout << -1 << "\n";
             continue;
        }
        
        std::map<State, bool> visited;
        long long reflections = 0;
        bool escaped = false;
        const int MAX_REFLECTIONS = 2000000;

        for (int step = 0; step <= MAX_REFLECTIONS; ++step) {
            State current_state = std::make_tuple(X, Y, vx, vy);
             
            if (visited.count(current_state)) {
                 break;
            }
            visited[current_state] = true;

            Rational min_t(-1);

            Rational current_X = X;
            Rational current_Y = Y;

            if (vx < 0) {
                Rational t_x = (Rational(0) - current_X) / Rational(vx);
                 if (t_x > Rational(0) && (min_t == Rational(-1) || t_x < min_t)) {
                     min_t = t_x;
                 }
            }
            if (vy < 0) {
                Rational t_y = (Rational(0) - current_Y) / Rational(vy);
                 if (t_y > Rational(0) && (min_t == Rational(-1) || t_y < min_t)) {
                     min_t = t_y;
                 }
            }
            if (vx + vy > 0) { 
                 Rational target_sum = N;
                 Rational current_sum = current_X + current_Y;
                 Rational t_xy = (target_sum - current_sum) / Rational(vx + vy);
                 if (t_xy > Rational(0) && (min_t == Rational(-1) || t_xy < min_t)) {
                     min_t = t_xy;
                 }
            }
            
             if (min_t == Rational(-1) || min_t <= Rational(0)) { 
                 break; 
             }

            X = current_X + Rational(vx) * min_t;
            Y = current_Y + Rational(vy) * min_t;

            bool is_vertex = false;
            if (X == 0 && Y == 0) is_vertex = true;
            else if (X == n_ll && Y == 0) is_vertex = true;
            else if (X == 0 && Y == n_ll) is_vertex = true;

            if (is_vertex) {
                escaped = true;
                break;
            }

            bool reflected = false;
             
             if (vx < 0) {
                 Rational t_x = (Rational(0) - current_X) / Rational(vx);
                 if (t_x == min_t) {
                     vx = -vx;
                     reflected = true;
                 }
             }
             if (vy < 0) {
                 Rational t_y = (Rational(0) - current_Y) / Rational(vy);
                  if (t_y == min_t) {
                      if (!reflected) { 
                          vy = -vy;
                          reflected = true;
                      } 
                  }
             }
             if (vx + vy > 0) {
                 Rational target_sum = N;
                 Rational current_sum = current_X + current_Y;
                 Rational t_xy = (target_sum - current_sum) / Rational(vx + vy);
                 if (t_xy == min_t) {
                      if (!reflected) {
                          long long old_vx = vx;
                          vx = -vy;
                          vy = -old_vx;
                          reflected = true;
                      } 
                 }
             }

             if (!reflected) {
                 break;
             }

            reflections++;
        }

        if (escaped) {
            std::cout << reflections << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    }

    return 0;
}
