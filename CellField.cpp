#include "CellField.h"

CellField::CellField(int rightValue_) {
    this->rightValue = rightValue_;
    this->visible = true;
    this->realValue = rightValue_;
    this->defaultCell = true;
}

void CellField::hide() {
    this->visible = false;
    this->realValue = -1;
    this->defaultCell = false;
}

bool CellField::isRight() const {
    return this->rightValue == this->realValue;
}

bool CellField::isVisible() const {
    return this->visible;
}

void CellField::setRealValue(int realValue_) {
    this->realValue = realValue_;
    this->visible = true;
}

int CellField::getRealValue() const {
    return realValue;
}

bool CellField::isDefaultCell() const {
    return defaultCell;
}
