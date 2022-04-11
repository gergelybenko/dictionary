// Standard libraries
#include <iostream>
#include <exception>

// Always use boost!
#include <boost/log/trivial.hpp>

// My stuff
#include "DBHandler/database.h"

int main( int argc, char** argv ) {
    dictionary::Database::instance().set_host( "postgres" );
    dictionary::Database::instance().set_dbname( "dict_db" );
    dictionary::Database::instance().set_user( "postgres" );
    dictionary::Database::instance().set_pword( "asd123" );

    try {
        dictionary::Database::instance().connect();
        BOOST_LOG_TRIVIAL( trace ) << "Successfully joined to database";
    } catch ( const std::exception& e ) {
        BOOST_LOG_TRIVIAL( error ) << "Error: " << e.what();
        return 1;
    }

    return 0;
}