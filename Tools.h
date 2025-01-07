#pragma once
#include "Dep.h"
#include "Canvas.h"
#include "Stamps.h"
#include "Utils.h"
#include "Mouse.h"
#include "Pallete.h"
class Tool {
    protected:
        int useColor;
    public:
        Tool(int);
        sf::Color getColor(Pallete*);
        virtual void handleEvent(LeftMouse*,Pallete*, Canvas* ) = 0;
};


class Bucket: public Tool{
    public:
        Bucket();
        void handleEvent(LeftMouse* mouse,Pallete*, Canvas* canvas);
};


class Brush: public Tool{
    protected:
        Stamp* stamp;
    public:
        Brush(Stamp* s,int);
        ~Brush();
        void handleEvent(LeftMouse* mouse,Pallete*, Canvas* canvas);
};

class Pencil: public Brush{
    public:
        Pencil();
};

class CircleBrush: public Brush{
    public:
        CircleBrush();
};

class SquareBrush: public Brush{
    public:
        SquareBrush();
};

class BackSlashBrush: public Brush{
    public:
        BackSlashBrush();
};

class ForwardSlashBrush: public Brush{
    public:
        ForwardSlashBrush();
};

class SprayBrush: public Brush{
    public:
        SprayBrush();
};

class Eraser: public Brush{
    public:
        Eraser();
};