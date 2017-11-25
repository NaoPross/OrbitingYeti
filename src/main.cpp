#include "diagram/Structogram.h"
#include <iostream>
#include "ui/AsciiRenderer.h"

int main(int argc, char *argv[]) {
	samb::Structogram st("Demo");
	samb::AsciiRenderer renderer(st, 60);

	renderer.render();

	return 0;
}




