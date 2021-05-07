#pragma once

#include <algorithm>

template <typename T> class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size);
  SimpleVector(const SimpleVector &vec);
  SimpleVector(SimpleVector &&vec);
  ~SimpleVector();

  void operator=(const SimpleVector &rhs);
  void operator=(SimpleVector &&rhs);
  T &operator[](size_t index);
  const T &operator[](size_t index) const;
  T *begin();
  T *end();
  const T *begin() const;
  const T *end() const;

  size_t Size() const;
  size_t Capacity() const;
  void PushBack(const T &value);
  void PushBack(T&& value);

private:
  T *data = nullptr;
  size_t size = 0;
  size_t capacity = 0;

  void ExpandIfNeeded();
};

template <typename T>
SimpleVector<T>::SimpleVector(size_t size)
    : data(new T[size]), size(size), capacity(size) {}

template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector<T> &rhs) {
  if (rhs.size <= capacity) {
    std::copy(rhs.begin(), rhs.end(), begin());
    size = rhs.size;
  } else {
    SimpleVector<T> tmp(rhs.Size());
    std::copy(rhs.begin(), rhs.end(), tmp.begin());
    std::swap(tmp.data, data);
    std::swap(tmp.size, size);
    std::swap(tmp.capacity, capacity);
  }
}

template <typename T> SimpleVector<T>::SimpleVector(SimpleVector<T> &&rhs) {
  if (rhs.size <= capacity) {
    std::move(rhs.begin(), rhs.end(), begin());
    size = rhs.size;
  } else {
    SimpleVector<T> tmp(rhs);
    std::swap(tmp.data, data);
    std::swap(tmp.size, size);
    std::swap(tmp.capacity, capacity);
  }
}

template <typename T> SimpleVector<T>::~SimpleVector() { delete[] data; }

template <typename T> void SimpleVector<T>::operator=(const SimpleVector &rhs) {
  if (rhs.size <= capacity) {
    std::copy(rhs.begin(), rhs.end(), begin());
    size = rhs.size;
  } else {
    SimpleVector<T> tmp(rhs);
    std::swap(tmp.data, data);
    std::swap(tmp.size, size);
    std::swap(tmp.capacity, capacity);
  }
}

template <typename T> void SimpleVector<T>::operator=(SimpleVector &&rhs) {
  if (rhs.size <= capacity) {
    std::move(rhs.begin(), rhs.end(), begin());
    size = rhs.size;
  } else {
    SimpleVector<T> tmp(rhs);
    std::swap(tmp.data, data);
    std::swap(tmp.size, size);
    std::swap(tmp.capacity, capacity);
  }
}

template <typename T> T &SimpleVector<T>::operator[](size_t index) {
  return data[index];
}

template <typename T> size_t SimpleVector<T>::Size() const { return size; }

template <typename T> size_t SimpleVector<T>::Capacity() const {
  return capacity;
}

template <typename T> void SimpleVector<T>::PushBack(T&& value) {
  ExpandIfNeeded();
  data[size++] = std::move(value);
}

template <typename T> void SimpleVector<T>::PushBack(const T &value) {
  ExpandIfNeeded();
  data[size++] = value;
}

template <typename T> void SimpleVector<T>::ExpandIfNeeded() {
  if (size >= capacity) {
    auto new_cap = capacity == 0 ? 1 : 2 * capacity;
    auto new_data = new T[new_cap];
    std::move(begin(), end(), new_data);
    delete[] data;
    data = new_data;
    capacity = new_cap;
  }
}

template <typename T> T *SimpleVector<T>::begin() { return data; }

template <typename T> T *SimpleVector<T>::end() { return data + size; }

template <typename T> const T *SimpleVector<T>::begin() const { return data; }

template <typename T> const T *SimpleVector<T>::end() const {
  return data + size;
}

// int main() { return 0; }