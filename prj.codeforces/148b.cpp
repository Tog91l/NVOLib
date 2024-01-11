#include<iostream>
 
 
int main() {
    double vp, vd, t, f, c;
   std:: cin >> vp >> vd >> t >> f >> c;
 
 double res =0;
    if (vp < vd) {
       double s = vp * vd * t / (vd - vp);
 
        for (res = 0; s < c; ++res) {
            s = vd * (s + vp * (s / vd + f)) / (vd - vp);
        }
        
    }
 
std::cout << res << std::endl;
    return 0;
}
