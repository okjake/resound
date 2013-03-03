//
//  config.h
//  resound
//
//  Created by _Jake on 27/02/2013.
//  Copyright (c) 2013 _Jake. All rights reserved.
//

#ifndef __resound__Config__
#define __resound__Config__

#include <string>
#include <vector>

class Config {
    
    public:
        static Config* getInstance();
        void set(std::string filePath);
    
    private:
        static Config* mInstance;
        Config() {};
        Config(Config const&);
        void operator=(Config const&);
    
};

#endif /* defined(__resound__Config__) */
