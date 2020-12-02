#pragma once
#include "memedit.hpp"

namespace routine_mgr
{
	class routine
	{
	private:
		size_t args_count;
	public:
		routine();
		routine(uintptr_t, size_t);
		~routine();

		uintptr_t old_function;
		uintptr_t new_function;

		uintptr_t create();
	};

	// because cant define `cdecl`, or `_cdecl`...
	enum conv : uint8_t
	{
		___cdecl,
		___stdcall,
		___fastcall,
		___thiscall
	};

	extern conv get_conv(uintptr_t func, size_t n_expected_args);
	extern uintptr_t create_routine(uintptr_t func, size_t n_args);

	extern std::vector<routine*>routines;
	extern void flush(); // clean up any/all resources
}
