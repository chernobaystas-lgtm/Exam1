#include "HeaderForFP1.h"



int Add_Product()
{
    if (productCount >= 50)
    {
        cout << "Pomilka! Dosyagnuto maksimum tovariv (50).\n";
        return 0;
    }
    cout << "\n--- Dodavannya tovaru ---\n";
    safeInputStr("Nazva tovaru: ", products[productCount].name, 30);
    safeInputStr("Vyrobnyk: ", products[productCount].manufacturer, 30);

    Show_all_Categories();
    int catId;
    while (true)
    {
        catId = safeInputInt("Vvedit ID kategoriyi tovaru: ");
        if (FindCategoryIndex(catId) != -1) break;
        cout << "Pomilka! Kategoriya z takym ID ne isnuye. Sprobuyte shche raz.\n";
    }
    products[productCount].categoryId = catId;

    products[productCount].price = safeInputDouble("Tsina tovaru: ");
    products[productCount].date_since_in_store = safeInputDate("Data nadkhodzhennya na sklad");

    int expiry;
    while (true)
    {
        expiry = safeInputDate("Termin prydatnosti");
        if (expiry >= products[productCount].date_since_in_store) break;
        cout << "Pomilka! Termin prydatnosti ne mozhe buty ranshe daty nadkhodzhennya.\n";
    }
    products[productCount].expiry_date = expiry;

    cout << "Tovar \"" << products[productCount].name << "\" uspishno dodano.\n";
    productCount++;
    return 1;
}

int Show_all_Products()
{
    if (productCount == 0)
    {
        cout << "Tovariv poky nemaye.\n";
        return 0;
    }
    cout << "\n--- Spysok tovariv ---\n";
    for (int i = 0; i < productCount; i++)
    {
        cout << "No" << (1 + i);
        products[i].PrintProduct();
    }
    cout << "----------------------\n";
    return 1;
}

int Delete_Product()
{
    if (productCount == 0)
    {
        cout << "Tovariv nemaye dlya vydalennya.\n";
        return 0;
    }
    Show_all_Products();
    int num = safeInputInt("Vvedit nomer tovaru dlya vydalennya: ");
    if (num < 1 || num > productCount)
    {
        cout << "Pomilka! Nekorektnyy nomer tovaru.\n";
        return 0;
    }

    int index = num - 1;
    cout << "Vydalyty \"" << products[index].name << "\"? (1 - tak, 0 - ni): ";
    int confirm = safeInputInt("");
    if (confirm != 1)
    {
        cout << "Vydalennya skasovano.\n";
        return 0;
    }

    for (int i = index; i < productCount - 1; i++)
    {
        products[i] = products[i + 1];
    }
    productCount--;
    cout << "Tovar uspishno vydaleno.\n";
    return 1;
}

int Change_Product()
{
    if (productCount == 0)
    {
        cout << "Tovariv nemaye dlya zminy.\n";
        return 0;
    }
    Show_all_Products();
    int num = safeInputInt("Vvedit nomer tovaru dlya zminy: ");
    if (num < 1 || num > productCount)
    {
        cout << "Pomilka! Nekorektnyy nomer tovaru.\n";
        return 0;
    }

    int index = num - 1;
    Product& p = products[index];

    cout << "\n--- Zmina tovaru: " << p.name << " ---\n";
    cout << "1. Nazvu\n";
    cout << "2. Vyrobnyka\n";
    cout << "3. Kategoriyu\n";
    cout << "4. Tsinu\n";
    cout << "5. Datu nadkhodzhennya\n";
    cout << "6. Termin prydatnosti\n";
    cout << "0. Skasuvaty\n";

    int choice = safeInputInt("Vash vybir: ");
    switch (choice)
    {
    case 1:
        safeInputStr("Nova nazva: ", p.name, 30);
        break;
    case 2:
        safeInputStr("Novyy vyrobnyk: ", p.manufacturer, 30);
        break;
    case 3:
        Show_all_Categories();
        while (true)
        {
            int newCat = safeInputInt("Novyy ID kategoriyi: ");
            if (FindCategoryIndex(newCat) != -1)
            {
                p.categoryId = newCat;
                break;
            }
            cout << "Pomilka! Kategoriya ne isnuye.\n";
        }
        break;
    case 4:
        p.price = safeInputDouble("Nova tsina: ");
        break;
    case 5:
    {
        int newDate = safeInputDate("Nova data nadkhodzhennya");
        if (newDate > p.expiry_date)
        {
            cout << "Pomilka! Data nadkhodzhennya ne mozhe buty piznishe terminu prydatnosti.\n";
            return 0;
        }
        p.date_since_in_store = newDate;
        break;
    }
    case 6:
    {
        int newExpiry = safeInputDate("Novyy termin prydatnosti");
        if (newExpiry < p.date_since_in_store)
        {
            cout << "Pomilka! Termin prydatnosti ne mozhe buty ranshe daty nadkhodzhennya.\n";
            return 0;
        }
        p.expiry_date = newExpiry;
        break;
    }
    case 0:
        cout << "Zminu skasovano.\n";
        return 0;
    default:
        cout << "Nekorektnyy vybir.\n";
        return 0;
    }
    cout << "Tovar uspishno zmineno.\n";
    return 1;
}