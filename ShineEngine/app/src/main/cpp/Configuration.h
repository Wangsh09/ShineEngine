//
// Created by Administrator on 2017/7/4.
//

#ifndef SHINEENGINE_CONFIGURATION_H
#define SHINEENGINE_CONFIGURATION_H

#include <string>
#include "utility.h"

class Configuration {

public:

    /** Returns a shared instance of Configuration.
     *
     * @return An autoreleased Configuration object.
     */
    static Configuration *getInstance();

    /** Initialize method.
     *
     * @return Is true if initialize success.
     */
    bool init();

private:
    Configuration(void);
    static Configuration    *s_sharedConfiguration;

};


#endif //SHINEENGINE_CONFIGURATION_H
