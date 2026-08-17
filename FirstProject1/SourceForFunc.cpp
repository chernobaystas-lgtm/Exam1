#include "HeaderForFP1.h"

Category categories[30];
int categoryCount = 10;
int nextCategoryId = 11;

Product products[50];
int productCount = 0;




void Product :: PrintProduct()
{
    cout << " | Nazva: " << name
        << " | Vyrobnyk: " << manufacturer
        << " | Kategoriya: " << GetCategoryName(categoryId)
        << " | Tsina: " << price
        << " | Data nadkhodzhennya: " << date_since_in_store
        << " | Prydatnist: " << expiry_date
        << "\n";
}


void clearInput()
{
    cin.clear();
    while (cin.get() != '\n');
}

int safeInputInt(const char* prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (cin.fail())
        {
            cout << "Pomilka! Vvedit tsele chislo.\n";
            clearInput();
        }
        else
        {
            clearInput();
            return value;
        }
    }
}

void safeInputStr(const char* prompt, char* buffer, int maxLen)
{
    while (true)
    {
        cout << prompt;
        cin.getline(buffer, maxLen);
        if (buffer[0] == '\0')
        {
            cout << "Pomilka! Ryadok ne mozhe buty porozhnim.\n";
        }
        else
        {
            break;
        }
    }
}

double safeInputDouble(const char* prompt)
{
    double value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0)
        {
            cout << "Pomilka! Vvedit korektne dodatne chislo.\n";
            clearInput();
        }
        else
        {
            clearInput();
            return value;
        }
    }
}

int safeInputDate(const char* prompt)
{
    cout << prompt << " (vvedit okremo: rik, misyats, den)\n";
    int year, month, day;
    while (true)
    {
        year = safeInputInt("  Rik (napriklad 2026): ");
        if (year < 1900 || year > 2100)
        {
            cout << "Pomilka! Rik maie buty 1900-2100.\n";
            continue;
        }
        month = safeInputInt("  Misyaats (1-12): ");
        if (month < 1 || month > 12)
        {
            cout << "Pomilka! Misyaats maie buty 1-12.\n";
            continue;
        }
        day = safeInputInt("  Den (1-31): ");
        if (day < 1 || day > 31)
        {
            cout << "Pomilka! Den maie buty 1-31.\n";
            continue;
        }
        return year * 10000 + month * 100 + day;
    }
}

void toLower(char* str)
{
    int i = 0;
    while (str[i])
    {
        unsigned char c1 = str[i];
        if (c1 < 0x80)
        {
            str[i] = tolower(c1);
            i++;
        }
        else if ((c1 == 0xD0 || c1 == 0xD1) && str[i + 1])
        {
            unsigned char c2 = str[i + 1];
            int codepoint = (c1 == 0xD0 ? 0x400 : 0x440) + (c2 & 0x3F);
            if (codepoint >= 0x410 && codepoint <= 0x42F)
                codepoint += 0x20;
            else if (codepoint >= 0x400 && codepoint <= 0x40F)
                codepoint += 0x50;
            str[i] = 0xC0 | (codepoint >> 6);
            str[i + 1] = 0x80 | (codepoint & 0x3F);
            i += 2;
        }
        else i++;
    }
}

void InitBaseCategories()
{
    strcpy_s(categories[0].name_of_category, 40, "Molochka produktsiya");
    categories[0].id = MILK;

    strcpy_s(categories[1].name_of_category, 40, "Instrumenty");
    categories[1].id = TOOLS;

    strcpy_s(categories[2].name_of_category, 40, "Produkty");
    categories[2].id = PRODUCTS;

    strcpy_s(categories[3].name_of_category, 40, "Kosmetika");
    categories[3].id = COSMETICS;

    strcpy_s(categories[4].name_of_category, 40, "Hihiyena");
    categories[4].id = HYGIENE;

    strcpy_s(categories[5].name_of_category, 40, "Elektronika");
    categories[5].id = ELECTRONICS;

    strcpy_s(categories[6].name_of_category, 40, "Domashniy pobut");
    categories[6].id = HOUSEHOLD;

    strcpy_s(categories[7].name_of_category, 40, "Kantselariya");
    categories[7].id = STATIONERY;

    strcpy_s(categories[8].name_of_category, 40, "Sport");
    categories[8].id = SPORT;

    strcpy_s(categories[9].name_of_category, 40, "Odyag");
    categories[9].id = CLOTHES;
}




bool containsIgnoreCase(const char* text, const char* query)
{
    if (query[0] == '\0') return true;

    char tBuf[100];
    char qBuf[100];
    strcpy_s(tBuf, 100, text);
    strcpy_s(qBuf, 100, query);
    toLower(tBuf);
    toLower(qBuf);

    int tLen = 0;
    while (tBuf[tLen]) tLen++;
    int qLen = 0;
    while (qBuf[qLen]) qLen++;
    if (qLen > tLen) return false;

    for (int i = 0; i <= tLen - qLen; i++)
    {
        bool match = true;
        for (int j = 0; j < qLen; j++)
        {
            if (tBuf[i + j] != qBuf[j])
            {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}


int myStrCompare(const char* a, const char* b)
{
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i]) i++;
    return (unsigned char)a[i] - (unsigned char)b[i];
}


void LoadProductsFromFile()
{
    FILE* file = nullptr;
    errno_t err = fopen_s(&file, "goods.txt", "r");
    if (err != 0 || file == nullptr)
    {
        productCount = 0;
        return;
    }
    productCount = 0;
    while (productCount < 50)
    {
        int result = fscanf_s(file, "%[^|]|%[^|]|%d|%lf|%d|%d\n",
            products[productCount].name, (unsigned)sizeof(products[productCount].name),
            products[productCount].manufacturer, (unsigned)sizeof(products[productCount].manufacturer),
            &products[productCount].categoryId,
            &products[productCount].price,
            &products[productCount].date_since_in_store,
            &products[productCount].expiry_date);
        if (result != 6) break;
        productCount++;
    }
    fclose(file);
}

void SaveProductsToFile()
{
    FILE* file = nullptr;
    errno_t err = fopen_s(&file, "goods.txt", "w");
    if (err != 0 || file == nullptr)
    {
        cout << "Pomilka! Ne vdalosya vidkryty goods.txt dlya zapysu.\n";
        return;
    }
    for (int i = 0; i < productCount; i++)
    {
        fprintf(file, "%s|%s|%d|%.2f|%d|%d\n",
            products[i].name,
            products[i].manufacturer,
            products[i].categoryId,
            products[i].price,
            products[i].date_since_in_store,
            products[i].expiry_date);
    }
    fclose(file);
}