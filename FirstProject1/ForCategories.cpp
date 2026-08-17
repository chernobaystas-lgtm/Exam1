#include "HeaderForFP1.h"



int Add_Category()
{
    if (categoryCount >= 30)
    {
        cout << "Pomilka! Dosyagnuto maksimum kategoriy (30).\n";
        return 0;
    }
    safeInputStr("Vvedit nazvu kategoriyi: ", categories[categoryCount].name_of_category, 40);
    categories[categoryCount].id = nextCategoryId;
    nextCategoryId++;
    cout << "Kategoriyu \"" << categories[categoryCount].name_of_category
        << "\" dodano z ID = " << categories[categoryCount].id << "\n";
    categoryCount++;
    return 1;
}

int Show_all_Categories()
{
    if (categoryCount == 0)
    {
        cout << "Kategoriy poky nemaye.\n";
        return 0;
    }
    cout << "\n--- Spysok kategoriy ---\n";
    for (int i = 0; i < categoryCount; i++)
    {
        cout << "ID: " << categories[i].id
            << " | Nazva: " << categories[i].name_of_category << "\n";
    }
    cout << "------------------------\n";
    return 1;
}

int Delete_Category()
{
    if (categoryCount <= 10)
    {
        cout << "Pomilka! Nemozhlyvo vydalyty bazovi kategoriyi.\n";
        return 0;
    }
    Show_all_Categories();
    int id = safeInputInt("Vvedit ID kategoriyi dlya vydalennya: ");

    int index = -1;
    for (int i = 0; i < categoryCount; i++)
    {
        if (categories[i].id == id)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Pomilka! Kategoriyu z ID " << id << " ne znaydeno.\n";
        return 0;
    }
    if (id >= 1 && id <= 10)
    {
        cout << "Pomilka! Nemozhlyvo vydalyty bazovu kategoriyu (ID 1-10).\n";
        return 0;
    }
    for (int i = 0; i < productCount; i++)
    {
        if (products[i].categoryId == id)
        {
            cout << "Pomilka! U kategoriyi ye tovary. Spochatku vydality yikh.\n";
            return 0;
        }
    }
    for (int i = index; i < categoryCount - 1; i++)
    {
        categories[i] = categories[i + 1];
    }
    categoryCount--;
    cout << "Kategoriyu z ID " << id << " uspishno vydaleno.\n";
    return 1;
}

int FindCategoryIndex(int id)
{
    for (int i = 0; i < categoryCount; i++)
    {
        if (categories[i].id == id) return i;
    }
    return -1;
}

const char* GetCategoryName(int id)
{
    for (int i = 0; i < categoryCount; i++)
    {
        if (categories[i].id == id) return categories[i].name_of_category;
    }
    return "Nevidoma";
}

