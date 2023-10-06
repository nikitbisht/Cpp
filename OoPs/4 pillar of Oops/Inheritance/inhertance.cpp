/*         ----------- Mode of inheritance------------
    superclass   |   PUBLIC        | PRIVATE   |  PROTECTED
1.  public       |   public        | private   |  protected    
2.  Protected    |   protected     | private   |  protected
3.  Private      |   Not Accesible |  NA       |   NA     
*/
#include<iostream>
using namespace std;
class human{
    public:
        int height;
        int weight;
        int age;
    public:
        int getage(){
            return this->age;
        }
        void setage(int age){
            this->age=age;
        }
};

class male:public human{
    public:
        string colour;

    void sleep(){
        cout<<"Male is Sleeping "<<endl;
    }
};
int main(){
    male obj1;
    obj1.setage(19);
    cout<<obj1.getage()<<endl;
    obj1.sleep();
    return 0;
}