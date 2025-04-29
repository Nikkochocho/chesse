#ifndef __EMPTY_H__
#define __EMPTY_H__

class Empty  {

    public:

    Empty( void );
    ~Empty( void );

    virtual void Movement( void );
    virtual bool Check( int src_row, int src_col, int dst_row, int dst_col );

    virtual void Print( void );
};

#endif // __EMPTY_H__