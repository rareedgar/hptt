/*
 * Config.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: raree
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Config.h"

using namespace std;

Config::Config() {
	// TODO Auto-generated constructor stub
   load();
}

Config::~Config() {
	// TODO Auto-generated destructor stub
}

void Config::load() {

	cout << "loading..." << endl;
	string filename = "config.txt";
	ifstream ifs(filename.c_str());
	string line;

	if(ifs.good())
	{
		while(getline(ifs,line))
		{
			cout << line << endl;
			insertConfigMap(line);
		}
	}
	else
		cout << "couldnt open " << filename.c_str() << endl;
}

void Config::printConfig() {
	cout << "printing all the params" << endl;
	map<string, string>::iterator it;

	for(it = ConfigMap.begin(); it != ConfigMap.end(); ++it)
		cout << it->first.c_str() << "  " << it->second.c_str() << endl;
}

string Config::getConfig(const string& key) {

	if( ConfigMap.find(key) == ConfigMap.end() )
		return " ";
    else
    	return ConfigMap[key];

}

void Config::insertConfigMap(string line) {

	stringstream ss(line);
	vector<string> tokens;
	string token;
	while (getline(ss, token, ' ')) {
	        tokens.push_back(token);
	}
	cout << " Tok1 " << tokens[0] << " Tok2 " << tokens[1] << endl;
	ConfigMap[tokens[0]] = tokens[1];
}
