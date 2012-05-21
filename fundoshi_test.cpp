#include <fundoshi.hpp>
#include <cstring>

#define BOOST_TEST_MODULE FundoshiTest
#include <boost/test/included/unit_test.hpp>
using namespace boost::unit_test_framework;

BOOST_AUTO_TEST_CASE(creating_instances)
{
	fundoshi::string str1, str2, str3, str4;
	
	str1 = fundoshi::string("foo");
	str2 = fundoshi::string("foobar", 3);
	str3 = fundoshi::string("foobar");
	str4 = fundoshi::string(str3);
	
	BOOST_CHECK_EQUAL(str1.length(), 3);
	BOOST_CHECK_EQUAL(std::strncmp("foo", str1.c_str(), 3), 0);

	BOOST_CHECK_EQUAL(str2.length(), 3);
	BOOST_CHECK_EQUAL(std::strncmp("foo", str2.c_str(), 3), 0);

	BOOST_CHECK_EQUAL(str3.length(), 6);
	BOOST_CHECK_EQUAL(std::strncmp("foobar", str3.c_str(), 6), 0);

	BOOST_CHECK_EQUAL(str4.length(), 6);
	BOOST_CHECK_EQUAL(std::strncmp("foobar", str4.c_str(), 6), 0);
}

BOOST_AUTO_TEST_CASE(creating_substrings)
{
	fundoshi::string str1, str2, str3;
	
	str1 = fundoshi::string(fundoshi::string("foobar"), 2, 3);
	str2 = fundoshi::string(std::string("foobar"), 2, 3);
	str3 = fundoshi::string("foobar", 2, 3);
	
	BOOST_CHECK_EQUAL(str1.length(), 3);
	BOOST_CHECK_EQUAL(std::strncmp("oba", str1.c_str(), 3), 0);
	
	BOOST_CHECK_EQUAL(str2.length(), 3);
	BOOST_CHECK_EQUAL(std::strncmp("oba", str2.c_str(), 3), 0);
	
	BOOST_CHECK_EQUAL(str3.length(), 3);
	BOOST_CHECK_EQUAL(std::strncmp("oba", str3.c_str(), 3), 0);
}

BOOST_AUTO_TEST_CASE(comparing_instances)
{
	fundoshi::string str1, str2, str3, str4;
	
	str1 = fundoshi::string("foo");
	str2 = fundoshi::string("foobar", 3);
	str3 = fundoshi::string("foobar");
	
	// BOOST_CHECK_EQUAL(str1, str2); // cannot be compiled...
	BOOST_CHECK(str1 == str2);
	BOOST_CHECK(str1 != str3);
	BOOST_CHECK(str2 != str3);
	
	BOOST_CHECK(str1 < str3);
	
	str4 = fundoshi::string("bar");
	
	BOOST_CHECK(str1 >  str4);
	BOOST_CHECK(str1 >= str4);
	BOOST_CHECK(str4 <  str1);
	BOOST_CHECK(str4 <= str1);
}

