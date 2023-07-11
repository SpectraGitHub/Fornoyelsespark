#ifndef __GJENSTAND_H
#define __GJENSTAND_H
#include "enum.h"

/**
 *  Gjenstand (med id, type)
 */

class Gjenstand {
    private:
        int id;
    protected:
        Type type;
    public:
        Gjenstand() {  }
        int hentID() { return id; }
        virtual void lesData();
        virtual void lagID();
        virtual void skrivData() const;
};


#endif
