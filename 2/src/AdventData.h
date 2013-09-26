#ifndef ADVENTDATA_H
#define ADVENTDATA_H

#include <map>
#include <vector>
#include <string>

#include "Map.h"
#include "Vocabulary.h"

struct TravelDestination {
	unsigned dest; // y
	std::vector<unsigned> verbs;
};
struct TravelLocation {
	unsigned loc; // x
	std::vector<TravelDestination> dests;
};

struct AdventData {
	Map map;
	Vocabulary vocabulary;

	std::map< unsigned, TravelLocation > dataTravelTable;

	// The vocabulary of the entire application.
	//std::map< std::string, unsigned > dataVocabulary;

	// Messages
	std::map< unsigned, std::string > dataMsgsArbitrary;
	std::map< unsigned, std::string > dataMsgsClass;

	// Objects
	std::map< unsigned, std::string > dataObj;
	std::map< unsigned, std::map< std::string, std::string > > dataObjDesc;
	std::map< unsigned, std::vector<int> > dataObjLoc; // Vector contains locations for key-object. If vector contains '-1', then the object is immovable. If the object has several locatons - it can be assumed to be immovable.

	std::map< unsigned, unsigned > dataActionDefaults;

	// std::map< unsigned, std::vector<unsigned> > dataLiquidAssets;
	// ^ We're not parsing this yet.
};

#endif //ADVENTDATA_H