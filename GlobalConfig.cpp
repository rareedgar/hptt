//============================================================================
// Name        : GlobalConfig.cpp
// Author      : Edgar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Config.h"
using namespace std;

Config *Config::s_instance = 0;


int main() {
	cout << "initing a config singleton" << endl;

	Config::instance()->printConfig();
	cout << "mdsock val"<< Config::instance()->getConfig("mdsocket") << endl;
	return 0;
}
