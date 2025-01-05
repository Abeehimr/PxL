#pragma once
#include "Dep.h"
#include "Canvas.h"
#include "Stamps.h"
#include "Utils.h"
#include "Mouse.h"

class Tool {
    public:
        virtual void handleEvent(LeftMouse*, Canvas* ) = 0;
};

class Pencil: public Tool{
    public:
        void handleEvent(LeftMouse* mouse, Canvas* canvas);
};