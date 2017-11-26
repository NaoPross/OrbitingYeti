#include "diagram/Structogram.hpp"
#include "diagram/Statement.hpp"
#include "ui/AsciiRenderer.hpp"

#include <iostream>
#include <memory>

using namespace samb;

int main(int argc, char *argv[]) {
	Structogram st("Demo");
	AsciiRenderer renderer(st, 60);

	Structogram::iterator it = st.begin();

	auto first = Statement::makeStatement(Statement::Type::PROCESS);
	first->text = "Hello World";

	auto second = Statement::makeStatement(Statement::Type::PROCESS);
	second->text = "Hello World Again!";

	st.insert_after(it, first);
	++it;

	st.insert_after(it, second);

	renderer.render();

	return 0;
}




