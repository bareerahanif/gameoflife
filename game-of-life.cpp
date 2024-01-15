#include <iostream>
#include <windows.h>
using namespace std;

#define Rows 30
#define Cols 60
#define Depth 10


void display(const char World[][Cols])
{
    system("cls");
    for (int ri = 0; ri < Rows; ri++) 
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            cout << World[ri][ci] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int neighbourhoodLivesCount(const char World[][Cols], int ri, int ci, char LS)
{
    int Count = 0;
    for (int r = ri - 1; r <= ri + 1; r++)
    {
        if (r < 0 || r == Rows)
            continue;
        for (int c = ci - 1; c <= ci + 1; c++) 
        {
            if (c < 0 || c == Cols)
                continue;
            if (r == ri && c == ci)
                continue;
            if (World[r][c] == LS)
                Count++;
        }
    }
    return Count;
}
void repopulate(char World[][Cols], char Sym)
{
    char DWorld[Rows][Cols];

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            int count = neighbourhoodLivesCount(World, ri, ci, Sym);
            if (World[ri][ci] == Sym && count < 2)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == Sym && (count == 2 || count == 3))
            {
                DWorld[ri][ci] = Sym;
            }
            else if (World[ri][ci] == Sym && count > 3) 
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == ' ' && count == 3)
            {
                DWorld[ri][ci] = Sym;
            }
            else {
                DWorld[ri][ci] = World[ri][ci];
            }
        }
    }

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
            World[ri][ci] = DWorld[ri][ci];
    }
}
void generateRandomPattern(char World[][Cols])
{
    srand(static_cast<unsigned int>(time(NULL)));
    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            World[ri][ci] = rand() % 2 == 0 ? ' ' : '#'; 
        }
    }
}
int main1()
{
    char world[Rows][Cols];

    generateRandomPattern(world);
    display(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen) {
        repopulate(world, '#'); 
        display(world);
        Sleep(50); 
    }

    return 0;
}

void display1(const char World[][Cols])
{
    system("cls");
    for (int ri = 0; ri < Rows; ri++) 
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            cout << World[ri][ci] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void generateRandomPattern1(char World[][Cols])
{
    srand(static_cast<unsigned int>(time(NULL)));
    for (int ri = 0; ri < Rows; ri++) 
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            World[ri][ci] = rand() % 2 == 0 ? ' ' : '#'; 
        }
    }
}
int neighbourhoodLivesCount1(const char World[][Cols], int ri, int ci, char LS) 
{
    int Count = 0;
    for (int r = ri - 1; r <= ri + 1; r++) 
    {
        if (r < 0 || r == Rows)
            continue;
        for (int c = ci - 1; c <= ci + 1; c++) 
        {
            if (c < 0 || c == Cols)
                continue;
            if (r == ri && c == ci)
                continue;
            if (World[r][c] == LS)
                Count++;
        }
    }
    return Count;
}
void repopulate1(char World[][Cols], char Sym)
{
    char DWorld[Rows][Cols];

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++) 
        {
            int count = neighbourhoodLivesCount1(World, ri, ci, Sym);
            if (World[ri][ci] == Sym && count < 2) 
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == Sym && (count == 2 || count == 3)) 
            {
                DWorld[ri][ci] = Sym;
            }
            else if (World[ri][ci] == Sym && count > 3)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == ' ' && count == 3)
            {
                DWorld[ri][ci] = Sym;
            }
            else 
            {
                DWorld[ri][ci] = World[ri][ci];
            }
        }
    }

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
            World[ri][ci] = DWorld[ri][ci];
    }
}
int main2()
{
    char world[Rows][Cols];

    generateRandomPattern1(world);
    display1(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen)
    {
        repopulate1(world, '#'); 
        display1(world);
        Sleep(50); 
    }

    return 0;
}

void display3(const char World[][Cols]) 
{
    system("cls");
    for (int ri = 0; ri < Rows; ri++) 
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            cout << World[ri][ci] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void generateAchimsp11Pattern3(char World[][Cols])
{
    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            World[ri][ci] = ' ';
        }
    }
    World[20][20] = '#';
    World[20][21] = '#';
    World[20][22] = '#';
    World[21][20] = '#';
    World[21][21] = ' ';
    World[21][22] = '#';
    World[22][20] = '#';
    World[22][21] = '#';
    World[22][22] = '#';
}
int neighbourhoodLivesCount3(const char World[][Cols], int ri, int ci, char LS) 
{
    int Count = 0;
    for (int r = ri - 1; r <= ri + 1; r++)
    {
        if (r < 0 || r == Rows)
            continue;
        for (int c = ci - 1; c <= ci + 1; c++)
        {
            if (c < 0 || c == Cols)
                continue;
            if (r == ri && c == ci)
                continue;
            if (World[r][c] == LS)
                Count++;
        }
    }
    return Count;
}
void repopulate3(char World[][Cols], char Sym)
{
    char DWorld[Rows][Cols];

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++) 
        {
            int count = neighbourhoodLivesCount3(World, ri, ci, Sym);
            if (World[ri][ci] == Sym && count < 2)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == Sym && (count == 2 || count == 3))
            {
                DWorld[ri][ci] = Sym;
            }
            else if (World[ri][ci] == Sym && count > 3)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == ' ' && count == 3)
            {
                DWorld[ri][ci] = Sym;
            }
            else {
                DWorld[ri][ci] = World[ri][ci];
            }
        }
    }

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
            World[ri][ci] = DWorld[ri][ci];
    }
}
int main3()
{
    char world[Rows][Cols];

    generateAchimsp11Pattern3(world);
    display3(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen) 
    {
        repopulate3(world, '#'); 
        display3(world);
        Sleep(50); 
    }

    return 0;
}

void display4(const char World[][30])
{
    system("cls");
    for (int ri = 0; ri < 15; ri++)
    {
        for (int ci = 0; ci < 30; ci++)
        {
            cout << World[ri][ci] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void generateRandomComplexPattern4(char World[][30])
{
    srand(static_cast<unsigned int>(time(NULL)));
    for (int ri = 0; ri < 15; ri++)
    {
        for (int ci = 0; ci < 30; ci++)
        {
            World[ri][ci] = rand() % 2 == 0 ? ' ' : '#'; 
        }
    }
    World[3][9] = '#';
    World[3][10] = '#';
    World[3][12] = '#';
    World[3][13] = '#';
    World[4][8] = '#';
    World[4][11] = '#';
    World[4][14] = '#';
    World[5][7] = '#';
    World[5][15] = '#';
    World[6][7] = '#';
    World[6][15] = '#';
    World[7][10] = '#';
    World[7][11] = '#';
    World[8][9] = '#';
    World[8][12] = '#';
}
int neighbourhoodLivesCount4(const char World[][30], int ri, int ci, char LS) 
{
    int Count = 0;
    for (int r = ri - 1; r <= ri + 1; r++) 
    {
        if (r < 0 || r == 15)
            continue;
        for (int c = ci - 1; c <= ci + 1; c++)
        {
            if (c < 0 || c == 30)
                continue;
            if (r == ri && c == ci)
                continue;
            if (World[r][c] == LS)
                Count++;
        }
    }
    return Count;
}
void repopulate4(char World[][30], char Sym) 
{
    char DWorld[15][30];

    for (int ri = 0; ri < 15; ri++) 
    {
        for (int ci = 0; ci < 30; ci++)
        {
            int count = neighbourhoodLivesCount4(World, ri, ci, Sym);
            if (World[ri][ci] == Sym && count < 2)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == Sym && (count == 2 || count == 3))
            {
                DWorld[ri][ci] = Sym;
            }
            else if (World[ri][ci] == Sym && count > 3) 
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == ' ' && count == 3) 
            {
                DWorld[ri][ci] = Sym;
            }
            else
            {
                DWorld[ri][ci] = World[ri][ci];
            }
        }
    }

    for (int ri = 0; ri < 15; ri++)
    {
        for (int ci = 0; ci < 30; ci++)
            World[ri][ci] = DWorld[ri][ci];
    }
}
int main4()
{
    char world[15][30];

    generateRandomComplexPattern4(world);
    display4(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen)
    {
        repopulate4(world, '#'); 
        display4(world);
        Sleep(50); 
    }

    return 0;
}

void display5(const char World[][20])
{
    system("cls");
    for (int ri = 0; ri < 20; ri++) 
    {
        for (int ci = 0; ci < 20; ci++) 
        {
            cout << World[ri][ci] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void generateRandomGliderPattern5(char World[][20])
{
    srand(static_cast<unsigned int>(time(NULL)));
    for (int ri = 0; ri < 20; ri++)
    {
        for (int ci = 0; ci < 20; ci++)
        {
            World[ri][ci] = ' ';
        }
    }

    int startRow = rand() % (20 - 4); 
    int startCol = rand() % (20 - 4); 

    World[startRow][startCol + 1] = '#';
    World[startRow + 1][startCol + 2] = '#';
    World[startRow + 2][startCol] = '#';
    World[startRow + 2][startCol + 1] = '#';
    World[startRow + 2][startCol + 2] = '#';
}
int neighbourhoodLivesCount5(const char World[][20], int ri, int ci, char LS)
{
    int Count = 0;
    for (int r = ri - 1; r <= ri + 1; r++)
    {
        if (r < 0 || r == 20)
            continue;
        for (int c = ci - 1; c <= ci + 1; c++) 
        {
            if (c < 0 || c == 20)
                continue;
            if (r == ri && c == ci)
                continue;
            if (World[r][c] == LS)
                Count++;
        }
    }
    return Count;
}
void repopulate5(char World[][20], char Sym)
{
    char DWorld[20][20];

    for (int ri = 0; ri < 20; ri++)
    {
        for (int ci = 0; ci < 20; ci++)
        {
            int count = neighbourhoodLivesCount5(World, ri, ci, Sym);
            if (World[ri][ci] == Sym && count < 2)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == Sym && (count == 2 || count == 3)) 
            {
                DWorld[ri][ci] = Sym;
            }
            else if (World[ri][ci] == Sym && count > 3)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == ' ' && count == 3)
            {
                DWorld[ri][ci] = Sym;
            }
            else
            {
                DWorld[ri][ci] = World[ri][ci];
            }
        }
    }

    for (int ri = 0; ri < 20; ri++)
    {
        for (int ci = 0; ci < 20; ci++)
            World[ri][ci] = DWorld[ri][ci];
    }
}
int main5()
{
    char world[20][20];

    generateRandomGliderPattern5(world);
    display5(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen) 
    {
        repopulate5(world, '#'); 
        display5(world);
        Sleep(50); 
    }

    return 0;
}

void display6(const char World[][Cols])
{
    system("cls");
    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++) 
        {
            cout << World[ri][ci] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void generateMazePattern6(char World[][Cols])
{
    srand(static_cast<unsigned int>(time(NULL)));
    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++) 
        {
            if (ri % 2 == 0 || ci % 2 == 0)
            {
                World[ri][ci] = '#'; 
            }
            else {
                World[ri][ci] = ' '; 
            }
        }
    }
    World[1][0] = ' ';
    World[Rows - 2][Cols - 1] = ' ';
}
int neighbourhoodLivesCount6(const char World[][Cols], int ri, int ci, char LS)
{
    int Count = 0;
    for (int r = ri - 1; r <= ri + 1; r++)
    {
        if (r < 0 || r == Rows)
            continue;
        for (int c = ci - 1; c <= ci + 1; c++) 
        {
            if (c < 0 || c == Cols)
                continue;
            if (r == ri && c == ci)
                continue;
            if (World[r][c] == LS)
                Count++;
        }
    }
    return Count;
}
void repopulate6(char World[][Cols], char Sym)
{
    char DWorld[Rows][Cols];

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            int count = neighbourhoodLivesCount6(World, ri, ci, Sym);
            if (World[ri][ci] == Sym && count < 2)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == Sym && (count == 2 || count == 3))
            {
                DWorld[ri][ci] = Sym;
            }
            else if (World[ri][ci] == Sym && count > 3) 
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == ' ' && count == 3) 
            {
                DWorld[ri][ci] = Sym;
            }
            else {
                DWorld[ri][ci] = World[ri][ci];
            }
        }
    }

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
            World[ri][ci] = DWorld[ri][ci];
    }
}
int main6()
{
    char world[Rows][Cols];

    generateMazePattern6(world);
    display6(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen) 
    {
        repopulate6(world, '#'); 
        display6(world);
        Sleep(50); 
    }

    return 0;
}

void display7(const char World[][Cols]) 
{
    system("cls");
    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            cout << World[ri][ci] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void generateRandomPattern7(char World[][Cols])
{
    srand(static_cast<unsigned int>(time(NULL)));
    for (int ri = 0; ri < Rows; ri++) {
        for (int ci = 0; ci < Cols; ci++) {
            World[ri][ci] = rand() % 2 == 0 ? '#' : ' '; 
        }
    }
}
int neighbourhoodLivesCount7(const char World[][Cols], int ri, int ci, char LS) 
{
    int Count = 0;
    for (int r = ri - 1; r <= ri + 1; r++)
    {
        if (r < 0 || r == Rows)
            continue;
        for (int c = ci - 1; c <= ci + 1; c++) 
        {
            if (c < 0 || c == Cols)
                continue;
            if (r == ri && c == ci)
                continue;
            if (World[r][c] == LS)
                Count++;
        }
    }
    return Count;
}
void repopulate7(char World[][Cols], char Sym)
{
    char DWorld[Rows][Cols];

    for (int ri = 0; ri < Rows; ri++) 
    {
        for (int ci = 0; ci < Cols; ci++) 
        {
            int count = neighbourhoodLivesCount7(World, ri, ci, Sym);
            if (World[ri][ci] == Sym && count < 2)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == Sym && (count == 2 || count == 3))
            {
                DWorld[ri][ci] = Sym;
            }
            else if (World[ri][ci] == Sym && count > 3)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == ' ' && count == 3)
            {
                DWorld[ri][ci] = Sym;
            }
            else 
            {
                DWorld[ri][ci] = World[ri][ci];
            }
        }
    }

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
            World[ri][ci] = DWorld[ri][ci];
    }
}
int main7()
{
    char world[Rows][Cols];

    generateRandomPattern7(world);
    display7(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen) {
        repopulate7(world, '#'); 
        display7(world);
        Sleep(50); 
    }

    return 0;
}

void display8(const char World[][Cols])
{
    system("cls");
    for (int ri = 0; ri < Rows; ri++) 
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            cout << World[ri][ci] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void generateBPattern8(char World[][Cols])
{
    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++) 
        {
            World[ri][ci] = ' ';
        }
    }
    World[15][10] = '#';
    World[15][11] = '#';
    World[15][12] = '#';
    World[15][13] = '#';
    World[15][14] = '#';
    World[16][10] = '#';
    World[17][10] = '#';
    World[17][12] = '#';
    World[18][11] = '#';
    World[18][13] = '#';
    World[19][12] = '#';
    World[19][14] = '#';
    World[19][15] = '#';
    World[20][12] = '#';
    World[21][12] = '#';
    World[22][12] = '#';
    World[22][13] = '#';
    World[22][14] = '#';
}
int neighbourhoodLivesCount8(const char World[][Cols], int ri, int ci, char LS) 
{
    int Count = 0;
    for (int r = ri - 1; r <= ri + 1; r++) 
    {
        if (r < 0 || r == Rows)
            continue;
        for (int c = ci - 1; c <= ci + 1; c++)
        {
            if (c < 0 || c == Cols)
                continue;
            if (r == ri && c == ci)
                continue;
            if (World[r][c] == LS)
                Count++;
        }
    }
    return Count;
}
void repopulate8(char World[][Cols], char Sym)
{
    char DWorld[Rows][Cols];

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            int count = neighbourhoodLivesCount8(World, ri, ci, Sym);
            if (World[ri][ci] == Sym && count < 2) 
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == Sym && (count == 2 || count == 3))
            {
                DWorld[ri][ci] = Sym;
            }
            else if (World[ri][ci] == Sym && count > 3)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == ' ' && count == 3) 
            {
                DWorld[ri][ci] = Sym;
            }
            else {
                DWorld[ri][ci] = World[ri][ci];
            }
        }
    }

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
            World[ri][ci] = DWorld[ri][ci];
    }
}
int main8()
{
    char world[Rows][Cols];

    generateBPattern8(world);
    display8(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen) 
    {
        repopulate8(world, '#'); 
        display8(world);
        Sleep(50); 
    }

    return 0;
}

void display9(const char World[][Cols])
{
    system("cls");
    for (int ri = 0; ri < Rows; ri++) 
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            cout << World[ri][ci] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void generateSimilarBPattern9(char World[][Cols])
{
    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            World[ri][ci] = ' ';
        }
    }
    World[10][10] = '#';
    World[11][10] = '#';
    World[12][10] = '#';
    World[13][10] = '#';
    World[14][10] = '#';
    World[11][12] = '#';
    World[12][12] = '#';
    World[13][12] = '#';
    World[14][12] = '#';
    World[10][11] = '#';
    World[10][13] = '#';
}
int neighbourhoodLivesCount9(const char World[][Cols], int ri, int ci, char LS)
{
    int Count = 0;
    for (int r = ri - 1; r <= ri + 1; r++)
    {
        if (r < 0 || r == Rows)
            continue;
        for (int c = ci - 1; c <= ci + 1; c++)
        {
            if (c < 0 || c == Cols)
                continue;
            if (r == ri && c == ci)
                continue;
            if (World[r][c] == LS)
                Count++;
        }
    }
    return Count;
}
void repopulate9(char World[][Cols], char Sym)
{
    char DWorld[Rows][Cols];

    for (int ri = 0; ri < Rows; ri++) 
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            int count = neighbourhoodLivesCount9(World, ri, ci, Sym);
            if (World[ri][ci] == Sym && count < 2)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == Sym && (count == 2 || count == 3))
            {
                DWorld[ri][ci] = Sym;
            }
            else if (World[ri][ci] == Sym && count > 3) 
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == ' ' && count == 3)
            {
                DWorld[ri][ci] = Sym;
            }
            else {
                DWorld[ri][ci] = World[ri][ci];
            }
        }
    }

    for (int ri = 0; ri < Rows; ri++) 
    {
        for (int ci = 0; ci < Cols; ci++)
            World[ri][ci] = DWorld[ri][ci];
    }
}
int main9()
{
    char world[Rows][Cols];

    generateSimilarBPattern9(world);
    display9(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen) 
    {
        repopulate9(world, '#'); 
        display9(world);
        Sleep(50); 
    }

    return 0;
}

void display10(const char World[][Cols])
{
    system("cls");
    for (int ri = 0; ri < Rows; ri++) 
    {
        for (int ci = 0; ci < Cols; ci++)
        {
            cout << World[ri][ci] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void generateRandomPattern10(char World[][Cols])
{
    srand(static_cast<unsigned>(time(0)));

    for (int ri = 0; ri < Rows; ++ri)
    {
        for (int ci = 0; ci < Cols; ++ci) 
        {
            World[ri][ci] = rand() % 2 == 0 ? '#' : ' ';
        }
    }
}
int neighbourhoodLivesCount10(const char World[][Cols], int ri, int ci, char LS)
{
    int Count = 0;
    for (int r = ri - 1; r <= ri + 1; r++)
    {
        if (r < 0 || r == Rows)
            continue;
        for (int c = ci - 1; c <= ci + 1; c++)
        {
            if (c < 0 || c == Cols)
                continue;
            if (r == ri && c == ci)
                continue;
            if (World[r][c] == LS)
                Count++;
        }
    }
    return Count;
}
void repopulate10(char World[][Cols], char Sym) 
{
    char DWorld[Rows][Cols];

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++) 
        {
            int count = neighbourhoodLivesCount10(World, ri, ci, Sym);
            if (World[ri][ci] == Sym && count < 2)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == Sym && (count == 2 || count == 3))
            {
                DWorld[ri][ci] = Sym;
            }
            else if (World[ri][ci] == Sym && count > 3)
            {
                DWorld[ri][ci] = ' ';
            }
            else if (World[ri][ci] == ' ' && count == 3) 
            {
                DWorld[ri][ci] = Sym;
            }
            else {
                DWorld[ri][ci] = World[ri][ci];
            }
        }
    }

    for (int ri = 0; ri < Rows; ri++)
    {
        for (int ci = 0; ci < Cols; ci++)
            World[ri][ci] = DWorld[ri][ci];
    }
}
int main10()
{
    char world[Rows][Cols];

    generateRandomPattern10(world);
    display10(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen) {
        repopulate10(world, '#'); 
        display10(world);
        Sleep(50); 
    }

    return 0;
}

#define mRows 10
#define mCols 10
#define mDepth 10

void displayFace12(const char World[][mCols])
{
    for (int r = 0; r < mRows; ++r)
    {
        for (int c = 0; c < mCols; ++c)
        {
            cout << World[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void displayAllFaces12(const char World[][mCols][mDepth])
{
    for (int d = 0; d < 6; ++d)
    {

        cout << "Face " << d + 1 << ":" << endl;
        displayFace12(World[d]);
    }
}
void generateOrthogonalSpaceship12(char World[][mCols][mDepth])
{
    for (int d = 0; d < mDepth; ++d)
    {
        for (int r = 0; r < mRows; ++r)
        {
            for (int c = 0; c < mCols; ++c)
            {
                World[d][r][c] = ' ';
            }
        }
    }

    World[mDepth / 2][4][4] = 'x';
    World[mDepth / 2][5][3] = 'x';
    World[mDepth / 2][5][4] = 'x';
    World[mDepth / 2][5][5] = 'x';
    World[mDepth / 2][6][4] = 'x';
}
int countLiveNeighbors12(const char World[][mCols][mDepth], int d, int r, int c, char LS)
{
    int count = 0;
    for (int i = d - 1; i <= d + 1; ++i)
    {
        for (int j = r - 1; j <= r + 1; ++j)
        {
            for (int k = c - 1; k <= c + 1; ++k)
            {
                if (i >= 0 && i < mDepth && j >= 0 && j < mRows && k >= 0 && k < mCols)
                {
                    if (i == d && j == r && k == c)
                        continue;
                    if (World[i][j][k] == LS)
                        count++;
                }
            }
        }
    }
    return count;
}
void repopulate3D12(char World[][mCols][mDepth], char Sym)
{
    char DWorld[mDepth][mRows][mCols];

    for (int d = 0; d < mDepth; ++d)
    {
        for (int r = 0; r < mRows; ++r)
        {
            for (int c = 0; c < mCols; ++c)
            {
                int count = countLiveNeighbors12(World, d, r, c, Sym);
                if (World[d][r][c] == Sym && count < 2)
                {
                    DWorld[d][r][c] = ' ';
                }
                else if (World[d][r][c] == Sym && (count == 2 || count == 3))
                {
                    DWorld[d][r][c] = Sym;
                }
                else if (World[d][r][c] == Sym && count > 3)
                {
                    DWorld[d][r][c] = ' ';
                }
                else if (World[d][r][c] == ' ' && count == 3)
                {
                    DWorld[d][r][c] = Sym;
                }
                else {
                    DWorld[d][r][c] = World[d][r][c];
                }
            }
        }
    }

    for (int d = 0; d < mDepth; ++d)
    {
        for (int r = 0; r < mRows; ++r)
        {
            for (int c = 0; c < mCols; ++c)
            {
                World[d][r][c] = DWorld[d][r][c];
            }
        }
    }
}
int main12()
{
    char world[mDepth][mRows][mCols];

    generateOrthogonalSpaceship12(world);
    displayAllFaces12(world);

    int generations;
    cout << "Enter the number of generations to simulate: ";
    cin >> generations;

    for (int gen = 0; gen < generations; ++gen) {
        repopulate3D12(world, 'x');
        displayAllFaces12(world);
        Sleep(50);
    }

    return 0;
}

void menu()
{
    cout << "1. 1" << endl;
    cout << "2. 2" << endl;
    cout << "3. 3" << endl;
    cout << "4. 4" << endl;
    cout << "5. 5" << endl;
    cout << "6. 6" << endl;
    cout << "7. 7" << endl;
    cout << "8. 8" << endl;
    cout << "9. 9" << endl;
    cout << "10. 10" << endl;
    cout << "11. 11" << endl;
    cout << "0. Exit" << endl;

}
int main()
{
    int choice;
    while (true)
    {
        cout << "__________________________\n" << endl;
        menu();
        cout << "__________________________\n" << endl;
        cout << "Enter Choice:";
        cin >> choice;

        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            main1();
            break;
        case 2:
            main2();
            break;
        case 3:
            main3();
            break;
        case 4:
            main4();
            break;
        case 5:
            main5();
            break;
        case 6:
            main6();
            break;
        case 7:
            main7();
            break;
        case 8:
            main8();
            break;
        case 9:
            main9();
            break;
        case 10:
            main10();
            break;
        case 11:
            main12();
            break;
        default:
            break;
        }
    }
    return 0;
}