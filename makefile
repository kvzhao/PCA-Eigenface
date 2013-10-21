CC = g++
CFLAGS=-Wall
IFLAGS=-I/usr/local/include/opencv
IFLAGS+=-I/usr/local/include/opencv2
LFLAGS=-lm -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_objdetect

all: face_recog eigenface_test

face_recog:
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -shared -fPIC myFaceRecognizer.cpp -o facerecognizer.o

eigenface_test: face_recog
	$(CC) $(CFLAGS) $(LFLAGS) $(IFLAGS) -shared -fPIC facerecognizer.o EigenFacesTest.cpp -o eigenfacestest

clean:
	rm *.o eigenfacestest
