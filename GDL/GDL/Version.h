#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "22";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2010";
	static const char UBUNTU_VERSION_STYLE[] = "10.04";
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";
	
	//Standard Version Type
	static const long MAJOR = 1;
	static const long MINOR = 3;
	static const long BUILD = 9211;
	static const long REVISION = 46394;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 19440;
	#define RC_FILEVERSION 1,3,9211,46394
	#define RC_FILEVERSION_STRING "1, 3, 9211, 46394\0"
	static const char FULLVERSION_STRING[] = "1.3.9211.46394";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 0;
	

}
#endif //VERSION_H
