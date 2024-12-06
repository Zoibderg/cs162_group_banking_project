#include <iostream>
#include "menu.h"
#include "BankAccountContainer.h"
using namespace std;

int main() {
    BankAccountContainer container;
    Menu menu(container);
    menu.start();
    return 0;
}
