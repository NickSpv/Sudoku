#pragma once

class CellField {
public:
    explicit CellField(int rightValue_);
    void setRealValue(int realValue_);
    void hide();
    bool isRight() const;
    bool isVisible() const;
    int getRealValue() const;
    bool isDefaultCell() const;

private:
    int rightValue;
    int realValue;
    bool visible;
    bool defaultCell;
};
