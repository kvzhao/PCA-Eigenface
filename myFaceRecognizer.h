#ifndef __FACERECOGNIZER_H__
#define __FACERECOGNIZER_H__

#include <iostream>
#include <vector>
#include <float.h>
#include <cv.h>

using namespace std;
using namespace cv;
class myFaceRecognizer {
	public:
		myFaceRecognizer(const Mat& trFaces, const vector<int>& trImageIDToSubjectIDMap, int components);
		~myFaceRecognizer();

        /* Inner function, used for constructor. */
		void init(const Mat& trFaces, const vector<int>& trImageIDToSubjectIDMap, int components);

        /* Predict function */
		int recognize(const Mat& instance);

        /* Get functions : PCA wrappers */
		Mat getAverage();
		Mat getEigenvectors();
		Mat getEigenvalues();

	private:
        /* major source of algorithm comes from OpenCV lib */
		PCA *pca;
        /* DB of faces from training data */
		vector<Mat> projTrFaces;
        /* Index of each traning faces */
		vector<int> trImageIDToSubjectIDMap;
};

#endif