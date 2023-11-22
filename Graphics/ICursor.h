#ifndef ICURSOR_H
#define ICURSOR_H

class ICursor
{
public:
    enum SystemCursor
    {
        Arrow,
        Ibeam,
        Crosshair,
        Hand,
        HorizontalResize,
        VerticalResize
    };

private:
    ICursor() = default;
    virtual ~ICursor() = default;
};

#endif //ICURSOR_H
