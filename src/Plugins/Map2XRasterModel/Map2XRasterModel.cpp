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

#include "Map2XRasterModel.h"

using namespace std;
using namespace Map2X::Core;

PLUGIN_REGISTER_STATIC(Map2XRasterModel,
                       Map2X::Plugins::Map2XRasterModel,
                       "cz.mosra.Map2X.Core.AbstractRasterModel/0.1")

namespace Map2X { namespace Plugins {

int Map2XRasterModel::addPackage(const string& filename) {
    return -1;
}

string Map2XRasterModel::tileFromPackage(const string& layer, Zoom z, const TileCoords& coords) {
    return "";
}

}}
