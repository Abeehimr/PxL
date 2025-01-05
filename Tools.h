#pragma once
#include "Dep.h"
#include "Canvas.h"
#include "Stamps.h"
#include "Utils.h"
#include "Mouse.h"

class Tool {
    public:
        virtual void handleEvent(LeftMouse*,sf::Color, Canvas* ) = 0;
};


class Bucket: public Tool{
    public:
        void handleEvent(LeftMouse* mouse,sf::Color color, Canvas* canvas);
};


class Brush: public Tool{
    protected:
        Stamp* stamp;
    public:
        Brush(Stamp* s);
        ~Brush();
        void handleEvent(LeftMouse* mouse,sf::Color color, Canvas* canvas);
};

class Pencil: public Brush{
    public:
        Pencil():Brush(new Point()){};
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