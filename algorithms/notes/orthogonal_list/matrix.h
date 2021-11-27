#ifndef MATRIX_H_
#define MATRIX_H_

/**
 * ����ĳ�����������.
 * - ���ݶ���: <val, i, j>��Ԫ��, ��ʾ�����i�е�j�е�Ԫ��Ϊval, val������Ϊ
 * ElemType.
 * - ��������:
 *    - ����n*m��ģ�Ŀվ���: CreateMatrix(Matrix &M, int n, int m)
 *    - ���õ�i�е�j�е�Ԫ��ֵ: SetElem(Matrix &M, int n, int m, ElemType e)
 *    - ��ȡ��i�е�j�е�Ԫ��ֵ: GetElem(Matrix M, int n, int m, ElemType &e)
 *    - ��ȡ��������: GetRows(Matrix M)
 *    - ��ȡ��������: GetColumns(Matrix M)
 *    - �������: MatrixAdd(Matrix M1, Matrix M2)
 *    - �������: MatrixMult(Matrix M1, Matrix M2)
 *    - ��ӡ����Ԫ��: MatrixPrint(Matrix M)
 */

#include <iostream>
#include <cassert>

// ʮ��������ṹ
typedef struct OLNode {
  int i, j, val;
  OLNode *down, *right;
}OLNode, *OLink;

// ʮ������ṹ
// rhead�洢����������ı�ͷ
// chead�洢����������ı�ͷ
// n, m, t�ֱ��ʾ���������, �����ͷ���Ԫ�ظ���
typedef struct {
  OLink *rhead, *chead;
  int n, m, t;
}CrossLink;


// ����ʮ������ľ���ʵ��
template <typename ElemType>
class Matrix {
 public:
  // ͨ��������ʽ��ʼ������
  Matrix(ElemType default_value = 0);
  Matrix(int rows, int cols) = delete;
  Matrix(const Matrix &m) = delete;  // copy c'tor

  ElemType GetElem(int i, int j) const;
  void SetElem(int i, int j, const ElemType &e) = delete;

  int rows() const { return rows_; }
  int cols() const { return cols_; }

  Matrix & operator=(const Matrix &m) = delete;  // assignment

  Matrix & operator+(const Matrix &m) = delete;  // m1 + m2
  Matrix & operator*(const Matrix &m) = delete;  // m1 * m2

  // ��ӡ��������Ԫ��
  void print() const;


 private:
  /* data */
  const ElemType kDefaultValue;
  // ʮ��������
  typedef struct OLNode {
    int i, j;
    ElemType val;
    OLNode *down, *right;
    OLNode() {
      down = right = nullptr;
    }
    OLNode(int row, int col, ElemType value)
        : i(row), j(col), val(value) {
      down = right = nullptr;
    }
  }OLNode, *OLink;
  // �洢������/�������ͷ���ָ�������
  OLink *chead_, *rhead_;
  // ��������/����
  int rows_, cols_;
  // �����еķ���Ԫ�ظ���
  int total_;
};

template <typename ElemType>
Matrix<ElemType>::Matrix(ElemType default_value)
    : kDefaultValue(default_value) {
  std::cout << "���������������, �����ͷ���Ԫ�ظ���: ";
  std::cin >> rows_ >> cols_ >> total_;
  rhead_ = new OLink[rows_];
  chead_ = new OLink[cols_];
  for (int i = 0; i < rows_; i++) {
    rhead_[i] = nullptr;
  }
  for (int i = 0; i < cols_; i++) {
    chead_[i] = nullptr;
  }
  int n = total_;
  int i, j, val;
  while (n--) {
    std::cout << "...������Ԫ��(i, j, val): ";
    std::cin >> i >> j >> val;
    OLNode *pnode = new OLNode(i, j, val);
    // ���½����뵽��Ӧ�������е���ȷλ��: �����㰴�ս��ֵ��С��������
    // �½����뵽��Ӧ�е�����
    if (rhead_[i] == nullptr || rhead_[i]->j > j) {
      pnode->right = rhead_[i];
      rhead_[i] = pnode;
    } else { // ����λ�ò�������
      OLNode *p = rhead_[i];
      // ��p�ƶ���������λ��
      while (p->right && p->right->j < j) {
        p = p->right;
      }
      pnode->right = p->right;
      p->right = pnode;
    }
    // ���½����뵽��Ӧ���������ȷλ��: �����㰴�ս��ֵ��С��������
    // �½����뵽��Ӧ�е�����
    if (chead_[j] == nullptr || chead_[j]->i > i) {
      pnode->down = chead_[j];
      chead_[j] = pnode;
    } else { // ����λ�ò�������
      OLNode *p = chead_[j];
      // ��p�ƶ���������λ��
      while (p->down && p->down->i > i) {
        p = p->down;
      }
      pnode->down = p->down;
      p->down = pnode;
    }
  }
}

template <typename ElemType>
ElemType Matrix<ElemType>::GetElem(int i, int j) const {
  assert(i >= 0 && i < rows_);
  assert(j >= 0 && j < cols_);
  OLNode *p = rhead_[i];
  while (p) {
    if (p->j == j) {
      return p->val;
    }
    p = p->right;
  }
  return kDefaultValue;
}

template <typename ElemType>
void Matrix<ElemType>::print() const {
  for (int i = 0; i < rows_; i++) {
    if (rhead_[i]) {
      OLink p = rhead_[i];
      while (p) {
        std::cout << p->i << ", " << p->j << ": " << p->val << std::endl;
        p = p-> right;
      }
    }
  }
}

#endif // MATRIX_H_