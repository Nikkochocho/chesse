#ifndef __PIECE_H__
#define __PIECE_H__

enum Color {
    WHITE,
    BLACK
};

class Piece  {

    protected:
    
    Color     m_color;

    public:

    Piece( Color color );

    virtual void Movement( void );
    virtual bool Check( int src_row, int src_col, int dst_row, int dst_col );

    virtual void Print( void );
};

#endif // __PIECE_H__