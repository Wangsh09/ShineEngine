//
// Created by Administrator on 2017/7/4.
//

#include "Configuration.h"

Configuration* Configuration::s_sharedConfiguration = nullptr;

Configuration::Configuration()
{
}

Configuration* Configuration::getInstance()
{
    if (! s_sharedConfiguration)
    {
        s_sharedConfiguration = new (std::nothrow) Configuration();
        s_sharedConfiguration->init();
    }

    return s_sharedConfiguration;
}

bool Configuration::init()
{
    return true;
}