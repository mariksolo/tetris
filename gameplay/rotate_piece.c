#include "piece_configs.h"
#include "Piece.h"
#include "get_config.h"

void rotate_piece(struct Piece *piece)
{
    switch (piece->type)
    {
    case 's':
        if (piece->config_id == 1)
        {
            piece->config_id = 0;
        }
        else
        {
            piece->config_id++;
        }
        get_config(piece, 's', piece->config_id);
        break;
    case 'z':
        if (piece->config_id == 1)
        {
            piece->config_id = 0;
        }
        else
        {
            piece->config_id++;
        }
        get_config(piece, 'z', piece->config_id);
        break;
    case 'l':
        if (piece->config_id == 3)
        {
            piece->config_id = 0;
        }
        else
        {
            piece->config_id++;
        }
        get_config(piece, 'l', piece->config_id);
        break;
    case 'j':
        if (piece->config_id == 3)
        {
            piece->config_id = 0;
        }
        else
        {
            piece->config_id++;
        }
        get_config(piece, 'j', piece->config_id);
        break;
    case 'q':
        get_config(piece, 'q', 0);
        break;
    case 'i':
        if (piece->config_id == 1)
        {
            piece->config_id = 0;
        }
        else
        {
            piece->config_id++;
        }
        get_config(piece, 'i', piece->config_id);
        break;
    case 't':
        if (piece->config_id == 3)
        {
            piece->config_id = 0;
        }
        else
        {
            piece->config_id++;
        }
        get_config(piece, 't', piece->config_id);
        break;
    }
}