#include "stack.h"
#include <iostream>

int main() {
	stack<int> s{};
	for (int i = 0;i < 1001;i += 10) {
		s.push(i);
	}

	while (!s.empty()) {
		auto opt = s.pop();
		printf("%d - %d\n", opt.has_value(), *opt);
	}

	return 0;
}
