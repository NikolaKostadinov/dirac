#pragma once

void setFalse(bool x, bool y, bool z)
{
    x = false;
    y = false;
    z = false;
}

void setX(bool x, bool y, bool z)
{
    x = true;
    y = false;
    z = false;
}

void setY(bool x, bool y, bool z)
{
    x = false;
    y = true;
    z = false;
}

void setZ(bool x, bool y, bool z)
{
    x = false;
    y = false;
    z = true;
}