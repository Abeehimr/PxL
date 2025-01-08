#pragma once
#include "Dep.h"
#include "Canvas.h"
#include "Stamps.h"
#include "Utils.h"
#include "Mouse.h"
#include "Pallete.h"
class Tool {
    protected:
        Stamp* stamp;
        int useColor;
    public:
        Tool(int,Stamp* s = nullptr);
        virtual ~Tool();
        void setStamp(Stamp* s = nullptr);
        Stamp* getStamp();
        void setStampRadius(int);
        void incStampRadius();
        void decStampRadius();
        int getStampRadius();
        sf::Color getColor(Pallete*);
        virtual void handleEvent(LeftMouse*,Pallete*, Canvas* ) = 0;
};


class EyeDropper: public Tool{
    public:
        EyeDropper();
        void handleEvent(LeftMouse* mouse,Pallete*, Canvas* canvas);
};

class Bucket: public Tool{
    public:
        Bucket();
        void handleEvent(LeftMouse* mouse,Pallete*, Canvas* canvas);
};

// basically represent free hand drawing
class Brush: public Tool{
    public:
        Brush(Stamp* s,int x = 0);
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

class Line: public Tool{
    public:
        Line();
        void handleEvent(LeftMouse* mouse,Pallete*, Canvas* canvas);
};