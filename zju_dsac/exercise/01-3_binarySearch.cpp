// Copyright [2018] <mituh>

Position BinarySearch(List L, ElementType X) {
  Position left = 1, right = L->Last;
  while (left <= right) {
    if (left == right) {
      if (L->Data[left] == X) {
        return left;
      } else {
        return NotFound;
      }
    }
    Position mid = (left+right)/2;
    if (X < L->Data[mid]) {
      right = mid;
    } else if (X > L->Data[mid]) {
      left = mid+1;
    } else {
      return mid;
    }
  }
  return NotFound;
}


/*
Position BinarySearch(List L, ElementType X) {
  Position left = 1, right = L->Last;
  while (left <= right) {
    Position mid = (left+right)/2;
    if (X < L->Data[mid]) {
      right = mid;
    } else if (X > L->Data[mid]) {
      left = mid+1;
    } else {
      return mid;
    }
  }
  return NotFound;
}
// case1, 6: LTE
*/
