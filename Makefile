# =============================================================================
# Time & Space Complexity Showcase – Build System
# Modern C++23 – One-command compilation and execution
#
# Targets:
#   make                → build all examples
#   make run_hash       → build & run O(1) hash lookup
#   make run_binsearch  → O(log n) binary search
#   make run_linear     → O(n) linear sum
#   make run_merge      → O(n log n) merge sort
#   make run_bubble     → O(n²) bubble sort
#   make run_fib        → O(2ⁿ) recursive Fibonacci
#   make run_perms      → O(n!) permutations
#   make clean          → remove all compiled binaries
#
# Why this exists:
#   One-line demo during interviews or live coding sessions.
#   No external dependencies — pure STL + standard compiler.
# =============================================================================

CXX      := g++                     # Compiler
CXXFLAGS := -std=c++23 -O2 -march=native -pipe   # Fast, modern, portable
SOURCES  := $(wildcard */*.cpp)     # All example source files
TARGETS  := $(SOURCES:%.cpp=%)      # Strip .cpp → executable name

# Default: build everything
all: $(TARGETS)
	@echo "All examples built successfully."

# Generic rule: compile any .cpp → executable
%: %.cpp
	@$(CXX) $(CXXFLAGS) $< -o $@

# Convenience runners – one command to build + execute
run_hash:   O1_Constant/hash_lookup
	@echo "=== O(1) – Constant time ==="; ./$<

run_binsearch: Ologn_Logarithmic/binary_search
	@echo "=== O(log n) – Logarithmic ==="; ./$<

run_linear: On_Linear/linear_scan_sum
	@echo "=== O(n) – Linear ==="; ./$<

run_merge: OnlogN_Linearithmic/merge_sort
	@echo "=== O(n log n) – Linearithmic ==="; ./$<

run_bubble: On2_Quadratic/bubble_sort
	@echo "=== O(n²) – Quadratic ==="; ./$<

run_fib: O2n_Exponential/fibonacci_recursive
	@echo "=== O(2ⁿ) – Exponential ==="; ./$<

run_perms: OnFact_Factorial/permutations
	@echo "=== O(n!) – Factorial ==="; ./$<

# Clean up compiled binaries
.PHONY: clean
clean:
	@rm -f $(TARGETS)
	@echo "Cleaned all executables."

# Help target – shows available commands
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  make              → build all examples"
	@echo "  make run_<name>   → build and run specific example"
	@echo "  make clean        → remove binaries"
	@echo "  make help         → show this message"
