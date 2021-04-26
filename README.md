# FormantSynth
# FormantSynth

Vladimir Baranov
vsbaranov83@gmail.com
https://twitter.com/Kvazikot

To use FormantSynth in multiple voices mode you need to create mixer device.
Put this following strings in  ~/.asoundrc file and restart your machine.
When select plug:dmix device in FormantSynth. Restart FormantSynth.

>>>> content of .asoundrc file >>>>>>>>>>>

pcm.hw3mix {
    type dmix
    ipc_key 1939 # must be unique
    slave {
            pcm "hw:0,0"
            channels 8
            period_size 1024
            buffer_size 4096
            rate 48000
    }
}

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>







