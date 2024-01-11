
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
	{ REH              ,	U'r' },
	{ ZAIN             ,	U'z' },
	{ SEEN             ,	U's' },
	{ SHEEN            ,	U'$' },
	{ SAD              ,	U'S' },
	{ DAD              ,	U'D' },
	{ TAH              ,	U'T' },
	{ ZAH              ,	U'Z' },
	{ AIN              ,	U'E' },
	{ GHAIN            ,	U'g' },
	{ TATWEEL          ,	U'_' },
	{ FEH              ,	U'f' },
	{ QAF              ,	U'q' },
	{ KAF              ,	U'k' },
	{ LAM              ,	U'l' },
	{ MEEM             ,	U'm' },
	{ NOON             ,	U'n' },
	{ HEH              ,	U'h' },
	{ WAW              ,	U'w' },
	{ ALEF_MAQSURA     ,	U'Y' },
	{ YEH 			   ,	U'y' },
	{ FATHATAN    ,	U'F' },
	{ DAMMATAN    ,	U'N' },
	{ KASRATAN    ,	U'K' },
	{ FATHA            ,	U'a' },
	{ DAMMA            ,	U'u' },
	{ KASRA            ,	U'i' },
	{ SHADDA           ,	U'~' },
	{ SUKUN            ,	U'o' },
	{ SMALL_ALEF 	   ,    U'`' },
	{ ALEF_WASLA	   ,    U'{' },
	{ PEH			   , 	U'P' },
	{ TCHEH   		   , 	U'J' },
	{ VEH			   , 	U'V' },
	{ GAF			   , 	U'G' },
};

const std::map<char_t, char_t> buckwalter_to_arabic_ =
{
	{ U'\'' , HAMZA },
	{ U'|' , ALEF_MADDA },
	{ U'>' , ALEF_HAMZA_ABOVE },
	{ U'&' , WAW_HAMZA_ABOVE },
	{ U'<' , ALEF_HAMZA_BELOW },
	{ U'}' , YEH_HAMZA_ABOVE },
	{ U'A' , ALEF_NO_HAMZA },
	{ U'b' , BEH },
	{ U'p' , TEH_MARBOOTA },
	{ U't' , TEH },
	{ U'v' , THEH },
	{ U'j' , JEEM },
	{ U'H' , HAH },
	{ U'x' , KHAH },
	{ U'd' , DAL },
	{ U'*' , THAL },
	{ U'r' , REH },
	{ U'z' , ZAIN },
	{ U's' , SEEN },
	{ U'$' , SHEEN },
	{ U'S' , SAD },
	{ U'D' , DAD },
	{ U'T' , TAH },
	{ U'Z' , ZAH },
	{ U'E' , AIN },
	{ U'g' , GHAIN },
	{ U'_' , TATWEEL },
	{ U'f' , FEH },
	{ U'q' , QAF },
	{ U'k' , KAF },
	{ U'l' , LAM },
	{ U'm' , MEEM },
	{ U'n' , NOON },
	{ U'h' , HEH },
	{ U'w' , WAW },
	{ U'Y' , ALEF_MAQSURA },
	{ U'y' , YEH },
	{ U'F' , FATHATAN },
	{ U'N' , DAMMATAN },
	{ U'K' , KASRATAN },
	{ U'a' , FATHA },
	{ U'u' , DAMMA },
	{ U'i' , KASRA },
	{ U'~' , SHADDA },
	{ U'o' , SUKUN },
	{ U'`' , SMALL_ALEF },
	{ U'{' , ALEF_WASLA },
	{ U'P' , PEH },
	{ U'J' , TCHEH },
	{ U'V' , VEH },
	{ U'G' , GAF }
 };





const std::map<char_t, char_t> arabic_to_safe_buckwalter_ =
{
	{ HAMZA            ,	U'C' } ,
	{ ALEF_MADDA       ,	U'M' },
	{ ALEF_HAMZA_ABOVE ,	U'O' },
	{ WAW_HAMZA_ABOVE  ,	U'W' },
	{ ALEF_HAMZA_BELOW ,	U'I' },
	{ YEH_HAMZA_ABOVE  ,	U'Q' },
	{ ALEF_NO_HAMZA    ,	U'A' },
	{ BEH              ,	U'b' },
	{ TEH_MARBOOTA     ,	U'p' },
	{ TEH              ,	U't' },
	{ THEH             ,	U'v' },
	{ JEEM             ,	U'j' },
	{ HAH              ,	U'H' },
	{ KHAH             ,	U'x' },
	{ DAL              ,	U'd' },
	{ THAL             ,	U'V' },
	{ REH              ,	U'r' },
	{ ZAIN             ,	U'z' },
	{ SEEN             ,	U's' },
	{ SHEEN            ,	U'c' },
	{ SAD              ,	U'S' },
	{ DAD              ,	U'D' },
	{ TAH              ,	U'T' },
	{ ZAH              ,	U'Z' },
	{ AIN              ,	U'E' },
	{ GHAIN            ,	U'g' },
	{ TATWEEL          ,	U'_' },
	{ FEH              ,	U'f' },
	{ QAF              ,	U'q' },
	{ KAF              ,	U'k' },
	{ LAM              ,	U'l' },
	{ MEEM             ,	U'm' },
	{ NOON             ,	U'n' },
	{ HEH              ,	U'h' },
	{ WAW              ,	U'w' },
	{ ALEF_MAQSURA     ,	U'Y' },
	{ YEH 			   ,	U'y' },
	{ FATHATAN         ,	U'F' },
	{ DAMMATAN         ,	U'N' },
	{ KASRATAN         ,	U'K' },
	{ FATHA            ,	U'a' },
	{ DAMMA            ,	U'u' },
	{ KASRA            ,	U'i' },
	{ SHADDA           ,	U'~' },
	{ SUKUN            ,	U'o' },
	{ SMALL_ALEF 	   ,    U'e' },
	{ ALEF_WASLA	   ,    U'L' },
	{ PEH			   , 	U'P' },
	{ TCHEH   		   , 	U'J' },
	{ VEH			   , 	U'B' },
	{ GAF			   , 	U'G' },
};


const std::map<char_t, char_t> safe_buckwalter_to_arabic_ = 
{
	{ U'C' , HAMZA} ,
	{ U'M', ALEF_MADDA },
	{ U'O', ALEF_HAMZA_ABOVE },
	{ U'W', WAW_HAMZA_ABOVE },
	{ U'I', ALEF_HAMZA_BELOW },
	{ U'Q', YEH_HAMZA_ABOVE },
	{ U'A', ALEF_NO_HAMZA },
	{ U'b', BEH },
	{ U'p', TEH_MARBOOTA },
	{ U't', TEH },
	{ U'v', THEH },
	{ U'j', JEEM },
	{ U'H', HAH },
	{ U'x', KHAH },
	{ U'd', DAL },
	{ U'V', THAL },
	{ U'r', REH },
	{ U'z', ZAIN },
	{ U's', SEEN },
	{ U'c', SHEEN },
	{ U'S', SAD },
	{ U'D', DAD },
	{ U'T', TAH },
	{ U'Z', ZAH },
	{ U'E', AIN },
	{ U'g', GHAIN },
	{ U'_', TATWEEL },
	{ U'f', FEH },
	{ U'q', QAF },
	{ U'k', KAF },
	{ U'l', LAM },
	{ U'm', MEEM },
	{ U'n', NOON },
	{ U'h', HEH },
	{ U'w', WAW },
	{ U'Y', ALEF_MAQSURA },
	{ U'y', YEH },
	{ U'F', FATHATAN },
	{ U'N', DAMMATAN },
	{ U'K', KASRATAN },
	{ U'a', FATHA },
	{ U'u', DAMMA },
	{ U'i', KASRA },
	{ U'~', SHADDA },
	{ U'o', SUKUN },
	{ U'e', SMALL_ALEF },
	{ U'L', ALEF_WASLA },
	{ U'P', PEH },
	{ U'J', TCHEH },
	{ U'B', VEH },
	{ U'G', GAF },
};


const std::map<char_t, std::string> chars_names_ =
{ 
	{ U'\u0621', "ARABIC LETTER HAMZA" },
	{ U'\u0622', "ARABIC LETTER ALEF WITH MADDA ABOVE" },
	{ U'\u0623', "ARABIC LETTER ALEF WITH HAMZA ABOVE" },
	{ U'\u0624', "ARABIC LETTER WAW WITH HAMZA ABOVE" },
	{ U'\u0625', "ARABIC LETTER ALEF WITH HAMZA BELOW" },
	{ U'\u0626', "ARABIC LETTER YEH WITH HAMZA ABOVE" },
	{ U'\u0627', "ARABIC LETTER ALEF" },
	{ U'\u0628', "ARABIC LETTER BEH" },
	{ U'\u0629', "ARABIC LETTER TEH MARBUTA" },
	{ U'\u062a', "ARABIC LETTER TEH" },
	{ U'\u062b', "ARABIC LETTER THEH" },
	{ U'\u062c', "ARABIC LETTER JEEM" },
	{ U'\u062d', "ARABIC LETTER HAH" },
	{ U'\u062e', "ARABIC LETTER KHAH" },
	{ U'\u062f', "ARABIC LETTER DAL" },
	{ U'\u0630', "ARABIC LETTER THAL" },
	{ U'\u0631', "ARABIC