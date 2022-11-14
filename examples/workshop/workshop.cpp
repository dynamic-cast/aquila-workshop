#include "aquila/functions.h"
#include "aquila/source/WaveFile.h"
#include "aquila/transform/Mfcc.h"

#include <algorithm>
#include <iostream>
#include <vector>

namespace
{

std::size_t roundToPowerOf2(std::size_t n)
{
    if (Aquila::isPowerOf2(n))
    {
        return n;
    }

    return Aquila::nextPowerOf2(n);
}

}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: workshop <FILENAME>" << std::endl;
        return 1;
    }

    Aquila::WaveFile wav(argv[1]);

    const auto numSamples = wav.getSamplesCount();
    const auto fftSize = roundToPowerOf2(numSamples);

    auto paddedData = std::vector<Aquila::SampleType>(fftSize);
    std::copy_n(wav.begin(), numSamples, paddedData.begin());

    const auto paddedSignal = Aquila::SignalSource(paddedData, wav.getSampleFrequency());

    Aquila::Mfcc mfcc(fftSize);
    const auto mfccValues = mfcc.calculate(paddedSignal);

    for (const auto val : mfccValues)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;
}
