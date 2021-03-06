# fundoshi.hpp Example

    // Creating a fundoshi::string instance
    // referring a std::string instance
    
    std::string x("abcde");
    fundoshi::string fs1 = fundoshi::string(x);
    
    std::cout << fs1.length() << std::endl; // 5
    std::cout << fs1[0] << std::endl; // a
    std::cout << fs1[2] << std::endl; // c
    
	// Creating a fundoshi::string instance
	// referring a substring of a std::string instance
	
	fundoshi::string fs2 = fundoshi::string(&(x[1]), 3);
	// fs2 represents "bcd"!
	
	std::cout << fs2.length() << std::endl; // 3
	std::cout << fs2[0] << std::endl; // b
	std::cout << fs2[2] << std::endl; // d
	
	// Since the memory for fs1 and fs2 are shared with x,
	// changes on x affects fs1 and fs2.
	x[2] = 'f';
	std::cout << fs1[2] << std::endl; // f
	std::cout << fs2[1] << std::endl; // f

Methods and other APIs are almost the same as those in `std::basic_string` (`std::string`), although some methods are omitted.
