#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
    char** boardToChar = new char* [m];

    for (int i = 0; i < m; i++)
    {
        boardToChar[i] = (char*)board.at(i).c_str();
    }

   

    //check
    int answer = 0;
    int deletionCount = 0;

    

    while (deletionCount != 0)
    {
        deletionCount = 0;
        for (int y = 0; y < m - 1; y++)
        {
            for (int x = 0; x < n - 2; x++)
            {
                if (boardToChar[x][y] == boardToChar[x + 1][y]
                    && boardToChar[x][y] == boardToChar[x][y + 1]
                    && boardToChar[x][y] == boardToChar[x + 1][y + 1])
                {
                    answer++;
                    deletionCount++;
                    boardToChar[x][y] = ' ';
                    boardToChar[x + 1][y] = ' ';
                    boardToChar[x][y + 1] = ' ';
                    boardToChar[x + 1][y + 1] = ' ';
                }
            }
        }

        if (deletionCount > 0)
        {
            //delete and removabl

        }
    }



    return answer;
}


int main()
{
    vector<string> vec;
    vec.push_back("CCBDE");
    vec.push_back("AAADE");
    vec.push_back("AAABF");
    vec.push_back("CCBBF");
    cout << solution(4,5, vec)<< endl;

    return 0;
}