#ifndef BCRYPT_H
#define BCRYPT_H

#include <string>
#include <cstdint>

namespace sahara::hash {
    struct bcrypt{
        static std::string generateHash(const char* password, std::size_t length, std::uint8_t rounds = 10 );
        static std::string generateHash(const std::string & password , unsigned rounds = 10 );
        static std::string generateHash(const std::string_view& password, unsigned rounds = 10);
        static bool validatePassword(const char* password, std::size_t password_length, const char* hash, std::size_t hash_length);
        static bool validatePassword(const std::string & password, const std::string & hash);
        static bool validatePassword(const std::string_view & password, const std::string_view & hash);
    };
}

#endif // BCRYPT_H
