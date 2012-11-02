#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

char default_string[] = "aboutabout";

int is_vowel(char str) {
    switch(str) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
    }
}

int find_next_vowel(char *str, int start, int is_backward) {

    int i = start;

    while(i >= 0 && str[i] != '\0' && !is_vowel(str[i])) {
        if (is_backward)
            i--;
        else
            i++;
    }

    return i;
}

void swap(char *a, char *b) {

    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char* argv[]) {

    char *str;
    int fw, bw;

    if (argc >= 2)
        str = argv[1];
    else
        str = default_string;

    if (str == NULL)
        return -1;

    cout << "input string: " << str << endl;

    fw = 0;
    bw = strlen(str) - 1;
    while(bw > fw) {
        fw = find_next_vowel(str, fw, 0);
        bw = find_next_vowel(str, bw, 1);
        if (bw > fw) {
            swap(&str[fw], &str[bw]);
            fw++;
            bw--;
        }
    }

    cout << "result string: " << str << endl;
}
