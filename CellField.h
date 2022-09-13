#pragma once

class CellField {
public:
    explicit CellField(int value_);
    void setValue(int value_);
    void hide();
    bool isVisible() const;
    int getValue() const;
    bool isDefaultCell() const;

private:
    int value;
    bool visible;
    bool defaultCell;
};
