#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

#include "Verb.h"
#include "Object.h"
#include "Destination.h"

class Location {
public:
	Location();
	Location( unsigned p_id, std::string p_descShort, std::vector< std::string > p_descLongs );
	~Location();

	void appendDestination( Destination p_destination );
	void appendObject( Object p_object );

	void setId( unsigned p_id );
	void setDescShort( std::string p_descShort );
	void appendDescLong( std::string p_descLong );

	unsigned getId() const;
	std::string getDescShort() const;
	std::string getDescLong() const;
	std::vector< std::string > getDescLongs() const;
	std::vector< Object > getObjects() const;
	unsigned getNumDestinations() const;

	Destination& operator[]( unsigned p_id );
protected:
private:
	// Data describing the location:
	unsigned m_id; // x
	std::string m_descShort;
	std::vector< std::string > m_descLongs;

	// Items:
	std::vector< Object > m_objects;

	// Travel:
	std::vector<Destination> m_destinations; // Consider implementing the Location/Destination paradigm as a linked graph.
};

#endif // LOCATION_H