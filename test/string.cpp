
#include <fstream>
#include <string/string.h>
#include <boost/test/unit_test.hpp>
#include <boost/asio.hpp>
BOOST_AUTO_TEST_SUITE(String)

  BOOST_AUTO_TEST_CASE(UrlTest){
    char test[128] = {0};
    boost::asio::streambuf buf;
    buf.prepare(1024000000);
    buf.prepare(1024000000);
    try{
        auto t = buf.sputn("12345123451234512345123451234512345123451234512345123451234512345123451234512345123451234512345123451234512345123451234512345123",128);
    }catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    buf.sgetn(test,128);
    buf.consume(128);
    buf.sputn("12345",5);
    std::cout << "Hello:"<< buf.size() << std::endl;
  sahara::string test_string = "Hello World 罗浩然";
  sahara::string test_string1 = sahara::string::url_encode("Hello World 罗浩然");
  sahara::string test_string2 = test_string.url_encode_copy();
  std::cout << test_string.to_std() << "\n" << std::endl;
  test_string.url_encode();
  std::cout << test_string.to_std() << "\n" << std::endl;

  std::cout << test_string1.to_std() << "\n" << std::endl;
  std::cout << test_string2.to_std() << "\n" << std::endl;

  }

  BOOST_AUTO_TEST_CASE(ConversionTest){

  }

    BOOST_AUTO_TEST_CASE(CompareTest){

    }
BOOST_AUTO_TEST_SUITE_END()