#include <string>

#include "database.h"

using namespace dictionary;

void Database::connect() {
    std::string s =     "host=" + m_host + " " 
                        "dbname=" + m_dbname + " "
                        "user=" + m_user + " "
                        "password=" + m_pword;
    soci::session sql( soci::postgresql, s );
}

void Database::set_host( const std::string& param ) {
    m_host = param;
}
void Database::set_dbname( const std::string& param ) {
    m_dbname = param;
}
void Database::set_user( const std::string& param ) {
    m_user = param;
}
void Database::set_pword( const std::string& param ) {
    m_pword = param;
}

const std::string& Database::get_host() const {
    return m_host;
}
const std::string& Database::get_dbname() const {
    return m_dbname;
}
const std::string& Database::get_user() const {
    return m_user;
}
const std::string& Database::get_pword() const {
    return m_pword;
}