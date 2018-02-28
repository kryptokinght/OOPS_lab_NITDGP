#include <bits/stdc++.h>

using namespace std;

class Matrix {

    int rows;
    int cols;
    int **m;

public:
	Matrix() {
		rows = 0;
		cols = 0;
		m = NULL;
	}
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        m = new int*[rows];
        for (int i = 0 ; i < rows ; i++) {
            m[i] = new int[cols];
        }
    }
    ~Matrix() {
    	cout<<"Matrix object Destroyed!!"<<endl;
    }
    int getRow();
    int getCol();
    int **getMatrix();
    void setMatrix(int**);
    void display();
};

int Matrix::getRow() {
    return rows;
}

int Matrix::getCol() {
    return cols;
}

int** Matrix::getMatrix() {
    return m;
}

void Matrix::setMatrix(int **m) {
    for (int i = 0 ; i < rows ; ++i) {
        for (int j = 0 ; j < cols ; ++j) {
            m[i][j] = m[i][j];
        }
    }
}

/*void Matrix::setMatrix() {
	cout<<"Enter elements for the matrix:"<<endl;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++)
			cin>>m[i][j];
	}
}*/

void Matrix::display() {
    for (int i = 0 ; i < rows ; ++i) {
        for (int j = 0 ; j < cols ; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}


Matrix addMatrices(Matrix mat1, Matrix mat2) {

    int r1 = mat1.getRow(), c1 = mat1.getCol();
    int r2 = mat2.getRow(), c2 = mat2.getCol();

    int** m1 = mat1.getMatrix();
    int** m2 = mat2.getMatrix();

    Matrix res(r1, c1); //resultant m

    if (r1 != r2 || c1 != c2) {
        cout << "Matrices of different sizes cannot be added!" << endl;
    } else {
        int** m = new int*[r1];
        for (int i = 0 ; i < r1 ; ++i) {
            m[i] = new int[c1];
            for (int j = 0 ; j < c1 ; ++j)
                m[i][j] = m1[i][j] + m2[i][j];
        }
        res.setMatrix(m);
        for (int i = 0; i < r1; ++i) {
            delete[] m[i];   
        }
        delete[] m;
    }
    return res;
}


Matrix subMatrices(Matrix mat1, Matrix mat2) {

    int r1 = mat1.getRow(), c1 = mat1.getCol();
    int r2 = mat2.getRow(), c2 = mat2.getCol();

    int** m1 = mat1.getMatrix();
    int** m2 = mat2.getMatrix();

    Matrix res(r1, c1);

    if (r1 != r2 || c1 != c2) {
        cout << "Matrices of different sizes cannot be subtracted!" << endl;
    } else {
        int** m = new int*[r1];
        for (int i = 0 ; i < r1 ; ++i) {
            m[i] = new int[c1];
            for (int j = 0 ; j < c1 ; ++j)
                m[i][j] = m1[i][j] - m2[i][j];
        }
        res.setMatrix(m);
        for (int i = 0; i < r1; ++i) {
            delete[] m[i];   
        }
        delete[] m;
    }
    return res;
}


Matrix mulMatrices(Matrix mat1, Matrix mat2) {

    int r1 = mat1.getRow(), c1 = mat1.getCol();
    int r2 = mat2.getRow(), c2 = mat2.getCol();

    int** m1 = mat1.getMatrix();
    int** m2 = mat2.getMatrix();

    Matrix res(r1, c2);

    if (r2 != c1) {
        cout << "Matrices cannot be multiplied. Not compatible sizes!!" << endl;
    } else {
        int** m = new int*[r1];
        for (int i = 0 ; i < r1 ; ++i) {
            m[i] = new int[c2];
            for (int j = 0 ; j < c2 ; ++j) {
                m[i][j] = 0;
                for (int k = 0 ; k < c1 ; ++k)
                    m[i][j] += m1[i][k] * m2[k][j];
            }
        }
        res.setMatrix(m);
        for (int i = 0; i < r1; ++i) {
            delete[] m[i];   
        }
        delete[] m;
    }
    return res;
}


int main() {
    
    int r1, c1;
    cout << "Enter rows and columns for first m: ";
    cin >> r1 >> c1;

    Matrix m1(r1, c1);
    int** m = new int*[r1];
    for (int i = 0 ; i < r1 ; ++i) {
        cout << "Enter values for row " << i+1 << ": ";
        m[i] = new int[c1];
        for (int j = 0 ; j < c1 ; ++j)
            cin >> m[i][j];
    }
    m1.setMatrix(m);
    for (int i = 0; i < r1; ++i) {
        delete[] m[i];   
    }
    delete[] m;

    cout << "First m:" << endl;
    m1.display();
    cout << endl;
    
    int r2, c2;
    cout << "Enter the number of rows and columns of second m: ";
    cin >> r2 >> c2;

    Matrix m2(r2, c2);
    m = new int*[r2];
    for (int i = 0 ; i < r2 ; ++i) {
        cout << "Enter values for row " << i+1 << ": ";
        m[i] = new int[c2];
        for (int j = 0 ; j < c2 ; ++j)
            cin >> m[i][j];
    }
    m2.setMatrix(m);
    for (int i = 0; i < r1; ++i) {
        delete[] m[i];   
    }
    delete[] m;

    cout << "Second m:" << endl;
    m2.display();

    int ch;
    do {
        cout << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Exit" << endl;
        cout << endl << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch(ch) {
            case 1: {
                cout << "Addition:" << endl;
                Matrix res = addMatrices(m1, m2);
                res.display();
                break;
            }
            case 2: {
                cout << "Subtraction:" << endl;
                Matrix res = subMatrices(m1, m2);
                res.display();
                break;
            }
            case 3: {
                cout << "Multiplication:" << endl;
                Matrix res = mulMatrices(m1, m2);
                res.display();
                break;
            }
            case 4:
                break;
            default:
                cout << "Wrong choice!" << endl;
        }
    } while (ch != 4);

    return 0;
}