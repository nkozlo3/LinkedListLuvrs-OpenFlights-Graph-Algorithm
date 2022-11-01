/*
    airports.csv is formatted as: 
    "Airline ID", "Name of the airline", "Alias of the airline", "2-letter IATA code", "3 letter ICAO code", "Callsign", "Country", "Active or not"

    NULL values are represented with \N
*/

/* 
    routes.csv is formatted as follows: 
    "Airline IATA/ICAO", "Airline ID", "Source airport", "Source airport ID", "Destination airport IATA/ICAO", "Codeshare", "Stops", "Equipment"


    Airline	2-letter (IATA) or 3-letter (ICAO) code of the airline.
    Airline ID	Unique OpenFlights identifier for airline (see Airline).
    Source airport	3-letter (IATA) or 4-letter (ICAO) code of the source airport.
    Source airport ID	Unique OpenFlights identifier for source airport (see Airport)
    Destination airport	3-letter (IATA) or 4-letter (ICAO) code of the destination airport.
    Destination airport ID	Unique OpenFlights identifier for destination airport (see Airport)
    Codeshare	"Y" if this flight is a codeshare (that is, not operated by Airline, but another carrier), empty otherwise.
    Stops	Number of stops on this flight ("0" for direct)
    Equipment	3-letter codes for plane type(s) generally used on this flight, separated by spaces
*/