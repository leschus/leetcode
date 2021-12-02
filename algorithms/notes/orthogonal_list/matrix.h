#ifndef MATRIX_H_
#define MATRIX_H_

/**
 * 矩阵的抽象数据类型.
 * - 数据对象: <val, i, j>三元组, 表示矩阵第i行第j列的元素为val, val的类型为
 * ElemType.
 * - 基本操作:
 *    - 创建n*m规模的空矩阵: CreateMatrix(Matrix &M, int n, int m)
 *    - 设置第i行第j列的元素值: SetElem(Matrix &M, int n, int m, ElemType e)
 *    - 获取第i行第j列的元素值: GetElem(Matrix M, int n, int m, ElemType &e)
 *    - 获取矩阵行数: GetRows(Matrix M)
 *    - 获取矩阵列数: GetColumns(Matrix M)
 *    - 矩阵相加: MatrixAdd(Matrix M1, Matrix M2)
 *    - 矩阵相乘: MatrixMult(Matrix M1, Matrix M2)
 *    - 打印矩阵元素: MatrixPrint(Matrix M)
 */

#include <iostream>
#include <cassert>

// 十字链表结点结构
typedef struct OLNode {
  int i, j, val;
  OLNode *down, *right;
}OLNode, *OLink;

// 十字链表结构
// rhead存储所有行链表的表头
// chead存储所有列链表的表头
// n, m, t分别表示矩阵的行数, 列数和非零元素个数
typedef struct {
  OLink *rhead, *chead;
  int n, m, t;
}CrossLink;


// 基于十字链表的矩阵实现
template <typename ElemType>
class Matrix {
 public:
  // 通过交互方式初始化矩阵
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

  // 打印矩阵所有元素
  void print() const;


 private:
  /* data */
  const ElemType kDefaultValue;
  // 十字链表结点
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
  // 存储所有列/行链表的头结点指针的数组
  OLink *chead_, *rhead_;
  // 矩阵行数/列数
  int rows_, cols_;
  // 矩阵中的非零元素个数
  int total_;
};

template <typename ElemType>
Matrix<ElemType>::Matrix(ElemType default_value)
    : kDefaultValue(default_value) {
  std::cout << "依次输入矩阵行数, 列数和非零元素个数: ";
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
    std::cout << "...输入三元组(i, j, val): ";
    std::cin >> i >> j >> val;
    OLNode *pnode = new OLNode(i, j, val);
    // 将新结点插入到对应行链表中的正确位置: 链表结点按照结点值大小升序排列
    // 新结点插入到对应行的行首
    if (rhead_[i] == nullptr || rhead_[i]->j > j) {
      pnode->right = rhead_[i];
      rhead_[i] = pnode;
    } else { // 插入位置不在行首
      OLNode *p = rhead_[i];
      // 将p移动到待插入位置
      while (p->right && p->right->j < j) {
        p = p->right;
      }
      pnode->right = p->right;
      p->right = pnode;
    }
    // 将新结点插入到对应列链表的正确位置: 链表结点按照结点值大小升序排列
    // 新结点插入到对应列的列首
    if (chead_[j] == nullptr || chead_[j]->i > i) {
      pnode->down = chead_[j];
      chead_[j] = pnode;
    } else { // 插入位置不再列首
      OLNode *p = chead_[j];
      // 将p移动到待插入位置
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