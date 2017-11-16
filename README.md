# mp3splitter
Pre-processor for splitting a long mp3 song downloaded from Youtube into individual mp3 files with the help of ffmpeg.

## main source file
mp3splitter.cpp

## sample input text
input.txt

## Build
g++ -std=c++11 mp3splitter.cpp

## Run
./a.out input.txt input.mp3 " - - "

## Result
<pre>
ffmpeg -i input.mp3 -acodec copy -ss 00:00 -t 182 -metadata Title="This Is What You Came For" -metadata Artist="Michelle Simonal" "This Is What You Came For.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 03:02 -t 175 -metadata Title="Get the Party Started" -metadata Artist="Stella Starlight Trio" "Get the Party Started.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 05:57 -t 321 -metadata Title="When We Were Young" -metadata Artist="Michelle Simonal" "When We Were Young.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 11:18 -t 234 -metadata Title="Never Be the Same" -metadata Artist="Sarah Menescal" "Never Be the Same.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 15:12 -t 262 -metadata Title="Sex with Me" -metadata Artist="Banda Do Sul" "Sex with Me.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 19:34 -t 222 -metadata Title="Sorry" -metadata Artist="Stella Starlight Trio" "Sorry.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 23:16 -t 197 -metadata Title="Enter Sandman" -metadata Artist="Jazzystics" "Enter Sandman.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 26:33 -t 270 -metadata Title="Hello" -metadata Artist="Amazonics" "Hello.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 31:03 -t 251 -metadata Title="Don't You Remember?" -metadata Artist="Morgan, G & Machines" "Don't You Remember?.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 35:14 -t 233 -metadata Title="Shape of You (Reggae Version)" -metadata Artist="Groove da Praia" "Shape of You (Reggae Version).mp3"
ffmpeg -i input.mp3 -acodec copy -ss 39:07 -t 220 -metadata Title="We Don't Talk Anymore (Reggaeton Mix)" -metadata Artist="Stereo Dub" "We Don't Talk Anymore (Reggaeton Mix).mp3"
ffmpeg -i input.mp3 -acodec copy -ss 42:47 -t 243 -metadata Title="Man Down (Bossa Nova Mix)" -metadata Artist="Shelly Sony" "Man Down (Bossa Nova Mix).mp3"
ffmpeg -i input.mp3 -acodec copy -ss 46:50 -t 224 -metadata Title="Please Don't Go" -metadata Artist="Eve St. Jones" "Please Don't Go.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 50:34 -t 268 -metadata Title="21 Guns (Album Mix)" -metadata Artist="Michelle Simonal" "21 Guns (Album Mix).mp3"
ffmpeg -i input.mp3 -acodec copy -ss 55:02 -t 237 -metadata Title="Walk of Life" -metadata Artist="Pink-House, Sylvie" "Walk of Life.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 58:59 -t 266 -metadata Title="The Scientist" -metadata Artist="Flora Martinez" "The Scientist.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 01:03:25 -t 201 -metadata Title="Sugar" -metadata Artist="Stella Starlight Trio" "Sugar.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 01:06:46 -t 246 -metadata Title="Let Her Go" -metadata Artist="Eve St. Jones" "Let Her Go.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 01:10:52 -t 243 -metadata Title="West End Girls" -metadata Artist="Ituana" "West End Girls.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 01:14:55 -t 223 -metadata Title="Carlito's Way" -metadata Artist="Von Mondo" "Carlito's Way.mp3"
ffmpeg -i input.mp3 -acodec copy -ss 01:18:38 -metadata Title="Satellite of Love" -metadata Artist="Anakelly" "Satellite of Love.mp3"
</pre>
