#include "pch.h"
#include "CppUnitTest.h"

#include "Item.h"
#include "FishBeta.h"
#include "Aquarium.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Testing
{
	TEST_CLASS(CFishBetaTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCFishBetaConstruct)
		{
			// Construct a beta fish to test
			CAquarium aquarium;
			CFishBeta fishBeta(&aquarium);
		}

	};
}