#include <iostream>
#include <cstring>

using namespace std;

const char *strings[] = {"at", "", "", "dad", "hard"};
const char key[] = "dad";

int search(const char *k, const char *str[], int min, int max)
{
    int mid = (min + max) / 2;
    int ret;

    while(!strcmp(strings[mid], ""))
        mid++;

    if (!strcmp(strings[mid], ""))
        while(!strcmp(strings[mid], "") && mid >=0)
            mid--;

    if (!strcmp(strings[mid], ""))
        return -1;

    ret = strcmp(key, strings[mid]);

    if (ret > 0)
        search(k, str, mid, max);
    else if (ret < 0)
        search(k, str, max, min);
    else
        return mid;
}

int main(void)
{
    int ret;

    ret = search(key, strings, 0, 4);

    cout << "result: " << ret << endl;
}
