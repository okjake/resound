//
//  main.cpp
//  playq
//
//  Created by _Jake on 25/02/2013.
//  Copyright (c) 2013 _Jake. All rights reserved.
//

#include <iostream>
#include "fmod.hpp"
#include "fmod_errors.h"

void checkErr(FMOD_RESULT res)
{
    if (res!= FMOD_OK)
    {
        std::cerr << "ERR: " << FMOD_ErrorString(res);
        exit(-1);
    }
}

int main(int argc, const char * argv[])
{

    /*
     * TODO error handling for cli args
     */
    
    FMOD::System     *system;
    FMOD::Sound      *sound;
    FMOD::Channel    *channel = 0;
    FMOD_RESULT       result;
    unsigned int      version;
    
    result = FMOD::System_Create(&system);
    checkErr(result);
    
    result = system->getVersion(&version);
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

