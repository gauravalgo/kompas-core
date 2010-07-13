/*
    Copyright © 2007, 2008, 2009, 2010 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Map2X.

    Map2X is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Map2X is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include "AbstractAnimal.h"

namespace Map2X { namespace PluginManager { namespace Test {

class Canary: public AbstractAnimal {
    public:
        std::string name() { return "Achoo"; }
        int legCount() { return 2; }
        bool hasTail() { return true; }
};

PLUGIN_REGISTER(Canary, "cz.mosra.Map2X.PluginManager.Test.AbstractAnimal/1.0")
PLUGIN_SET_NAME("I'm allergic to canaries!")
PLUGIN_FINISH

}}}
