#ifndef CHAR_MAPS_H
#define CHAR_MAPS_H

#include "anltk/anltk_typedefs.h"
#include <array>
#include <map>
namespace anltk
{
// clang-format off
// alphapet
constexpr char_t HAMZA            = U'\u0621'; // ء	 \u0621
constexpr char_t ALEF_MADDA       = U'\u0622'; // آ	 \u0622
constexpr char_t ALEF_HAMZA_ABOVE = U'\u0623'; // أ	 \u0623
constexpr char_t WAW_HAMZA_ABOVE  = U'\u0624'; // ؤ	 \u0624
constexpr char_t ALEF_HAMZA_BELOW = U'\u0625'; // إ	 \u0625
constexpr char_t YEH_HAMZA_ABOVE  = U'\u0626'; // ئ	 \u0626
constexpr char_t ALEF_NO_HAMZA    = U'\u0627'; // ا	 \u0627
constexpr char_t BEH              = U'\u0628'; // ب	 \u0628
constexpr char_t TEH_MARBOOTA     = U'\u0629'; // ة	 \u0629
constexpr char_t TEH              = U'\u062A'; // ت	 \u062A
constexpr char_t THEH             = U'\u062B'; // ث	 \u062B
constexpr char_t JEEM             = U'\u062C'; // ج	 \u062C
constexpr char_t HAH              = U'\u062D'; // ح	 \u062D
constexpr char_t KHAH             = U'\u062E'; // خ	 \u062E
constexpr char_t DAL              = U'\u062F'; // د	 \u062F
constexpr char_t THAL             = U'\u0630'; // ذ	 \u0630
constexpr char_t REH              = U'\u0631'; // ر	 \u0631
constexpr char_t ZAIN             = U'\u0632'; // ز	 \u0632
constexpr char_t SEEN             = U'\u0633'; // س	 \u0633
constexpr char_t SHEEN            = U'\u0634'; // ش	 \u0634
constexpr char_t SAD              = U'\u0635'; // ص	 \u0635
constexpr char_t DAD              = U'\u0636'; // ض	 \u0636
constexpr char_t TAH              = U'\u0637'; // ط	 \u0637
constexpr char_t ZAH              = U'\u0638'; // ظ	 \u0638
constexpr char_t AIN              = U'\u0639'; // ع	 \u0639
constexpr char_t GHAIN            = U'\u063A'; // غ	 \u063A
constexpr char_t FEH              = U'\u0641'; // ف	 \u0641
constexpr char_t QAF              = U'\u0642'; // ق	 \u0642
constexpr char_t KAF              = U'\u0643'; // ك	 \u0643
constexpr char_t LAM              = U'\u0644'; // ل	 \u0644
constexpr char_t MEEM             = U'\u0645'; // م	 \u0645
constexpr char_t NOON             = U'\u0646'; // ن	 \u0646
constexpr char_t HEH              = U'\u0647'; // ه	 \u0647
constexpr char_t WAW              = U'\u0648'; // و	 \u0648
constexpr char_t ALEF_MAQSURA     = U'\u0649'; // ى	 \u0649
constexpr char_t YEH              = U'\u064A'; // ي	 \u064A


// extras
// not an alpha
constexpr char_t TATWEEL    = U'\u0640'; // ـ \u0640
constexpr char_t ALEF_WASLA = U'\u0671'; // ٱ  \u0671
constexpr char_t PEH        = U'\u067E'; // پ  \u067E
constexpr char_t TCHEH      = U'\u0686'; // چ  \u0686
constexpr char_t VEH        = U'\u06A4'; // ڤ  \u06A4
constexpr char_t GAF        = U'\u06AF'; // گ  \u06AF

// \u064B	ً
// \u064C	ٌ
// \u064D	ٍ
// \u064E	َ
// \u064F	ُ
// \u0650	ِ
// \u0651	ّ
// \u0652	ْ
// \u0670	ٰ

// harakat
constexpr char_t FATHATAN      = U'\u064b'; // 	ً  \u064B
constexpr char_t DAMMATAN      = U'\u064c'; // 	ٌ  \u064C
constexpr char_t KASRATAN      = U'\u064d'; // 	ٍ  \u064D
constexpr char_t FATHA         = U'\u064e'; // 	َ  \u064E
constexpr char_t DAMMA         = U'\u064f'; // 	ُ  \u064F
constexpr char_t KASRA         = U'\u0650'; // 	ِ  \u0650
constexpr char_t SHADDA        = U'\u0651'; // 	ّ  \u0651
constexpr char_t SUKUN         = U'\u0652'; // 	ْ  \u0652

// symbols
constexpr char_t FASLA          = U'\u060C';
constexpr char_t QUESTION_MARK  = U'\u061F';
constexpr char_t FASLA_MANKOOTA = U'\u060B';
constexpr char_t NOKTATAN       = U'\u003A';
constexpr char_t NESBA          = U'\u0025';
constexpr char_t TA3AJJOB       = U'\u0021';
constexpr char_t KAWS_MAFTOOH   = U'\u0028';
constexpr char_t KAWS_MAKFOOL   = U'\u0029';
constexpr char