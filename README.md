Super-minimal CLI audio player based on FMOD.

It's designed for quite a specific use case (namely installation work), so the focus will be on stability and simplicity rather than features.
Currently all audio is read into memory, rather than streamed from disk. This is by design but may be revised later.

Builds on OSX currently. I'll be working on Linux support shortly.

### This is currently working:
+ Looping a single audio file (by passing the filepath as the first argument)

### What's coming / roadmap:
+ Play and loop multiple audio files
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