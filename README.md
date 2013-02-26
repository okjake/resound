## Super-minimal CLI audio player

It's designed for quite a specific use case (namely installation work), so the focus will be on stability and simplicity rather than features.
Currently all audio is read into memory, rather than streamed from disk. This is by design but may be revised later.

Builds on OSX currently. I'll be working on Linux support shortly. Built on FMOD.

### Usage
Pass one or more soundfile paths as command line arguments. They will be played.
If you need more fine-grained configuration, use a configuration YAML file. There's one in the examples folder.

### Currently working:
+ Looping a single audio file (by passing the filepath as the first argument)
+ Play and loop multiple audio files

### What's coming / roadmap:
+ Passing external config file at runtime
+ OSC support

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