#include "CellField.h"

CellField::CellField(int value_) {
    this->visible = true;
    this->value = value_;
    this->defaultCell = true;
}

void CellField::hide() {
    this->visible = false;
    this->value = -1;
    this->defaultCell = false;
}

bool CellField::isVisible() const {
    return this->visible;
}

void CellField::setValue(int value_) {
    this->value = value_;
    this->visible = true;
}

int CellField::getValue() const {
    return value;
}

bool CellField::isDefaultCell() const {
    return defaultCell;
}
