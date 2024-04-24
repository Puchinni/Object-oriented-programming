#pragma once
#include "Organism.h"
//#include "WorldData.h"
#include <vector>
#include <string>

class Organism;
//class WorldData;
class World
{
private:
    
    Organism*** organismsBoard = nullptr;
    int row, col;
    void ClearBoard();
    int step = 0;
    const int saveNotifyCount = 15;
    int saveNotify = -2;
    std::vector<std::string> messages;

    void PrintMessage(int x, int y, const std::string& msg);
    void PrintMessages();
    void SaveRequest();
public:
    void Save(const std::string& fName);
    void Restore(const std::string& fName);
    World(int row, int col, const std::vector<Organism*>& organisms);


    int GetRow();
    int GetCol();

    bool isEmptyCell(int x, int y);
    bool isCellExists(int x, int y);

    bool IsContinue();

    Organism* GetOrganismByPosition(int x, int y);
    void SetOrganismOnBoard(int x, int y, Organism* org);

    ~World();

    void ExecuteTure();
    void DrawWorld();

    std::vector<Organism*> organisms;
    //friend class WorldData;
};

