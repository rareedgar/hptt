/*
 * Config.h
 *
 *  Created on: Mar 24, 2018
 *      Author: raree
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include<map>

using namespace std;
class Config {

	public:
	static Config *instance()
	{
	        if (!s_instance)
	          s_instance = new Config();
	        return s_instance;
	}
	void printConfig();
	string getConfig(const string& key);


	private:
	Config();
	virtual ~Config();
	void load();
	void insertConfigMap(string line);


	static Config *s_instance;

	map<string, string> ConfigMap;
};

#endif /* CONFIG_H_ */
