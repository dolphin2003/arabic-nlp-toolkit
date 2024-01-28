
#include "anltk/anltk.hpp"
#include <algorithm>
#include <iostream>

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto timeFuncInvocation = [](auto&& func, auto&&... params)
{
	// get time before function invocation
	const auto& start = std::chrono::high_resolution_clock::now();
	// function invocation using perfect forwarding
	std::f