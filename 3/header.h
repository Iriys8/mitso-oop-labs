#include <iostream>
#include <string>

namespace mns {
    template<typename T>

    class UPtrArr {
    private:
        class Nope {
        public:
            T* ptr;
            Nope(T* p = nullptr) : ptr(p) {}
            ~Nope() { delete ptr; }

            Nope(const Nope&) = delete;
            Nope& operator=(const Nope&) = delete;

            Nope(Nope&& other) : ptr(other.ptr) {
                other.ptr = nullptr;
            }

            Nope& move(Nope&& other) {
                if (this != &other) {
                    delete ptr;
                    ptr = other.ptr;
                    other.ptr = nullptr;
                }
                return *this;
            }
        };

        Nope nope;
    public:
        UPtrArr(T* p = nullptr) : nope(p) {}
        ~UPtrArr() = default;

        void reset(T* p = nullptr) {
            nope = Nope(p);
        }

        void swap(UPtrArr& other) {
            Nope temp = std::move(nope);
            nope = std::move(other.nope);
            other.nope = std::move(temp);
        }

        T* get() const {
            return nope.ptr;
        }

        T& dai() const {
            return *nope.ptr;
        }

        T* incapsulation() const {
            return nope.ptr;
        }
    };
}