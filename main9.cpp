#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NAME_LENGTH = 16;
typedef char String[NAME_LENGTH];

struct Matrix {
    double a11, a12, a21, a22;
};

void get_matrix(String, Matrix&);
void get_scalar(double&);
void calc_sum(Matrix&, Matrix&, Matrix&);
void calc_diff(Matrix&, Matrix&, Matrix&);
void scalar_mult(double&, Matrix&, Matrix&);
void calc_prod(Matrix&, Matrix&, Matrix&);
void calc_inv(Matrix&, Matrix&);
void print_matrix(fstream&, String, Matrix&);


int main() {
    Matrix m1, m2, answer;
    String name1, name2, outputName = "Output";
    double scalar;
    fstream outfile;
    bool run = true;
    int option;

    while (run) {
        get_matrix(name1, m1);
        get_matrix(name2, m2);
        get_scalar(scalar);

        cout<<"Inputted Data:"<<endl;
        cout << left << "Matrix 1:\n" << " _ " << setw(16) << name1 << " _\n| " << setw(8) 
        << m1.a11 << "  "<< setw(8) << m1.a12 << " |\n|                    |\n|_"
        << setw(8) << m1.a21 << "  " << setw(8) << m1.a22 << "_|\n";
        cout << "Matrix 2:\n" << " _ " << setw(16) << name2 << " _\n| " << setw(8) << m2.a11 
        << "  "<< setw(8) << m2.a12 << " |\n|                    |\n|_"
        << setw(8) << m2.a21 << "  " << setw(8) << m2.a22 << "_|\n";
        cout << "Scalar: " << scalar << endl << endl;

        print_matrix(outfile, name1, m1);
        print_matrix(outfile, name2, m2);

        cout<<"1. Add matrices\n"
        <<"2. Subtract matrices\n"
        <<"3. Multiply matrices\n"
        <<"4. Multiply matrix by scalar\n"
        <<"5. Find the inverse of a matrix\n"
        <<"Input a number for the option you'd like to pick (input any other number to exit): ";
        cin>>option;

        switch(option) {
            case 1:
                calc_sum(m1, m2, answer);
                print_matrix(outfile, outputName, answer);
                cout << "Sum:\n" << " _ " << setw(16) << "Sum" << " _\n| " << setw(8) << answer.a11 
                << "  "<< setw(8) << answer.a12 << " |\n|                    |\n|_"
                << setw(8) << answer.a21 << "  " << setw(8) << answer.a22 << "_|\n";
                break;
            case 2:
                calc_diff(m1, m2, answer);
                print_matrix(outfile, outputName, answer);
                cout << "Difference:\n" << " _ " << setw(16) << "Difference" << " _\n| " << setw(8) << answer.a11 
                << "  "<< setw(8) << answer.a12 << " |\n|                    |\n|_"
                << setw(8) << answer.a21 << "  " << setw(8) << answer.a22 << "_|\n";
                break;
            case 3:
                calc_prod(m1, m2, answer);
                print_matrix(outfile, outputName, answer);
                cout << "Product:\n" << " _ " << setw(16) << "Product" << " _\n| " << setw(8) << answer.a11 
                << "  "<< setw(8) << answer.a12 << " |\n|                    |\n|_"
                << setw(8) << answer.a21 << "  " << setw(8) << answer.a22 << "_|\n";
                break;
            case 4:
                cout<<"Which matrix would you like to use (1 or 2): ";
                cin>>option;
                while (option != 1 && option != 2) {
                    cout<<"Invalid input!\nWhich matrix would you like to use (1 or 2): ";
                    cin>>option;
                }
                (option == 1) ? scalar_mult(scalar, m1, answer) : scalar_mult(scalar, m2, answer);
                print_matrix(outfile, outputName, answer);
                cout << "Scalar Product:\n" << " _ " << setw(16) << "Scalar Product" << " _\n| " << setw(8) << answer.a11 
                << "  "<< setw(8) << answer.a12 << " |\n|                    |\n|_"
                << setw(8) << answer.a21 << "  " << setw(8) << answer.a22 << "_|\n";
                break;
            case 5:
                cout<<"Which matrix would you like to use (1 or 2): ";
                cin>>option;
                while (option != 1 && option != 2) {
                    cout<<"Invalid input!\nWhich matrix would you like to use (1 or 2): ";
                    cin>>option;
                }
                (option == 1) ? calc_inv(m1, answer) : calc_inv(m2, answer);
                print_matrix(outfile, outputName, answer);
                cout << "Inverse:\n" << " _ " << setw(16) << "Inverse" << " _\n| " << setw(8) << answer.a11 
                << "  "<< setw(8) << answer.a12 << " |\n|                    |\n|_"
                << setw(8) << answer.a21 << "  " << setw(8) << answer.a22 << "_|\n";
                break;
            default:
                run = false;
                break;
        }
    }

    return 0;
}

void get_matrix(String name, Matrix& m) {
    cout<<"Please give your matrix a name: ";
    cin>>name;
    cout<<endl;
    cout<<"Please input the number for postion (1, 1) of the matrix: ";
    cin>>m.a11;
    cout<<endl;
    cout<<"Please input the number for postion (1, 2) of the matrix: ";
    cin>>m.a12;
    cout<<endl;
    cout<<"Please input the number for postion (2, 2) of the matrix: ";
    cin>>m.a21;
    cout<<endl;
    cout<<"Please input the number for postion (2, 2) of the matrix: ";
    cin>>m.a22;
    cout<<endl;
}

void get_scalar(double& b) {
    cout<<"Please input the scalar: ";
    cin>>b;
    cout<<endl;
}

void calc_sum(Matrix& m1, Matrix& m2, Matrix& sum) {
    sum.a11 = m1.a11 + m2.a11;
    sum.a12 = m1.a12 + m2.a12;
    sum.a21 = m1.a21 + m2.a21;
    sum.a22 = m1.a22 + m2.a22;
}

void calc_diff(Matrix& m1, Matrix& m2, Matrix& diff) {
    diff.a11 = m1.a11 - m2.a11;
    diff.a12 = m1.a12 - m2.a12;
    diff.a21 = m1.a21 - m2.a21;
    diff.a22 = m1.a22 - m2.a22;
}

void scalar_mult(double& k, Matrix& m, Matrix& k_m) {
    k_m.a11=m.a11*k;
    k_m.a12=m.a12*k;
    k_m.a21=m.a21*k;
    k_m.a22=m.a22*k;
}

void calc_prod(Matrix& m1, Matrix& m2, Matrix& prod) {
    prod.a11 = m1.a11 * m2.a11 + m1.a12 * m2.a21;
    prod.a12 = m1.a11 * m2.a12 + m1.a12 * m2.a22;
    prod.a21 = m1.a21 * m2.a11 + m1.a22 * m2.a21;
    prod.a22 = m1.a21 * m2.a12 + m1.a22 * m2.a22;
}

void calc_inv(Matrix& m, Matrix& m_inv) {
    double det = m.a11 * m.a22 - m.a12 * m.a21;
    m_inv.a11 = m.a22/det;
    m_inv.a22 = m.a11/det;
    m_inv.a12 = -m.a12/det;
    m_inv.a21 = -m.a21/det;
}

void print_matrix(fstream& outfile, String name, Matrix& m) {
    outfile.open("output.txt", ios_base::app);
    outfile << left << " _ " << setw(16) << name << " _\n| " << setw(8) 
    << m.a11 << "  "<< setw(8) << m.a12 << " |\n|                    |\n|_"
    << setw(8) << m.a21 << "  " << setw(8) << m.a22 << "_|\n";
    outfile.close();
}
