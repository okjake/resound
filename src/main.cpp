//
//  main.cpp
//  playq
//
//  Created by _Jake on 25/02/2013.
//  Copyright (c) 2013 _Jake. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "fmod.hpp"
#include "fmod_errors.h"

#define MAX_AUDIO_FILES 32
#define VERSION 0.01
#define USAGE "Usage: resound \"/path/to/audiofile\" \"/path/to/audiofile_two\" --config \"/path/to/config_file\""

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
            if (!strncmp(argv[i], "--config", 8) || !strncmp(argv[i], "-c", 2)) {
                cfg_set = true;
            }
            else {
                path_audio.push_back(argv[i]);
            }
        }
        else {
            path_config = argv[i];
            cfg_set = false;
        }
    }
    
    FMOD::System     *system;
    FMOD::Sound      *sound;
    FMOD::Channel    *channel = 0;
    FMOD_RESULT       result;
    
    result = FMOD::System_Create(&system);
    checkErr(result);
    
    result = system->init(32, FMOD_INIT_NORMAL, NULL);
    checkErr(result);
    result = system->createSound(argv[1], FMOD_SOFTWARE, 0, &sound);
    checkErr(result);
    
    result = sound->setMode(FMOD_LOOP_OFF);
    checkErr(result);
    
    do
    {
        result = system->playSound(FMOD_CHANNEL_FREE, sound, 0, &channel);
        checkErr(result);
        system->update();
    }
    
    while(1);
    
    return 0;
}

