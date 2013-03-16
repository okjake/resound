//
//  config.cpp
//  resound
//
//  Created by _Jake on 27/02/2013.
//  Copyright (c) 2013 _Jake. All rights reserved.
//

#include "config.h"
#include "json.h"

Config* Config::mInstance = NULL;

Config* Config::getInstance() {

    if(!mInstance) {
        mInstance = new Config;
    }
    
    return mInstance;
}

void Config::set(std::string fp) {

    // Parse this.
    Json::Value root;
    Json::Reader reader;
    
    if (!reader.parse(fp.c_str(), root)) {
        std::cout << "\033[1;31mError parsing " << fp << "\033[0m\n" << std::endl;
        return;
    }
    
    const Json::Value files = root["files"];
    for ( int i = 0; i < files.size(); ++i ) {
        std::cout << files[i].asString() << std::endl;
    }
    
}