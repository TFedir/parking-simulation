#define _USE_MATH_DEFINES
#include <cmath>
#include "..//Parking/Parking.h"
#include "..//Parking/Driver.h"
#include "..//Parking/Vehicle.h"
#include "..//Parking/TwoTrackVehicle.h"
#include "..//ConsoleGUI/Drawer.h"
#include "..//ConsoleGUI/Object.h"
#include "..//ConsoleGUI/Screen.h"
#include <iostream>
#include <windows.h>
#include <memory>

void ClearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

std::shared_ptr<Car> createCar(int x, int y)
{
    int weight = 1000;
    int width = 6;
    int length = 3;
    int height = 2;
    std::string name = "opel";
    std::string registrationNo = "1234";
    double maxWheelAngle = 45;
    Engine engine;
    auto car = std::make_shared<Car>(x, y, weight, width, length, height, '8', Dir::east, name, registrationNo, maxWheelAngle, engine);
    return car;
}

void refreshConsole(std::shared_ptr<Drawer> drawer)
{
    drawer->redrawObjects();
    Sleep(300);
    ClearScreen();
    drawer->outputScreen();
}

int main()
{
    int size = 30;
    std::shared_ptr<Drawer> drawer = std::make_shared<Drawer>(size, size, std::cout);
    Parking parking(size, size, drawer);
    /*parking.drawParking();
    std::shared_ptr<Car> car = createCar(0, 1);
    std::shared_ptr<Car> newCar = createCar(0, 7);
    SupremeDriver driver(car, 'o', drawer);
    SupremeDriver newDriver(newCar, 'o', drawer);
    parking.addObject(driver.getObject());
    parking.addObject(newDriver.getObject());
    refreshConsole(drawer);*/
    //driver.parkIn(5, 5);
    //newDriver.parkIn(5, 7);
    std::shared_ptr<Object> obj = std::make_shared<Object>(10, 10, 3, 3, '*', Dir::west, M_PI/4);
    parking.addObject(obj);
    //drawer->getScreen()->clearScreen();
    auto tempv = parking.findOccupied();
    drawer->getScreen()->deleteObject(obj->getX(), obj->getY());
    for (auto pair : tempv)
    {
            std::shared_ptr<Object> temp = std::make_shared<Object>(pair.first, pair.second, 1, 1, '*');
            parking.addObject(temp);
            drawer->getScreen()->changePoint(pair.first, pair.second, '*');
    }
    refreshConsole(drawer);
}
