# sd92wav
sd92wav (Well... SD9-to-WAV) is a simple converter that converts a sd9 file to wav. The format is very simple. It is simply a WAV file with 0x20 (32 bytes) of additional data added onto the front of the file. Because of this, it is as simple as chopping those first few bytes off and it will read properly as a WAV file.

# About sd9 files
sd9 files are typically in Beatmania IIDX games. The ones tested for this program were Beatmania IIDX 20 Tricoro and Beatmania IIDX 21 SPADA.

# Usage
*sd92wav.exe *.sd9 [*.wav]*</br>
"*.wav" is optional. If omitted, it would tack on ".wav" to the original filename.

*sd92wav.exe syssd_bgm_default_l0.sd9*</br>
This converts the file and outputs "syssd_bgm_default_l0.sd9.wav".

*sd92wav.exe syssd_bgm_default_l0.sd9 syssd_bgm_default_l0.wav*</br>
This converts the file and outputs "syssd_bgm_default_l0.wav".

Typing nothing and simply running the application shows the usage in the command line.
