opencv_traincascade.exe -data data/ -vec pos.vec -bg neg.txt -numPos 200 -numNeg 500 -numStages 20 -precalcValbufSize 200 -precalcdxBufSize 1000 -w 50 -h 50 -minHitRate 0.995 -featureType HAAR
 
pause