#include <argparse/argparse.hpp>

#include <anltk/anltk.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>

#include <stack>
#include <taskflow/taskflow.hpp>

namespace fs = std::filesystem;

struct Options
{
	int min_words_per_line         = 5;
	int max_words_per_line         = 10;
	int n_threads                  = std::round(std::thread::hardware_concurrency() * 0.7);
	std::string output_directory   = "out";
	std::string output_file_prefix = "batch_";
	std::string output_file_suffix = ".txt";

	std::vector<std::string> files;

	friend std::ostream& operator<<(std::ostream& os, const Options& opts)
	{
		os << "Options: \n";
		os << "\tmin_words_per_line = " << opts.min_words_per_line << '\n';
		os << "\tmax_words_per_line = " << opts.max_words_per_line << '\n';
		os << "\tn_threads = " << opts.n_threads << '\n';
		os << "\toutput_directory = " << opts.output_direc