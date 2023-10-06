/*              STATIC KEY WORD
static keyword create data member belongs to class we can alseo access this datamember without creating any object.
Initilize it outside the class:-   "datatype class_name :: field_name = value"
*/
#include<iostream>
using namespace std;
class hero{
    public:
    int x;
    int y;
    static int timetoComplete;

};
int hero::timetoComplete=5;         //initilize
int main(){
    cout<<hero::timetoComplete<<endl;
    return 0;
}