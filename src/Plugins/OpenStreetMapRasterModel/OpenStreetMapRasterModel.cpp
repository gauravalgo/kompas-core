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

#include "OpenStreetMapRasterModel.h"

#include <sstream>

using namespace std;
using namespace Map2X::Core;

PLUGIN_REGISTER_STATIC(OpenStreetMapRasterModel,
                       Map2X::Plugins::OpenStreetMapRasterModel,
                       "cz.mosra.Map2X.Core.AbstractRasterModel/0.1")

namespace Map2X { namespace Plugins {

OpenStreetMapRasterModel::OpenStreetMapRasterModel(PluginManager::AbstractPluginManager* manager, const std::string& plugin): Map2XRasterModel(manager, plugin), areaOnline(0, 0, 1, 1) {
    /* All zoom levels for online maps */
    for(Zoom i = 0; i != 19; ++i)
        zoomLevelsOnline.push_back(i);

    /* All layers for online maps */
    layersOnline.push_back("Mapnik");
    layersOnline.push_back("Osmarender");
    layersOnline.push_back("Cycle");
}

string OpenStreetMapRasterModel::tileUrl(const std::string& layer, Zoom z, const TileCoords& coords) const {
    if(z > 18) return "";

    ostringstream url;
    if(layer == "Mapnik")
        url << "http://tile.openstreetmap.org/";
    else if(layer == "Osmarender")
        url << "http://tah.openstreetmap.org/Tiles/tile/";
    else if(layer == "Cycle")
        url << "http://andy.sandbox.cloudmade.com/tiles/cycle/";
    else return "";

    url << z << "/" << coords.x << "/" << coords.y << ".png";

    return url.str();
}

}}