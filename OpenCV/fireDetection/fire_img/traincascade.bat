opencv_traincascade.exe -data data -vec pos.vec -bg neg.txt -numPos 80 -numNeg 40 -numStages 20 -precalcValbufSize 200 -precalcdxBufSize 1000 -w 30 -h 30 -minHitRate 0.995 -featureType HAAR
 
pause