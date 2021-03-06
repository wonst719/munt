/* Copyright (C) 2011, 2012, 2013, 2014 Jerome Fisher, Sergey V. Mikayev
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

#ifndef SAMPLERATE_ADAPTER_H
#define SAMPLERATE_ADAPTER_H

#include <samplerate.h>

#include "SampleRateConverter.h"

class SamplerateAdapter : public SampleRateConverter {
public:
	SamplerateAdapter(MT32Emu::Synth *synth, double targetSampleRate, SRCQuality quality);
	~SamplerateAdapter();
	void getOutputSamples(MT32Emu::Sample *buffer, unsigned int length);

private:
	float * const inBuffer;
	unsigned int inBufferSize;
	SRC_STATE *resampler;

	static long getInputSamples(void *cb_data, float **data);
};

#endif // SAMPLERATE_ADAPTER_H
