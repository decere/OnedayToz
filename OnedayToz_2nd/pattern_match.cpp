#include <iostream>

using namespace std;

static char target[] = "ab00a00bcc";
static char pattern[] = "abc";

bool is_match(char *t, char*p)
{
    while (*t != '\0' && *p != '\0') {
        if (*t == *p) {
            t++;
            p++;
        }
        else {
            t++;
        }
    }

    if (*p == '\0')
        return 1;

    return 0;
}

int main(int argc, char**argv)
{
    char *t, *p;
    if (argc == 3) {
        t = argv[1];
        p = argv[2];
    }
    else {
        t = target;
        p = pattern;
    }

    if (t == NULL || p == NULL)
        return -1;

    cout << "target: " << t <<  "\n";
    cout << "pattern: " << p <<  "\n";

    cout << "match? ";
    if (is_match(t, p))
        cout << "Yes!\n";
    else
        cout << "No!\n";

    return 0;
}
