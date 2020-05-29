#include "Engine.h"

Engine::Engine(const Vector<Booked*> &vec_b,
	const Vector<Holiday*> &vec_h,
	const char first_sym)
	:booked(vec_b), holiday(vec_h)
{
	file[0] = first_sym;
}

void Engine::open()
{

}
void Engine::close()
{

}
void Engine::save()
{

}
void Engine::saveas()
{

}
void Engine::help()
{

}
void Engine::book()
{

}
void Engine::unbook()
{

}
void Engine::agenda()
{

}
void Engine::change()
{

}
void Engine::find()
{

}
void Engine::f_holiday()
{

}
void Engine::busydays()
{

}
void Engine::findslot()
{

}
void Engine::findslotwith()
{

}
void Engine::unknown()
{
	std::cin.ignore(IGNORE_LENGTH, '\n');
	std::cout << "Unknown command!\n";
}