#include <iostream>
#include "Usuario.h"
using namespace std;

int main()
{
    Usuario usu(1,"Ignacio","Fiori","nacho@gmail.com","12345","1136303031","11/02/1999",true);

    cout << usu.getNombre() << endl;
    return 0;
}
