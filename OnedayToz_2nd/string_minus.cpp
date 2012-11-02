#include <iostream>
#include <string.h>

using namespace std;

static char string_a[] = "1234567";
static char string_b[] = "987";

int need_swap(char *a, char *b)
{
    return 0; /* a is bigger than or equal to b */
}


int main(int argc, char**argv)
{
    char *a, *b, *r;
    int a_len, b_len, r_len;
    int a_idx, b_idx, r_idx;
    int tmp, has_carry, swap;

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

    if (a_len > b_len)
        swap = 0;
    else if (a_len < b_len)
        swap = 1;
    else {
        int idx = 0;

        swap = 0;
        while(idx <= a_len - 1) {
            if (a[idx] < b[idx]) {
                swap = 1;
                break;
            }
            else if (a[idx] > b[idx]) {
                break;
            }
            idx++;
        }
    }

    a_idx = a_len - 1;
    b_idx = b_len - 1;
    r_idx = r_len - 1;
    has_carry = 0;
    while (r_idx > 0) {
        int tmp_a, tmp_b;
        tmp_a = a_idx >= 0 ? a[a_idx] - '0' : 0;
        tmp_b = b_idx >= 0 ? b[b_idx] - '0' : 0;
        if (swap) {
            tmp = tmp_b - tmp_a - has_carry;
        }
        else {
            tmp = tmp_a - tmp_b - has_carry;
        }

        if (tmp < 0) {
            tmp += 10;
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
    if (swap)
        r[0] = '-';
    else
        r[0] = '+';

    cout << "result: " << r << "\n";

    delete[] r;
    return 0;
}
