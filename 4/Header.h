#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <stack>

#ifndef NOT_VERY_SMART_POINTER
#define NOT_VERY_SMART_POINTER
template<typename xto_im>
class coolerPointer { // будет unique, всё равно потом в stack пойдёт, там много указателей на одно и тоже не надо. Ну или я потом пожалею об этом
	xto_im* pointer;
public:
	explicit coolerPointer(xto_im* otherPointer = nullptr) : pointer(otherPointer) {}
	~coolerPointer() {
		delete pointer;
	}

	coolerPointer(const coolerPointer&) = delete;
	coolerPointer& operator=(const coolerPointer&) = delete;

	coolerPointer(coolerPointer&& lessCoolerPointer) noexcept : pointer(lessCoolerPointer.pointer) {
		lessCoolerPointer.pointer = nullptr;
	}

	coolerPointer& operator = (coolerPointer&& moreCoolerPointer) noexcept {
		if (this != &moreCoolerPointer) {
			delete pointer;
			pointer = moreCoolerPointer.pointer;
			moreCoolerPointer.pointer = nullptr;
		}
		return *this;
	}

	void reset(xto_im moreCoolerPointer) {
		delete pointer;
		pointer = moreCoolerPointer;
	}

	void swap(coolerPointer& anotherCoolPointer) noexcept {
		xto_im* temp = pointer;
		pointer = anotherCoolPointer.pointer;
		anotherCoolPointer.pointer = temp;
	}

	xto_im* get() {
		return pointer;
	}
	xto_im& operator*() {
		return *pointer;
	}
	xto_im* operator-> () {
		return pointer;
	}
};
#endif // !NOT_VERY_SMART_POINTER

#ifndef MAGICK_SHOOTING
#define MAGICK_SHOOTING
class magicSpellsRejector {
public:
	static void handle(const std::exception& E) { // E
		std::cerr << std::endl << "Гномик магокрад нашёл волшебный фокус! " << E.what() << std::endl;
		system("Pause");
	}
	static void nullStack() {
		std::cerr << std::endl << "Гномик магокрад заметил фокусы с пустым стеком! Он следит!";
		system("Pause");
	}
};
#endif // !MAGICK_SHOOTING

#ifndef NOT_MAGIC_AT_ALL
#define NOT_MAGIC_AT_ALL
template<typename xto_im>
class magicVector {
	coolerPointer<std::stack<std::vector<xto_im>>> thisIsVectorISwear;
public:
	magicVector() : thisIsVectorISwear(new std::stack<std::vector<xto_im>>()) {}
	magicVector(std::initializer_list<xto_im> list) {
		thisIsVectorISwear.reset(new std::stack<std::vector<xto_im>>());
		thisIsVectorISwear->push(std::vector<xto_im>(list));
	}

	magicVector& operator=(const magicVector& coolerMagickVector) {
		if (this != &coolerMagickVector) {
			thisIsVectorISwear.reset(new std::stack<xto_im>(*coolerMagickVector.thisIsVectorISwear));
		}
		return *this;
	}

	magicVector(magicVector&& lessCoolerMagickVector) noexcept : thisIsVectorISwear(std::move(lessCoolerMagickVector)) {}
	magicVector& operator=(magicVector&& lessCoolerMagickVector) noexcept {
		if (this != &lessCoolerMagickVector) {
			thisIsVectorISwear = std::move(lessCoolerMagickVector.thisIsVectorISwear);
		}
		return *this;
	}

	void pushVector(const std::vector<xto_im>& vec) {
		try {
			thisIsVectorISwear->push(vec);
		}
		catch (const std::runtime_error& e) {
			magicSpellsRejector::handle(e);
			throw;
		}
	}
	
	void popVector() {
		try {
			if (thisIsVectorISwear->empty()) {
				magicSpellsRejector::nullStack();
				throw;
			}
			return thisIsVectorISwear->pop();
		}
		catch (const std::exception& e) {
			magicSpellsRejector::handle(e);
			throw;
		}
	}

	std::vector<xto_im>& topVector() {
		try {
			if (thisIsVectorISwear->empty()) {
				magicSpellsRejector::nullStack();
				throw;
			}
			return thisIsVectorISwear->top();
		}
		catch (const std::exception& e) {
			magicSpellsRejector::handle(e);
			throw;
		}
	}
	
	bool isEmpty() const {
		return thisIsVectorISwear->empty();
	}
};
#endif // !NOT_MAGIC_AT_ALL
