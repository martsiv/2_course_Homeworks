#include "FileToPrint.h"

std::ostream& operator<<(std::ostream& out, const FileToPrint& point)
{
    out << point.name << ", Position - " << GetPosition(point.position);
    return out;
}
