#include <iostream>
#include <string.h>

using namespace std;

static char string_a[] = "1234567";
static char string_b[] = "987";

int main(int argc, char**argv)
{
    char *a, *b, *r;
    int a_len, b_len, r_len;
    int a_idx, b_idx, r_idx;
    int tmp, has_carry;

    if (argc == 3) {
        a = argv[1];
        b = argv[2];
    }
    else {
        a = string_a;
        b = string_b;
    }

    if (a == NULL || b == NULL) {
        cout << "Error! Input values are invalid.\n";
        return -1;
    }

    cout << "string_a: " << a <<  "\n";
    cout << "string_b: " << b <<  "\n";

    a_len = strlen(a);
    b_len = strlen(b);
    r_len = a_len > b_len ? a_len : b_len;
    r_len ++; /* when added, we might need one more digit. */

    r = new char[r_len + 1]; /* considering terminating character */
    if (r == NULL) {
        cout << "Error in allocating result buffer!\n";
        return -1;
    }
    r[r_len] = '\0';

    a_idx = a_len - 1;
    b_idx = b_len - 1;
    r_idx = r_len - 1;
    has_carry = 0;
    while (r_idx > 0) {
        tmp = has_carry;
        tmp += a_idx >= 0 ? a[a_idx] - '0' : 0;
        tmp += b_idx >= 0 ? b[b_idx] - '0' : 0;
        if (tmp > 9) {
            tmp -= 10;
            has_carry = 1;
        }
        else {
            has_carry = 0;
        }

        r[r_idx] = tmp + '0';
        cout << "r_idx: " << r_idx << " r: " << r[r_idx] << '\n';
        a_idx--;
        b_idx--;
        r_idx--;
    }
    r[0] = has_carry + '0';

    cout << "result: " << r << "\n";

    delete[] r;
    return 0;
}
