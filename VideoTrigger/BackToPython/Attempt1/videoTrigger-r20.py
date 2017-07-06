from omxplayer import OMXPlayer
from time import sleep
# import RPi.GPIO as GPIO
import signal
# import subprocess
# import numpy as np

video1Pin = 17
video2Pin = 18
video3Pin = 22
video4Pin = 27

debounceTime = 500

# triggerPins = [video1Pin,video2Pin,video3Pin,video4Pin]
state = 0 # 0 is loop, 1 is 1, 2 is 2

def start_the_video():
    subprocess.call(["pkill", "-9", "omxplayer"])
    # file_path_or_url = '/usr/share/adafruit/webide/repositories/my-pi-projects/ScotchBot_AV/CAPTERED.mp4'
    # file_path_or_url = '/usr/share/adafruit/webide/repositories/my-pi-projects/PyWrapper/python-omxplayer-wrapper/r2-vfr.mp4'
    file_path_or_url = '/home/pi/Videos/SEQUENCE_1-sm2.mp4'
    args=['--loop', '--no-keys', '-b']
    player = OMXPlayer(file_path_or_url, args)
    return player

VideoVersionString = 'r2'
fps = 24.0
clipNames = ['neutral',   'cute',      'dizzy',      'hearts',  'joyful',     'sad',      'smelling'  ]
clipStarts= [0.00,        7+( 3/fps),   10 +(2/fps), 15+(3/fps), 18+(4/fps),  21+(8/fps),  26+(7/fps)]
clipEnds =  [6+(20/fps) , 9+(16/fps),   14+(22/fps), 18.0  ,     21+(4/fps),  26+(2/fps),  29+(0/fps)]#was 29
clipTriggers =[ -1,         -1,         0,            1,          2,           3,          4]

clips = {
    'neutral': {
        'start': 0.00,
        'end': 6.0 + (20/fps),
        'trigger': -1
    }, 
    'cute': {
        'start': 7.00 + (3 / fps),
        'end': (9.0 + (16/fps)),
        'trigger': -1
    },
    'dizzy': {
        'start': 10.00 + (2/fps),
        'end': 14.0 + (22/fps),
        'trigger': 0
    },
    'hearts': {
        'start': 15.00 + (3/fps),
        'end': 18.0,
        'trigger': 1
    },
    'joyful': {
        'start': 18.00 + (4/fps),
        'end':   21.0 + (4/fps),
        'trigger': 2
    },
    'sad': {
        'start': 21.0+(8/fps),
        'end':   26.0+(2/fps),
        'trigger': 3
    },
    'smelling': {
        'start': 26.0+(7/fps),
        'end':   29.0+(0/fps),
        'trigger': 4
    }
}


#clipStarts= np.around(clipStarts, decimals=3)
#clipEnds= np.around(clipEnds, decimals=3)
#print clipStarts
#print clipEnds

#VID_START = clips[''][''] #clipStarts[0]
#VID_END   = #clipEnds[0]

loop_point = clips['neutral']['end'] #VID_END


# GPIO.setmode(GPIO.BCM)
# GPIO.setup(video1Pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
# GPIO.setup(video2Pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
# GPIO.setup(video3Pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
# GPIO.setup(video4Pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)


def kill_all_players(a, b):
    print "killers gonna kill"
    player.quit()
    # subprocess.call(["pkill", "-9", "omxplayer"])
    exit()


#Binds an interupt function to the falling edge of the GPIO pin (Button press)
# GPIO.add_event_detect(video1Pin, GPIO.FALLING, bouncetime=debounceTime)  
# GPIO.add_event_detect(video2Pin, GPIO.FALLING, bouncetime=debounceTime)  
# GPIO.add_event_detect(video3Pin, GPIO.FALLING, bouncetime=debounceTime)  
# GPIO.add_event_detect(video4Pin, GPIO.FALLING, bouncetime=debounceTime)  

#quits on quit
signal.signal(signal.SIGTERM, kill_all_players)
currentPosition = 0

def checkKeyboard():
    key = ord(getch())
    if key == ord('1'): #ESC
        print "you pressed 1!"
        goTo(1)
        break
    elif key == ord('2'): #Enter
        print "you pressed 2!"
        goTo(2)
        break
    elif key == ord('3'): #Special keys (arrows, f keys, ins, del, etc.)
        print "you pressed 3!"
        goTo(3)
        break
    elif key == ord('4'): #Special keys (arrows, f keys, ins, del, etc.)
        print "you pressed 4!"
        goTo(4)
        break
    elif key == ord('5'): #Special keys (arrows, f keys, ins, del, etc.)
        print "you pressed 5!"
        goTo(5)
        break

def goTo(int target):
    print "state is %r" % target
    print "video is %r" % clipNames[target]
    # print "video duration is %r" % (clipEnds[target]-clipStarts[target])
    global loop_point 
    loop_point= clipEnds[target]
    player.set_position(clipStarts[target])
    sleep(1)
    # return loop_point
        

player = start_the_video()

while(True):
    player.play()
    currentPos = player.position()
    #print currentPos
    #print player.maximum_rate()
    if currentPos > loop_point:
        print "LOOPINGcurrent position: %f" %  currentPos
        print "video is back to %r" % clipNames[0]
        loop_point = clipEnds[0]
        player.set_position(clipStarts[0])
        sleep(1)
    sleep(0.1)