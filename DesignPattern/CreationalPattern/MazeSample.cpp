#include <iostream>
using namespace std;

class MapSite{
    public:
        virtual void Enter() = 0;
};

class Room : public MapSite{
    public:
        Room(int roomNo);
        MapSite* GetSide(Direction) const;
        void SetSide(Direction, MapSite*);
        virtual void Enter();
    private:
        MapSite* _sides[4];
        int _roomNumber;
};

class Wall : public MapSite{
    public:
        Wall();
        virtual void Enter();
};

class Door : public MapSite{
    public:
        Door(Room* = 0, Room* = 0);
        virtual void Enter();
        Room* OtherSideFrom(Room*);
    private:
        Room* _room1;
        Room* _room2;
        bool _isOpen;
};

class Maze{
    public:
        Maze();
        void AddRoom(Room*);
        Room* RoomNo(int) const;
    private:
};

Maze* MazeGame::CreateMaze(){
    Maze* aMaze = new Maze;
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* theDoor = new Door(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, new Wall);
    r1->SetSide(East, theDoor);
    r1->SetSide(South, new Wall);
    r1->SetSide(West, new Wall);

    r2->SetSide(North, new Wall);
    r2->SetSide(East, new Wall);
    r2->SetSide(South, new Wall);
    r2->SetSide(West, theDoor);
    return aMaze;
}

int main()
{
    
}