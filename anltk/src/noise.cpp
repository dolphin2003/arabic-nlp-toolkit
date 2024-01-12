#include <anltk/anltk.hpp>
#include <iostream>
#include <random>
#include <utf8.h>

namespace anltk
{

NoiseGenerator::NoiseGenerator()
{
	auto seed = rd();
	gen.seed(seed);
}

bool _has_adjacent_ar_chars(const std::u32string& inp)
{
	bool has_adjacent_ar_chars = false;
	for (size_t i = 1; i < inp.size(); ++i)
	{
		if (is_arabic_alpha(inp[i]) && is_arabic_alpha(inp[i - 1]))
		{
			has_adjacent_ar_chars = true;
			break;
		}
	}
	return has_adjacent_ar_chars;
}

std::vector<size_t> _get_indices_if(const std::u32string& inp, std::function<bool(char32_t)>&& f)
{
	std::vector<size_t> indices;

	for (size_t i = 0; i < inp.size(); i++)
	{
		if (f(inp[i]))
		{
			indices.push_back(i);
		}
	}
	return indices;
}
std::string NoiseGenerator::swap_adjacent_chars(anltk::string_view_t input, size_t n)
{
	if (n == 0)
	{
		return std::string(input.beg