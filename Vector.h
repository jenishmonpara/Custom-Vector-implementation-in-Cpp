#pragma once
#include <cassert>

//Points learned for developing big projects:
// use "this" for all member variables
//size_t data type is automatically of the max size that the system allows

template<typename T> class Vector
{
private:
      T *data = nullptr;
      size_t size,capacity;
      void ReAlloc(size_t newCapacity)
      {
            T* newBlock = new T[newCapacity];

            if(newCapacity < this->size)
            {
                  this->size = newCapacity;
            }
            for(size_t i = 0;i<this->size;i++)
            {
                  newBlock[i] = std::move(this->data[i]);
            }
            delete[] this->data;
            this->data = newBlock;
            this->capacity = newCapacity;
      }

public:
      Vector()
      {
            this->size = 0;
            ReAlloc(2);
      }
      Vector(size_t psize, T&& value)
      {
        this->size = psize;
        this->capacity = (psize + psize/2);
        delete[] this->data;
        this->data = new T[capacity];
        for(size_t i=0; i < psize; i++)
          data[i]=value;
      }
      Vector(T para[],size_t psize)
      {
            ReAlloc(psize);
            for(size_t i = 0;i<psize;i++)
            {
                  this->data = para[i];
            }
      }

      size_t Size() const
      {
        return this->size;
      }
      const T& operator[](size_t index) const
      {
            assert(index < this->size);
            return this->data[index];
      }

      T& operator[](size_t index)
      {
            assert(index < this->size);
            return this->data[index];
      }

      void PushBack(T&& value)
      {
            if(this->size >= this->capacity)
            {
                  ReAlloc(this->capacity + this->capacity/2);
            }
            this->data[this->size] = std::move(value);
            this->size++;
      }

      void PopBack()
      {
            assert(this->size > 0);
            this->size--;
            this->data[size].~T();
      }

      void Clear()
      {
            for(size_t i = 0;i<this->size;i++)
            {
                  this->data[i].~T();
            }
            this->size = 0;
      }


};
