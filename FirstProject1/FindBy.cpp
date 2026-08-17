#include "HeaderForFP1.h"



int Find_by_name()
{
    if (productCount == 0)
    {
        cout << "Tovariv nemaye dlya poshuku.\n";
        return 0;
    }
    char query[30];
    safeInputStr("Vvedit nazvu dlya poshuku (mozhna chastkovo): ", query, 30);

    int found = 0;
    cout << "\n--- Rezultaty poshuku za nazvoyu ---\n";
    for (int i = 0; i < productCount; i++)
    {
        if (containsIgnoreCase(products[i].name, query))
        {
            PrintProduct(products[i]);
            found++;
        }
    }
    if (found == 0) cout << "Nichoho ne znaydeno.\n";
    else cout << "Znaydeno: " << found << " tovar(iv).\n";
    return found;
}

int Find_by_manufacturer()
{
    if (productCount == 0)
    {
        cout << "Tovariv nemaye dlya poshuku.\n";
        return 0;
    }
    char query[30];
    safeInputStr("Vvedit vyrobnyka dlya poshuku (mozhna chastkovo): ", query, 30);

    int found = 0;
    cout << "\n--- Rezultaty poshuku za vyrobnykom ---\n";
    for (int i = 0; i < productCount; i++)
    {
        if (containsIgnoreCase(products[i].manufacturer, query))
        {
            PrintProduct(products[i]);
            found++;
        }
    }
    if (found == 0) cout << "Nichoho ne znaydeno.\n";
    else cout << "Znaydeno: " << found << " tovar(iv).\n";
    return found;
}

int find_by_price()
{
    if (productCount == 0)
    {
        cout << "Tovariv nemaye dlya poshuku.\n";
        return 0;
    }
    double price = safeInputDouble("Vvedit tsinu dlya tochnoho poshuku: ");

    int found = 0;
    cout << "\n--- Rezultaty poshuku za tsinoyu ---\n";
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].price == price)
        {
            PrintProduct(products[i]);
            found++;
        }
    }
    if (found == 0) cout << "Nichoho ne znaydeno za tsinoyu " << price << ".\n";
    else cout << "Znaydeno: " << found << " tovar(iv).\n";
    return found;
}

int find_by_category()
{
    if (productCount == 0)
    {
        cout << "Tovariv nemaye dlya poshuku.\n";
        return 0;
    }
    Show_all_Categories();
    int catId = safeInputInt("Vvedit ID kategoriyi dlya poshuku: ");
    if (FindCategoryIndex(catId) == -1)
    {
        cout << "Pomilka! Kategoriya z takym ID ne isnuye.\n";
        return 0;
    }

    int found = 0;
    cout << "\n--- Rezultaty poshuku za kategoriyeyu ---\n";
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].categoryId == catId)
        {
            PrintProduct(products[i]);
            found++;
        }
    }
    if (found == 0) cout << "U tsiy kategoriyi tovariv nemaye.\n";
    else cout << "Znaydeno: " << found << " tovar(iv).\n";
    return found;
}

int find_by_expiry_date()
{
    if (productCount == 0)
    {
        cout << "Tovariv nemaye dlya poshuku.\n";
        return 0;
    }
    int date = safeInputDate("Vvedit datu (znaydemo tovary z prydatnistyu DO tsiyey daty vklyuchno)");

    int found = 0;
    cout << "\n--- Rezultaty poshuku za terminom prydatnosti ---\n";
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].expiry_date <= date)
        {
            PrintProduct(products[i]);
            found++;
        }
    }
    if (found == 0) cout << "Nichoho ne znaydeno.\n";
    else cout << "Znaydeno: " << found << " tovar(iv) (prydatni do vkazanoyi daty).\n";
    return found;
}

int find_by_date_since_in_store()
{
    if (productCount == 0)
    {
        cout << "Tovariv nemaye dlya poshuku.\n";
        return 0;
    }
    int date = safeInputDate("Vvedit datu nadkhodzhennya dlya tochnoho poshuku");

    int found = 0;
    cout << "\n--- Rezultaty poshuku za datoyu nadkhodzhennya ---\n";
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].date_since_in_store == date)
        {
            PrintProduct(products[i]);
            found++;
        }
    }
    if (found == 0) cout << "Nichoho ne znaydeno.\n";
    else cout << "Znaydeno: " << found << " tovar(iv).\n";
    return found;
}