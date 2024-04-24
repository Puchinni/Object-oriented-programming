#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <vector>
#include "World.h"
#include "Organism.h"
#include "Grass.h"
#include "Kosulya.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Human.h"
#include "WolfBerries.h"
#include "FileSaver.h"
using namespace std;

int main() {
	{
		//for (int k = 0; k < 10; k++)
		//{
		//	for (int i = 0; i < 10; i++)
		//	{
		//		for (int j = 0; j < 20; j++)
		//		{
		//			cout << k;
		//		}
		//		cout << endl;
		//	}

		//	if (k == 9) {
		//		k = -1;
		//	}

		//	Sleep(100);
		//	//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		//	//SetConsoleCursorPosition(handle, COORD{0,0});
		//}
	}

	//Grass* or_ = new Grass();

	std::vector<Organism*> orgs{
		(Organism*)new Human(6, 6),
		(Organism*)new Grass(7, 5),
		//(Organism*)new Kosulya(13, 5),
		//(Organism*)new Sheep(7, 5),
		(Organism*)new Sheep(8, 4),
		//(Organism*)new WolfBerries(4, 3),
		//(Organism*)new Sheep(5, 3),
		//(Organism*)new Fox(5, 6),
		//(Organism*)new Fox(6, 6),

		//(Organism*)new Wolf(),
		//(Organism*)new Sheep(),



	};

	int row, col;
	cin >> row >> col;
	system("cls");
	World w(row, col, orgs);
	bool isDef = true;
	std::cout << "Do you want to\nRESTOR world?(y/n)\n->";
	char ch; cin >> ch;
	if (ch == 'y') {
		std::cout << "Enter file name:\n->";
		std::string fName; cin >> fName;

		if (!FileSaver::IsFileExists(fName)) {
			std::cout << "File is not exists!\n";
		}
		else {
			w.Restore(fName);
			isDef = false;
		}
	}

	if (isDef) {
		cout << "*Loading default world\nPress any key...";
	}

	do
	{
		w.DrawWorld();
		w.ExecuteTure();

	} while (w.IsContinue());

	cout << "\n\n Simulation Over!\n";
	system("pause");
	return 0;
}