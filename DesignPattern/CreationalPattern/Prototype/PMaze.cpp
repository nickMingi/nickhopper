#include <iostream>
using namespace std;

class MazePrototypeFactory : public MazeFactory{
    public:
        MazePrototypeFactory(Maze*, Wall*, Room*, Door*);
        virtual Maze* MakeMaze() const;
        virtual Room* MakeRoom(int) const;
        virtual Wall* MakeWall() const;
        virtual Door* MakeDoor(Room*, Room*) const;
    private:
        Maze* _prototypeMaze;
        Room* _prototypeRoom;
        Wall* _prototypeWall;
        Door* _prototypeDoor;
};

MazePrototypeFactory::MazePrototypeFactory(Maze* m, Wall* w, Room* r, Door* d){
    _prototypeMaze = m;
    _prototypeWall = w;
    _prototypeRoom = r;
    _prototypeDoor = d;
}

Wall* MazePrototypeFactory::MakeWall() const{
    return _prototypeWall->Clone();
}

Door* MazePrototypeFactory::MakeDoor(Room* r1, Room* r2) const{
    Door* door = _prototypeDoor->Clone();
    door->Initialize(r1, r2);
    return door;
}

int main()
{

}