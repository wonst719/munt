/* Copyright (C) 2011 Jerome Fisher, Sergey V. Mikayev
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 2.1 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QtGui>
#include <QProcessEnvironment>
#include <mt32emu/mt32emu.h>

#include "MainWindow.h"
#include "Master.h"
#include "MasterClock.h"
#include "QSynth.h"

#include "mididrv/TestDriver.h"
#ifdef WITH_WIN32_MIDI_DRIVER
#include "mididrv/Win32Driver.h"
#endif

using namespace MT32Emu;

int main(int argv, char **args)
{
	QApplication app(argv, args);
	app.setApplicationName("Munt mt32emu-qt");

	QProcessEnvironment::systemEnvironment().insert("PA_ALSA_PLUGHW", "1");

	MasterClock::init();
	Master::init();
	{
		MainWindow mainWindow(Master::getInstance());
		mainWindow.show();
		app.exec();
	}
	Master::deinit();
	MasterClock::deinit();
	return 0;
}