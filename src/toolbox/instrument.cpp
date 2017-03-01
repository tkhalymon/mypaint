#include "instrument.hpp"

Instrument::Instrument(shared_ptr<int> width, shared_ptr<int> padding, shared_ptr<int> instrument) : Toolbox (width, padding), value(instrument)
{
	*value = 1;
	height = 20 * 4;
}

Instrument::~Instrument()
{

}

void Instrument::render() const
{
	// render background
	glColor3d(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2i(0, 0);
	glVertex2i(*width, 0);
	glVertex2i(*width, height);
	glVertex2i(0, height);
	glEnd();
	
	int iconHeight = 20;

	// gray for selected
	glColor3d(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(0, (*value - 1) * iconHeight);
	glVertex2i(*width, (*value - 1) * iconHeight);
	glVertex2i(*width, (*value) * iconHeight);
	glVertex2i(0, (*value) * iconHeight);
	glEnd();
	// save matrix transformations
	glPushMatrix();
	glLineWidth(2);
	glColor3d(0, 0, 0);
	// pencil - just a sinusoide
	glBegin(GL_LINE_STRIP);
	for (double i = 0; i < (*width - *padding * 2) / 5; i += 0.2)
		glVertex2i(*padding + i * 5, iconHeight / 2 + sin(i) * 7);
	glEnd();
	// line
	glTranslated(0, iconHeight, 0);
	glBegin(GL_LINES);
	glVertex2i(*padding, 5);
	glVertex2i(*width - *padding, 15);
	glEnd();
	// elipse
	glTranslated(0, iconHeight, 0);
	glBegin(GL_LINE_LOOP);
	for (double angle = 0; angle < 2 * M_PI; angle += 0.01)
	{
		glVertex2i(*width / 2 + cos(angle) * (*width / 2 - *padding), 10 + sin(angle) * 7);
	}
	glEnd();
	// rectangle
	glTranslated(0, iconHeight, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(*padding, 3);
	glVertex2i(*padding, 17);
	glVertex2i(*width - *padding, 17);
	glVertex2i(*width - *padding, 3);
	glEnd();
	// revert matrix transformations
	glPopMatrix();
}

bool Instrument::mouseClick(const Vertex& pos)
{
	// check if mouse is inside toolbox
	if (pos.x() > 0 && pos.x() < *width
		&& pos.y() > 0 && pos.y() < height)
	{
		// set value
		*value = pos.y() / 20 + 1;
		return true;
	}
	else
	{
		return false;
	}
}
