
#include "string/string.h"

#include <codecvt>
#include <boost/locale.hpp>
#include <boost/algorithm/string.hpp>
namespace sahara {

    string::string(const std::string &other) : string_(boost::locale::conv::to_utf<wchar_t>(other, "GB2312")) {}

    string::string(const std::wstring &other) : string_(other) {}

    string::string(const char *other) : string_(boost::locale::conv::to_utf<wchar_t>(other, "GB2312")) {}

    string::string(const wchar_t *other) : string_(other) {}

    string::string(const string &other) : string_(other.string_) {}

    string::string(string &&other) noexcept: string_(std::move(other.string_)) {}

    string &string::operator=(const string &other) {
        this->string_ = other.string_;
        return *this;
    }

    bool string::operator==(const string &other) const {
        return equals(other);
    }

    bool string::operator==(string &&other) const {
        return equals(other);
    }

    bool string::iequals(const string &other) const {
        return boost::algorithm::iequals(string_, other.string_);
    }

    string::string(std::wstring_view other) : string_(other) {}

    string::string(std::string_view other) : string_(boost::locale::conv::to_utf<wchar_t>(other.data(), "GB2312")) {}

    string &string::operator=(std::string other) {
        operator=(string(other));
        return *this;
    }

    std::vector<string> string::split(const string &delimeter) {
        std::vector<string> result;
        std::wstring wstr = string_;
        std::wstring wdelimeter = delimeter.string_;
        std::wstring::size_type pos1, pos2;
        pos2 = wstr.find(wdelimeter);
        pos1 = 0;
        while (std::wstring::npos != pos2) {
            result.emplace_back(wstr.substr(pos1, pos2 - pos1));
            pos1 = pos2 + wdelimeter.size();
            pos2 = wstr.find(wdelimeter, pos1);
        }
        if (pos1 != wstr.length())
            result.emplace_back(wstr.substr(pos1));
        return result;
    }

    string::operator std::wstring &() {
        return string_;
    }

    string::operator std::string () {
        return boost::locale::conv::utf_to_utf<char>(string_);
    }

    string::operator std::wstring_view() {
        return string_;
    }

    std::string string::to_std() const {
        return boost::locale::conv::utf_to_utf<char>(string_);
    }

    std::wstring &string::to_wstd() {
        return string_;
    }

    string operator+(const char *lhs, const string &rhs) {
        return boost::locale::conv::to_utf<wchar_t>(lhs, "GB2312") + rhs.string_;
    }

    bool string::start_with(const string &other) const {
        return boost::algorithm::starts_with(string_, other.string_);
    }

    bool string::istart_with(const string &other) const {
        return boost::algorithm::istarts_with(string_, other.string_);

    }

    bool string::equals(const string &other) const {
        return string_ == other;
    }


}