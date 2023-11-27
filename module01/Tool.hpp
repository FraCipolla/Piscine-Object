#pragma once

class Tool {
	public:
		int nUses;

		Tool() { std::cout << "Tool abstract class constructor" << std::endl; };
		virtual ~Tool() = 0;
		virtual void use() = 0;
};
