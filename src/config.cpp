//
//  config.cpp
//  resound
//
//  Created by _Jake on 27/02/2013.
//  Copyright (c) 2013 _Jake. All rights reserved.
//

#include "config.h"
#include "json.h"

using namespace std;

Config* Config::mInstance = NULL;

Config* Config::getInstance() {
    
    if(!mInstance) {
        mInstance = new Config;
    }
    
    return mInstance;
}

void Config::set(std::string fp) {
    
    // Parse this.
    
}