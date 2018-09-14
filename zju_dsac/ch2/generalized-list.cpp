// Copyright [2018] <mituh>
// generalized-list.cpp

typedef struct GNode *GList;
struct GNode {
  int tag;
  union {
    ElementType Data;
    GList subList;
  };
  GList next;
};
