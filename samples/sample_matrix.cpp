// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
#include <string.h>
//---------------------------------------------------------------------------

void main()
{
    TMatrix<int> a(5);
  TMatrix<int> b(5);
  TMatrix<int> c(5);

  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� ������������� ����������� ������"
    << endl;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++ )
    {
      a[i][j] =  i * 5 + j;
      b[i][j] = (i * 5 + j) * 50;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;

}
//---------------------------------------------------------------------------
