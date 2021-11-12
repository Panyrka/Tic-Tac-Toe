#include "figure.h"

figure_enum figure::get() const
{
	return figure_;
}

void figure::set(const figure_enum& figure)
{
	figure_ = figure;
}

bool operator==(const figure& left, const figure& right)
{
	if (left.get() == right.get())
	{
		return true;
	}
	return false;
}

int figure::get_int() const
{
	switch (figure_)
	{
	case figure_enum::cross:
		return 0;
	case figure_enum::nought:
		return 1;
	case figure_enum::empty:
		return 2;
	}
	return 2;
}

char figure::get_char() const
{
	switch (figure_)
	{
	case figure_enum::cross:
		return 'X';
	case figure_enum::nought:
		return '0';
	case figure_enum::empty:
		return '_';
	}
	return '_';
}

bool figure::is_empty() const
{
	if (figure_ == figure_enum::empty)
	{
		return true;
	}
	return false;
}

figure figure::get_opposite_figure() const
{
	if (figure_ == figure_enum::nought)
	{
		return figure(figure_enum::cross);
	}
	if (figure_ == figure_enum::cross)
	{
		return figure(figure_enum::nought);
	}
	return figure(figure_enum::nought);
}

figure figure::get_empty_figure()
{
	return figure(figure_enum::empty);
}
