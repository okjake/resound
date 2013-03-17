//
//  config.cpp
//  resound
//
//  Created by _Jake on 27/02/2013.
//  Copyright (c) 2013 _Jake. All rights reserved.
//

#include <fstream>
#include "config.h"
#include "json.h"

#define ERR_OP_WRAP_BEGIN "\n\n\033[1;31m"
#define ERR_OP_WRAP_END   "\033[0m\n"

Config* Config::mInstance = NULL;

Config* Config::getInstance() {

    if(!mInstance) {
        mInstance = new Config;
    }
    
    return mInstance;
}

void Config::set(std::string fp) {
    
    /*
     * Open the config JSON and store it in contents string
     */
    std::string contents, line;
    std::ifstream config_file(fp);
    
    if (config_file.is_open()) {
        while(config_file.good()) {
            getline(config_file, line);
            contents.append(line);
        }
        config_file.close();
    }
    else {
        std::cerr << ERR_OP_WRAP_BEGIN << "Could not open " << fp << ERR_OP_WRAP_END << std::endl;
        return;
    }
    
    /*
     * Try to parse contents string
     */
    Json::Value root;
    Json::Reader reader;
    
    if (!reader.parse(contents, root)) {
        std::cerr << ERR_OP_WRAP_BEGIN << "Error parsing " << fp << std::endl << std::endl;
        std::cerr << reader.getFormatedErrorMessages() << ERR_OP_WRAP_END << std::endl;
        return;
    }
    
    const Json::Value files = root["files"];
    for ( int i = 0; i < files.size(); ++i ) {
        std::cout << files[i].asString() << std::endl;
    }
    
}