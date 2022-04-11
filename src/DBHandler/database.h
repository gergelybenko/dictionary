#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include "soci/soci.h"
#include "soci/postgresql/soci-postgresql.h"

namespace dictionary {
    class Database {
        private:
        Database() {}
        ~Database() {}

        std::string m_host;
        std::string m_dbname;
        std::string m_user;
        std::string m_pword;

        public:
        static Database &instance() {
            static Database instance;
            return instance;
        }

        Database( const Database& )             = delete;
        Database& operator=( const Database& )  = delete;

        void connect();

        void set_host( const std::string& h );
        void set_dbname( const std::string& d );
        void set_user( const std::string& u );
        void set_pword( const std::string& p );

        const std::string& get_host() const;
        const std::string& get_dbname() const;
        const std::string& get_user() const;
        const std::string& get_pword() const;
    };
}

#endif // __DICTIONARY_H__