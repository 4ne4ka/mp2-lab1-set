// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);
static TSet FAKE_SET(1);

TSet::TSet(int mp) : BitField(mp), MaxPower(mp)
{
    if (mp < 0) {
        throw out_of_range("n > 0!");
    }
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField), MaxPower(s.MaxPower)
{
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf), MaxPower(bf.GetLength())
{
}

TSet::operator TBitField()
{
    return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    if (Elem < 0 || Elem >= MaxPower) {
        throw out_of_range("out of range");
    }
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    if (Elem < 0 || Elem >= MaxPower) {
        throw std::out_of_range("Element out of range");
    }
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if (Elem < 0 || Elem >= MaxPower) {
        throw std::out_of_range("Element out of range");
    }
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
    if (this == &s) return *this;
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return (MaxPower == s.MaxPower && BitField == s.BitField);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return !(*this == s);
}

TSet TSet::operator+(const TSet &s) // объединение
{
    int maxpwr = (MaxPower > s.MaxPower) ? MaxPower : s.MaxPower;
    TSet result(maxpwr);
    result.BitField = BitField | s.BitField;
    return result;
    
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet result(*this);
    result.InsElem(Elem);
    return result;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet result(*this);
    result.DelElem(Elem);
    return result;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    int minpwr = (MaxPower < s.MaxPower) ? MaxPower : s.MaxPower;
    TSet result(minpwr);

    if (minpwr > 0) {
        // Создаем временные битовые поля одинакового размера
        TBitField bf1(minpwr);
        TBitField bf2(minpwr);

        // Копируем биты из исходных множеств (только общую часть)
        for (int i = 0; i < minpwr; i++) {
            if (this->IsMember(i)) bf1.SetBit(i);
            if (s.IsMember(i)) bf2.SetBit(i);
        }

        // Применяем AND
        result.BitField = bf1 & bf2;
    }
    return result;
}

TSet TSet::operator~(void) // дополнение
{
    TSet result(MaxPower);
    result.BitField = ~BitField;
    for (int i = MaxPower; i < result.BitField.GetLength(); i++) {
        result.BitField.ClrBit(i);
    }
    return result;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    return ostr;
}
