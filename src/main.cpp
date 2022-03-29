#include <iostream>
#include <exception>

#include "soci/soci.h"
#include "soci/postgresql/soci-postgresql.h"

#include <boost/log/trivial.hpp>

int main( int argc, char** argv ) {
    try {
        soci::session sql( soci::postgresql, "service=mydb user=psql password=psql" );
    } catch( const std::exception &e ) {
        BOOST_LOG_TRIVIAL( error ) << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}