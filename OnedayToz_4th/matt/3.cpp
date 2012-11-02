#include <iostream>
#include <cstring>

using namespace std;

static const char char_matrix[4][4] = {
    { 'a', 'b', 'c' , 'd'},
    { 'l', 'm', 'n' , 'o'},
    { 'a', 'e', 'i' , 'o'},
    { 'w', 'x', 'y' , 'z'}};

static int count = 0;
static int count_per_strlen[16+1] = {0,};

int
check_dictionary(char *str, int len)
{
    char tmp;
    count++;
    count_per_strlen[len]++;
#if 0
    cout << "search count= " << count << endl;
    cout << "search count of each strlen(" << len+1 << ")= " << count_per_strlen[len] << endl;
    if (count == 50)
        cin >> tmp;
#endif
    if (len == 0)
        cout << str << endl;

    return 0;
}

int
search_around(char *word, int cur_idx, char visited[4][4], int x, int y) {

    int m, n;
    char word_local[16+1];
    char visited_local[4][4];

    memcpy(word_local, word, sizeof(word_local));
    memcpy(visited_local, visited, sizeof(visited_local));
    for (m=x-1; m <= x+1; m++) {
        if (m < 0 || m > 3) continue;
        for (n=y-1; n <= y+1; n++) {

            if (n < 0 || n > 3) continue; 
            if (visited_local[m][n] == 1) continue;

            word_local[cur_idx] = char_matrix[m][n];
            visited_local[m][n] = 1;

#if 0
            if (check_dictionary(word_local, cur_idx))
                cout << "Got it! " << m << "," << n << " " << word_local << endl;
            else
                cout << "Not a word! " << m << "," << n << " " << word_local << endl;
#else
            check_dictionary(word_local, cur_idx);
#endif

            if (cur_idx == 0)
                cout << m << n << word_local << endl;

            search_around(word_local, cur_idx+1, visited_local, m, n);
        }
    }
}

int main(int argc, char *argv[]) {
    
    char word[16+1];
    char visited[4][4];
    int m, n;

#if 0
    for (m=0; m<=16; m++)
        word[m] = '\0';

    for (m=0; m<=3; m++)
        for (n=0; n<=3; n++)
            visited[m][n] = 0;
#endif

    for (m=0; m<=3; m++)
        for (n=0; n<=3; n++) {
            memset(word, 0, sizeof(word));
            memset(visited, 0, sizeof(visited));
            search_around(word, 0, visited, m, n);
        }

    cout << "search count= " << ++count << endl;
    for (m=0; m <= 15; m++)
        cout << "search count of each strlen(" << m+1 << ")= " << ++count_per_strlen[m] << endl;

}
