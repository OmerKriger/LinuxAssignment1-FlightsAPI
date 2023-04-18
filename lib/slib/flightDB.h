#ifndef __FLIGHT_DB_H
#define __FLIGHT_DB_H

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "airport.h"
#include "flight.h"

class FlightDatabase {
public:
    enum class DataParameters { icao24, callsign, origin, destination, departure_time, arrival_time, totalParm };
    FlightDatabase() : loaded(false) {}
    bool load_db(const std::string& dataBasePath,const std::string& airportCode);
    const std::list<Flight>& get_flights_by_airport_name(const std::string& airport_name, bool from) const; // from == true, to == false
    const std::list<Flight>& get_flights_by_callsign(const std::string& callsign) const;
    void rerun_script() const;
    const std::list<const std::string&> get_airports_names() const;
    const std::list<Flight> getAirplanes(const std::string& icao24) const;
private:
    std::list<Flight>&& getFlightsFromFiles(std::ifstream& inFile);
    bool load_flights_to_DB(const std::string& filePath, const std::string& postfix, const std::string& airportCode);
    std::list<Airport> Airports;
    bool loaded;
};

#endif