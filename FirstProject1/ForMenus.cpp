#include "HeaderForFP1.h"



void FirstMainMenu()
{
    ClearScreen();
    cout << "Shyro dyakuyemo, shcho zavitay v nash sklad\n\n";
    cout << "Viberit diyu z:\n";
    cout << "1. Kategoriyeyu\n";
    cout << "2. Tovarom\n";
    cout << "3. Poshukom z tovarom\n";
    cout << "4. Sortuvannyam tovariv\n";
    cout << "0. Viyty\n";
}

void CategoryMenu()
{
    ClearScreen();
    cout << "Viberit diyu z:\n";
    cout << "1. Dodaty kategoriyu\n";
    cout << "2. Vydalyty kategoriyu\n";
    cout << "3. Pokazaty vsi kategoriyi\n";
    cout << "0. Viyty\n";
}

void ProductMenu()
{
    void ClearScreen();
    cout << "Viberit diyu z:\n";
    cout << "1. Dodaty tovar\n";
    cout << "2. Vydalyty tovar\n";
    cout << "3. Pokazaty vsi tovary\n";
    cout << "4. Zminyty tovar\n";
    cout << "0. Viyty\n";
}

void SearchMenu()
{
    void ClearScreen();
    cout << "Viberit diyu z:\n";
    cout << "1. Poshukom po nazvi\n";
    cout << "2. Poshukom po vyrobnyku\n";
    cout << "3. Poshukom po tsini\n";
    cout << "4. Poshukom po kategoriyi\n";
    cout << "5. Poshukom po terminu prydatnosti\n";
    cout << "6. Poshukom po dati nadkhodzhennya v mahazyn\n";
    cout << "0. Viyty\n";
}

void SortMenu()
{
    void ClearScreen();
    cout << "Viberit diyu z:\n";
    cout << "1. Sortuvannya po tsini\n";
    cout << "2. Sortuvannya po kategoriyi\n";
    cout << "0. Viyty\n";
}