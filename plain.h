#ifndef PLAINOBJECT_H
#define PLAINOBJECT_H

#include <iostream>

class PlainObject
{
public:
    PlainObject()
    {
        std::cout << "PlainObject created\n";
    }

    ~PlainObject()
    {
        std::cout << "PlainObject destroyed\n";
    }
};

#endif
