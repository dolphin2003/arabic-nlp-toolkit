#include "anltk/anltk.hpp"

#include "utf8.h"
#include <algorithm>

namespace anltk
{
bool is_digit(char_t c)
{
	// TODO(Abdullah) This causes issues in windows, needs more testing
	// return c  >= U'0' && c <= U'9';
	switch (c)
	{
	case U'0':
	case U'1':
	case U'2':
	case U'3':
	case U'4':
	case U'5':
	case U'6':
	case U'7':
	case U'8':
	case U'9':
		return true;
		/* code */
		break;

	default:
		return false;
		break;
	}
}

bool is_indic_digit(char_t c)
{
	return c >= SEFR && c <= TES3A;
}

bool is_tashkeel(char_t c)
{
	return c >= FATHATAN && c <= SUKUN;
}

bool is_arabic_alpha(char_t c)
{
	return c != TATWEEL && (c >= HAMZA && c <= YEH);
}

bool is_small(char_t c)
{
	return std::find(small_list_.begin(), small_list_.end(), c) != small_list_.end();
}

bool is_shamsi(char_t c)
{
	return std::find(shmasi_.begin(), shmasi_.end(), c) != shmasi_.end();
}

bool is_qamari(char_t c)
{
	return std::find(qamari_.begin(), qamari_.end(), c) != qamari_.end();
}

bool is_valid_kalima(string_view_t input)
{

	std::u32string text = to_32string(input);

	if (text.empty())
	{
		return false;
	}

	if (!std::all_of(text.begin(), text.end(),
	           