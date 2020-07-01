#include<fstream>

using namespace std;
void Create()
{
    std::fstream file;
    file.open("BegPrevGames.txt", std::ios::app);
    file.close();

    file.open("IntPrevGames.txt", std::ios::app);
    file.close();

    file.open("AdvPrevGames.txt", std::ios::app);
    file.close();
}
