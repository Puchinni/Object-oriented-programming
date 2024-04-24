#include "World.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include "Animal.h"
#include "fstream"
//#include "FileSaver.h"
#include <conio.h>
#include "OrganismFactory.h"

void World::ClearBoard()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            organismsBoard[i][j] = nullptr;
        }
    }

    messages.clear();

    if (saveNotify == 0) {
        std::string clearStr(50, ' ');
        PrintMessage(col + 5, 0, clearStr);
        PrintMessage(col + 5, 1, clearStr);
        PrintMessage(col + 5, 2, clearStr);
        PrintMessage(col + 5, 3, clearStr);
        PrintMessage(0, 0, "");
    }

}

Organism* World::GetOrganismByPosition(int x, int y)
{
    for (auto org : organisms) {
        if (org->GetX() == x && org->GetY() == y) {
            return org;
        }
    }
    
    return nullptr;
}

void World::SetOrganismOnBoard(int x, int y, Organism* org)
{
    organismsBoard[y][x] = org;
}

void World::PrintMessage(int x, int y, const std::string& msg)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, COORD{ (SHORT)x, (SHORT)y });

    std::cout << std::string(25, ' ');
    SetConsoleCursorPosition(handle, COORD{ (SHORT)x, (SHORT)y });
    std::cout << msg;

}

void World::PrintMessages()
{
    for (int i = 0; i < messages.size(); i++)
    {

        PrintMessage(col+5, 3+i, messages[i]);
    }
}

void World::SaveRequest()
{
    saveNotify++;
    if (saveNotify == saveNotifyCount) {
        saveNotify = 0;
        PrintMessage(col + 5, 0, "Do you want save game?(y/n)");
        PrintMessage(col + 5, 1, "-> ");
        char ch; std::cin >> ch;
        if (ch == 'y') {
            PrintMessage(col + 5, 2, "Enter name: ");
            std::string fName; std::cin >> fName;
            Save(fName);
            PrintMessage(col + 5, 3, "Complete! Press any key...");
            _getch();
        }
    }
}

void World::Save(const std::string& fName)
{
    std::ofstream fout;

    fout.open(fName);

    fout << row << ' ' << col << std::endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fout << ((this->organismsBoard[i][j] == nullptr)
                    ? (char)OrganismType::EMPTY
                    : this->organismsBoard[i][j]->Draw());
        }
        fout << std::endl;
    }
}

void World::Restore(const std::string& fName)
{
    std::ifstream fin;
    fin.open(fName);

    for (int i = 0; i < row; i++)
    {
        delete[] organismsBoard[i];
    }
    delete organismsBoard;

    for (auto o : organisms) {
        delete[] o;
    }
    organisms.clear();
    messages.clear();

    fin >> row >> col; fin.get();
    organismsBoard = new Organism * *[row];
    for (int i = 0; i < row; i++)
    {
        organismsBoard[i] = new Organism * [col];
    }

    for (int i = 0; i < row; i++)
    {
        std::string line; std::getline(fin, line);
        for (int j = 0; j < col; j++)
        {
            //char ch =  fin.get();//fin.read((char*)(&ch), sizeof(OrganismType)); //>> ch;
            char ch = line[j];
            std::cout << line[j];
            organismsBoard[i][j] = OrganismFactory::Create((OrganismType)line[j], j, i);
            if(organismsBoard[i][j]!=nullptr)
            organisms.push_back(organismsBoard[i][j]);
        }
        //char c = fin.get();
        std::cout << std::endl;
    }
    std::cout << "Complete! Press any key...\n";
    _getch();
}

int World::GetRow()
{
    return row;
}
int World::GetCol()
{
    return col;
}
bool World::isEmptyCell(int x, int y)
{
    return organismsBoard[y][x] == nullptr;
}
bool World::isCellExists(int x, int y)
{
    return !(x < 0 || x >= col || y < 0 || y >= row);
}
bool World::IsContinue()
{
    return row*col > organisms.size();
}
World::World(int row, int col, const std::vector<Organism*>& organisms)
    :row{ row }, col{ col }, organisms{organisms}
{
    this->row = row;
    this->col = col;
    this->organisms = organisms;

    organismsBoard = new Organism * *[row];
    for (int i = 0; i < row; i++)
    {
        organismsBoard[i] = new Organism * [col];
    }
    ClearBoard();

    for (auto org : organisms)
    {
        organismsBoard[org->GetY()][org->GetX()] = org;
        Animal* animal = dynamic_cast<Animal*>(org);
        if (animal != nullptr) {
            animal->SetWorld(this);
        }
    }
}

World::~World()
{
    for (auto org : organisms)
    {
        delete org;
    }

    if (organismsBoard == nullptr) {
        return;
    }

    for (int i = 0; i < row; i++)
    {
        delete[] organismsBoard[i];
    }
    delete[] organismsBoard;
}

void World::ExecuteTure()
{
    ClearBoard();
    int current_size = organisms.size();
    for (int i = 0; i < current_size; i++)
    {
        organisms[i]->Action(this);
        if (dynamic_cast<Animal*>(organisms[i]) != nullptr &&
            organismsBoard[organisms[i]->GetY()][organisms[i]->GetX()] != nullptr){
            organisms[i]->Colission(organismsBoard[organisms[i]->GetY()][organisms[i]->GetX()]);
            organismsBoard[organisms[i]->GetY()][organisms[i]->GetX()]->Colission(organisms[i]);

            messages.push_back(std::to_string(organisms[i]->Draw()) +" x "+ organismsBoard[organisms[i]->GetY()][organisms[i]->GetX()]->Draw());

        }

        organismsBoard[organisms[i]->GetY()][organisms[i]->GetX()] = organisms[i];
    }

    for (int i = current_size; i < organisms.size(); i++)
    {
        if (organismsBoard[organisms[i]->GetY()][organisms[i]->GetX()] != nullptr) {
            Organism* other = organismsBoard[organisms[i]->GetY()][organisms[i]->GetX()];
            organisms[i]->Colission(other);
            other->Colission(organisms[i]);
        }
    }

    for (int i = 0; i < organisms.size(); i++)
    {
        if (organisms[i]->IsDied()) {

            this->organismsBoard[organisms[i]->GetY()][organisms[i]->GetX()] = nullptr;

            messages.push_back(std::to_string(organisms[i]->Draw()) + "-> is died!");

            delete organisms[i];
            organisms.erase(organisms.begin() + i);
            i--;
        }
    }

    messages.push_back("H [" + std::to_string(organisms[0]->GetX()) + ";" + std::to_string(organisms[0]->GetY()) + "]");
    messages.push_back("Organism Count: "+ std::to_string(organisms.size()));

    SaveRequest();

}

void World::DrawWorld()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, COORD{0,0});
    std::cout << std::string(col + 2, '-') << std::endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j == 0) {
                std::cout << '|';
            }
            std::cout << ((this->organismsBoard[i][j] == nullptr) 
                        ? (char)OrganismType::EMPTY
                        : this->organismsBoard[i][j]->Draw());
            if (j == col-1) {
                std::cout << '|';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::string(col + 2, '-') << std::endl;
    //std::cout << "\nStep -> " << step++;

    PrintMessages();
}
