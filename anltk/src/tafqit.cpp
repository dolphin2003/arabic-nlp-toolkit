

/*********************************************************************\
* Ported from https://github.com/MohsenAlyafei/tafqit/blob/master/tafqit.js

* @function      : tafqit(Number [,{options}])
* @purpose       : Converts Numbers to Arabic Words with Grammar Rules
* @version       : 1.60
* @author        : Mohsen Alyafei
* @date          : 04 August 2020
* @Licence       : MIT
* @param         : {Number} [Integer in Numeric or String form]
*                  Number may be in Arabic-Indic format (as a string)
* @param         : [{options}] 9 Options passed as object {name:value} as follows:
*
* {Feminine}     : "on": Generate string for a Feminine subject (أرقام بصيغة المؤنث).
*                        The default is the Masculine form.
* {Miah}         : "on": Use Mi'ah for Hundreds (مئة بدل مائة). Default is Ma'ah "مائة".
* {Comma}        : "on": Insert comma between triplet words.
* {SplitHund}    : "on": Split number from hundred words (فصل الرقم عن المئة).
                   i.e. ثلاث مائة. Default "No Split" i.e. (ثلاثمائة).
* {Billions}     : "on": Use Billions (بليون) instead of Miliard (مليار).
* {TextToFollow} : "on": Indicates that there will be text to follow the resulting text.
*                  This permits proper subject name to be added after the resulting text.
* {AG}           : "on": Text is produced in Accusative/Genitive (جر/نصب) case.
*                  The default is the Nominative cse (رفع).
*
* {Subjec}       : An optional array holding the Subject Name to be counted in 4 forms as follows:
*                  [0] = Deafult Name Singular      (e.g. "كتاب/تفاحة/دينار").
*                  [1] = Name for 2's (double)      (e.g. "كتابان/تفاحتان/ديناران").
*                  [2] = Name for plural            (e.g. "كتب/تفاحات/دنانير").
*                  [3] = Name Singular with Tanween (e.g. "كتابًا/تفاحةً/دينارًا").
*                  The subject name will be added to the resulting string in acordance
*                  with the number grammar rules.
* {Legal}        : "on" Uses the lagal form of output text.
*
* @returns       : {string} The wordified number string in Arabic.
**********************************************************************/
#include "anltk/anltk.hpp"
#include <array>
#include <iostream>
#include <string>
#include <vector>
namespace anltk
{
const std::vector<std::string> TableScales{
	"", "ألف", "مليون", "مليار", "ترليون", "كوادرليون", "كوينتليون", "سكستليون"
}; // Add here only
const std::vector<std::string> TableScalesP{ "", "آلاف", "ملايين",
	                                         "مليارات" }; // Do not change this table
const std::vector<std::string> TableMale{ "",    "واحد", "اثنان",  "ثلاثة", "أربعة", "خمسة",
	                                      "ستة", "سبعة", "ثمانية", "تسعة",  "عشرة" };
const std::vector<std::string> TableFemale{ "",   "واحدة", "اثنتان", "ثلاث", "أربع", "خمس",
	                                        "ست", "سبع",   "ثمان",   "تسع",  "عشر" };

std::string tafqit(long long Num, TafqitOptions opts)
{
	using namespace std::string_literals;
	using std::string;
	using std::vector;

	if (Num == 0)
		return "صفر"; // if 0 or "0" then "zero"
	// let Triplet, Scale, ScalePos, ScalePlural, TableUnits, Table11_19, NumberInWords = "",
	// IsLastEffTriplet = false,
	// Num_99;
	long long Triplet, ScalePos, Num_99;
	string NumberInWords = "";
	string Scale, ScalePlural;
	bool IsLastEffTriplet = false;
	bool ON               = true; // Flag to test if Option is ON

	bool IsAG                 = (opts.is_accusative == ON); // Option Accusative or Genitive case Grammar?
	string SpWa          = " و"; // AND word
	string TanweenLetter = "ًا"; // Tanween Fatih for Scale Names above 10
	string Ahad          = "أحد";
	string Ehda          = "إحدى"; // Masculine/Feminine 11
	// ---- Setup constants for the AG Option (Accusative/Genitive or Nominative case Grammar)
	string Taa = IsAG ? "تي" : "تا";
	string Taan = IsAG ? "تين" : "تان"; // Hundred 2's مئتا/مائتا مئتان/مائتان
	string Aa = IsAG ? "ي" : "ا";
	string Aan = IsAG ? "ين" : "ان"; // Scale 2's ا