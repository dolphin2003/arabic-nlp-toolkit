
#include "anltk/char_maps.h"
#include <map>
namespace anltk
{
// clang-format off
const std::map<char_t, char_t> arabic_to_buckwalter_= 
{
	{ HAMZA            ,	U'\'' } ,
	{ ALEF_MADDA       ,	U'|' },
	{ ALEF_HAMZA_ABOVE ,	U'>' },
	{ WAW_HAMZA_ABOVE  ,	U'&' },
	{ ALEF_HAMZA_BELOW ,	U'<' },
	{ YEH_HAMZA_ABOVE  ,	U'}' },
	{ ALEF_NO_HAMZA    ,	U'A' },
	{ BEH              ,	U'b' },
	{ TEH_MARBOOTA     ,	U'p' },
	{ TEH              ,	U't' },
	{ THEH             ,	U'v' },
	{ JEEM             ,	U'j' },
	{ HAH              ,	U'H' },
	{ KHAH             ,	U'x' },
	{ DAL              ,	U'd' },
	{ THAL             ,	U'*' },
	{ REH              ,	U'r