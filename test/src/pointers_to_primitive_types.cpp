#include <iostream>
#include <sstream>

#include <nvx/iostream.hpp>
#include <nvx/type.hpp>

#include "assert.hpp"
#include "random_values.hpp"

#include "../../serialization.hpp"


using namespace nvx;
using namespace std;





bool pointers_to_primitive_types()
{
	bool ret = true;

	for (int i = 0; i < 100; ++i)
	{
		stringstream ss;

		bool    *boolval,    *boolvalr;
		short   *shortval,   *shortvalr;
		int     *intval,     *intvalr;
		long    *longval,    *longvalr;
		llong   *llongval,   *llongvalr;
		char    *charval,    *charvalr;
		uint    *uintval,    *uintvalr;
		ulong   *ulongval,   *ulongvalr;
		ullong  *ullongval,  *ullongvalr;
		float   *floatval,   *floatvalr;
		double  *doubleval,  *doublevalr;
		ldouble *ldoubleval, *ldoublevalr;

		boolval    = new bool(uidis_t<int>( 0, 1 )(dre));
		shortval   = new short(uidis_t<short>(   short_min,  short_max  )(dre));
		intval     = new int(uidis_t<int>(       int_min,    int_max    )(dre));
		longval    = new long(uidis_t<long>(     long_min,   long_max   )(dre));
		llongval   = new llong(uidis_t<llong>(   llong_min,  llong_max  )(dre));
		charval    = new char(uidis_t<char>(     char_min,   char_max   )(dre));
		uintval    = new uint(uidis_t<uint>(     uint_min,   uint_max   )(dre));
		ulongval   = new ulong(uidis_t<ulong>(   ulong_min,  ulong_max  )(dre));
		ullongval  = new ullong(uidis_t<ullong>( ullong_min, ullong_max )(dre));

		floatval   = new float(urdis_t<float>()(dre));
		doubleval  = new double(urdis_t<double>()(dre));
		ldoubleval = new ldouble(urdis_t<ldouble>()(dre));

		archive<stringstream>(&ss) <<
			&boolval   <<
			&shortval  <<
			&intval    <<
			&longval   <<
			&llongval  <<
			&charval   <<
			&uintval   <<
			&ulongval  <<
			&ullongval <<
			&floatval  <<
			&doubleval <<
			&ldoubleval;

		archive<stringstream>(&ss) >>
			&boolvalr   >>
			&shortvalr  >>
			&intvalr    >>
			&longvalr   >>
			&llongvalr  >>
			&charvalr   >>
			&uintvalr   >>
			&ulongvalr  >>
			&ullongvalr >>
			&floatvalr  >>
			&doublevalr >>
			&ldoublevalr;

		try
		{
			is_equal(*boolval,    *boolvalr,    "Equal fail: boolval != boolvalr");
			is_equal(*shortval,   *shortvalr,   "Equal fail: shortval != shortvalr");
			is_equal(*intval,     *intvalr,     "Equal fail: intval != intvalr");
			is_equal(*longval,    *longvalr,    "Equal fail: longval != longvalr");
			is_equal(*llongval,   *llongvalr,   "Equal fail: llongval != llongvalr");
			is_equal(*charval,    *charvalr,    "Equal fail: charval != charvalr");
			is_equal(*uintval,    *uintvalr,    "Equal fail: uintval != uintvalr");
			is_equal(*ulongval,   *ulongvalr,   "Equal fail: ulongval != ulongvalr");
			is_equal(*ullongval,  *ullongvalr,  "Equal fail: ullongval != ullongvalr");
			is_equal(*floatval,   *floatvalr,   "Equal fail: floatval != floatvalr");
			is_equal(*doubleval,  *doublevalr,  "Equal fail: doubleval != doublevalr");
			is_equal(*ldoubleval, *ldoublevalr, "Equal fail: ldoubleval != ldoublevalr");
		}
		catch (char const *err)
		{
			fprintf(stderr, "%s\n", err);
			ret = false;
		}

		delete boolval;
		delete shortval;
		delete intval;
		delete longval;
		delete llongval;
		delete charval;
		delete uintval;
		delete ulongval;
		delete ullongval;
		delete floatval;
		delete doubleval;
		delete ldoubleval;

		delete boolvalr;
		delete shortvalr;
		delete intvalr;
		delete longvalr;
		delete llongvalr;
		delete charvalr;
		delete uintvalr;
		delete ulongvalr;
		delete ullongvalr;
		delete floatvalr;
		delete doublevalr;
		delete ldoublevalr;

		if (!ret)
			return false;
	}

	return true;
}





// END
