//
//  main.cpp
//  (c in c++'s clothing)
//
//  Created by _Jake on 25/02/2013.
//  Copyright (c) 2013 _Jake. All rights reserved.
//
//

#include <iostream>
#include <string>
#include <vector>
#include "fmod.hpp"
#include "fmod_errors.h"

#define VERSION 0.01
#define USAGE "Usage: resound audiofile.mp3 audiofile.wav ... --config configfile.yml"

void checkErr(FMOD_RESULT res)
{
    if (res!= FMOD_OK)
    {
        std::cerr << "FMOD ERR: " << FMOD_ErrorString(res);
        exit(-1);
    }
}

int main(int argc, const char * argv[])
{
    /*
     * Parse CLI args
     */
    std::string path_config;
    std::vector<std::string> path_audio;
    
    if (argc < 2) {
        std::cout << USAGE << std::endl;
        exit(-1);
    }
    
    if (!strncmp(argv[1], "-v", 2)) {
        std::cout << "Version: " << VERSION << std::endl;
        exit(0);
    }
    else if (!strncmp(argv[1], "--help", 6)) {
        std::cout << USAGE << std::endl;
        exit(0);
    }
    
    bool cfg_set = false;
    for (int i = 1; i < argc; i++) {
        if (!cfg_set) {
            if (!strncmp(argv[i], "--config", 8) || !strncmp(argv[i], "-c", 2)) cfg_set = true;
            else path_audio.push_back(std::string(argv[i]));
        }
        else {
            path_config = argv[i];
            cfg_set = false;
        }
    }
    
    /*
     * Set up FMOD
     */
    FMOD::System     *system;
    FMOD::Sound      *sound[path_audio.size()];
    FMOD::Channel    *channel = 0;
    FMOD_RESULT       result;
    
    result = FMOD::System_Create(&system);
    checkErr(result);
    
    result = system->init(32, FMOD_INIT_NORMAL, NULL);
    checkErr(result);
    
    
    for (int i=0; i<path_audio.size(); i++) {
        result = system->createSound(path_audio[i].c_str(), FMOD_SOFTWARE, 0, &sound[i]);
        checkErr(result);
        result = sound[i]->setMode(FMOD_LOOP_NORMAL);
        checkErr(result);
    }
    
    /*
     * Play loop
     */
    do
    {
        for (int i=0; i<path_audio.size(); i++) {
            result = system->playSound(FMOD_CHANNEL_FREE, sound[i], 0, &channel);
            checkErr(result);
        }

        system->update();
    }
    
    while(1);
    
    return 0;
}

