## Super-minimal CLI audio player

[Under development, currently very limited functionality]

Built with arts installations in mind. The idea is to provide a basic, rock-solid player that can be controlled over OSC.
All of the configuration and mapping can be stored in one portable JSON document, bundling this with your audio files allows you to recreate your environment easily. 
Builds on OSX currently. I'll be working on Linux support shortly.

### Usage
Pass one or more soundfile paths as command line arguments. They will be played.
If you need more fine-grained configuration, use a configuration JSON file. There's one in the examples folder.

### Currently working:
+ Play and loop one or more audio files

### What's coming / roadmap:
The following should be configurable at runtime:
+ Useful features of the FMOD API
+ OSC mapping

### Supported audio file formats
+ AIFF
+ ASF
+ ASX
+ DLS
+ FLAC
+ FSB
+ IT
+ M3U
+ MIDI
+ MOD
+ MP2
+ MP3
+ Ogg Vorbis
+ PLS
+ S3M
+ VAG
+ WAV
+ WAX
+ WMA
+ XM
+ Raw audio data