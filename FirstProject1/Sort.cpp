#include "HeaderForFP1.h"


int sort_by_price()
{
    if (productCount <= 1)
    {
        cout << "Nedostatno tovariv dlya sortuvannya.\n";
        return 0;
    }
    for (int i = 0; i < productCount - 1; i++)
    {
        for (int j = 0; j < productCount - 1 - i; j++)
        {
            if (products[j].price > products[j + 1].price)
            {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
    cout << "Tovary vidsortovano za tsinoyu (zrostannya).\n";
    Show_all_Products();
    return 1;
}

int sort_by_category()
{
    if (productCount <= 1)
    {
        cout << "Nedostatno tovariv dlya sortuvannya.\n";
        return 0;
    }
    for (int i = 0; i < productCount - 1; i++)
    {
        for (int j = 0; j < productCount - 1 - i; j++)
        {
            const char* name1 = GetCategoryName(products[j].categoryId);
            const char* name2 = GetCategoryName(products[j + 1].categoryId);
            if (myStrCompare(name1, name2) > 0)
            {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
    cout << "Tovary vidsortovano za kategoriyeyu (alfavit).\n";
    Show_all_Products();
    return 1;
}