#include "utf8.h"
#include <anltk/anltk.hpp>
#include <anltk/anltk_algorithm.h>
namespace anltk
{

vector_t<string_t> tokenize_words(string_view_t input)
{
	vector_t<string_t> result;
	if (input.empty())
	{
		return result;
	}

	auto start = input.begin();
	auto end   = input.end();

	char_t next = utf8::next(start, end);
	bool done   = false;

	while (start != end)
	{

		if (isspace(static_cast<char>(next)))
		{
			next = utf8::next(start, end);
			continue;
		}

		if (is_arabic_alpha(next) || is_tashkeel(next) || next == TATWEEL)
		{
			result.push_back(parse_sequence(
			    next, start, end, done,
			    [](char_t c) { return is_arabic_alpha(c) || is_tashkeel(c) || c == TATWEEL; }));
		}
		else
		{
			result.push_back(parse_sequence(
			    next, start, end, done,
			    [](char_t c) { return !is_arabic_alpha(c) && !isspace(static_cast<char