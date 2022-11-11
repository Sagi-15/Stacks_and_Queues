#include <iostream>
using namespace std;
template <typename T,typename V>
class Pair{
    private:
        T x;
        V y;
    public:
        void setX(T x){
            this->x=x;
        }
        T getX(){
            return this->x;
        }
        void setY(V y){
            this->y=y;
        }
        V getY(){
            return this->y;
        }
};
int main(){
    Pair<Pair<int,double>,char> p;
    /*So <typename T,typename V> tha so T mei Pair<Int,double>
    aur V mei char aa ja*/
    /*so p ke liye x is also a pair of int and double x and 
    y respectively. p ke liye y is char*/
    p.setY('a');
    /*but can't do p.setX(4) aisa as parameter mei need to
    pass T joh ki*/
    Pair<int,double> p_internal;/*so to set x value joh issi type ka*/
    p_internal.setX(15);
    p_internal.setY(18.345);
    p.setX(p_internal);
    cout<<(p.getX()).getX()<<" "<<(p.getX()).getY()<<" "<<p.getY();
}