#pragma once

#include "MediaTests.hpp"

#include "creators/AudioBuilder.hpp"
#include "media/Audio.hpp"
#include "mocks/MockAudioHandler.hpp"

class AudioTest : public MediaTest<MockAudioHandler>
{
public:
    auto constructAudio()
    {
        return constructAudio(DEFAULT_AUDIO_MUTED, DEFAULT_AUDIO_LOOPED, MAX_VOLUME);
    }

    std::unique_ptr<Audio> constructAudio(boost::optional<AudioOptions::Mute> muted,
                                          boost::optional<AudioOptions::Loop> looped,
                                          boost::optional<int> volume)
    {
        AudioOptions opts{DEFAULT_ID, DEFAULT_PATH.string(), DEFAULT_DURATION, muted, looped, volume};

        return AudioBuilder{}.adaptor(unique(&adaptor()))
                             .filesystem(unique(&filesystem()))
                             .options(opts)
                             .build();
    }

};
