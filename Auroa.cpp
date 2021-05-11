#include <iostream>
#include <Windows.h>
#include <future>
#include <clocale>

#include "Auroa.h"

bool IsOpen = false;
int CPV = 1;
int Delay = 100;

Auroa au;

void Auroa::StartAuroa() {
	system("cls");
	//Fonksyon başlatmaları
	auto AuMain = std::async(std::launch::async, &Auroa::AuroaMain, au);
	auto AuText = std::async(std::launch::async, &Auroa::Yazi, au);
}

int Auroa::AuroaMain() {

	setlocale(LC_ALL, "Turkish");
	while (true) {
		if (((GetAsyncKeyState(VK_F7)) && (IsOpen == true))) IsOpen = false;
		else if ((GetAsyncKeyState(VK_F8) && (IsOpen == false))) IsOpen = true;

		if (IsOpen == true) {
			for (int i = 0; i <= CPV; i++) {
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(Delay);
			}
		}

		if (GetAsyncKeyState(VK_F5)) {
			system("cls");
			while (true) {
				std::cout << "Lutfen Sayi Seklinde Delay giriniz. (Tikladiktan sonra bekleme suresi. MAX= 100000, MIN= 0): ";
				std::cin >> Delay;
				if (Delay <= 100000 && Delay >= 0) {
					while (true) {
						std::cout << "\n\nLutfen sayi seklinde CPV giriniz. (Belirtilen zaman basi tiklama. MAX= 99, MIN = 1";
						std::cin >> CPV;
						if (CPV <= 99 && CPV >= 1) {
							system("cls");
							std::cout << "Basariyla Degerler Degistirildi.";
							Sleep(1000);
							system("cls");
							auto AuStart = std::async(std::launch::async, &Auroa::StartAuroa, au);
							return 0;
						}
						else { std::cout << "\n\nUygun bir sayi giriniz.\n\n\n"; }
					}
				}
				else { std::cout << "\n\nUygun bir sayi giriniz.\n\n\n"; }
			}
		}
	}
}

void Auroa::Yazi() {
	setlocale(LC_ALL, "Turkish");
	std::cout << "AuroaCNAU'ya hosgeldiniz. \n\n\nF8 = Baslat\nF7 = Durdur\n\nF5 = Degerleri degistir.\n\n\nSeuika tarafindan kodlanmistir.";
}