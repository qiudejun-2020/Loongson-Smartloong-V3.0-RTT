#include <rtthread.h>

rt_uint8_t line[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

/* : - / */
rt_uint8_t gap[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,\
                    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
                    0x00,0x00,0x40,0x20,0x20,0x20,0x10,0x10,0x08,0x08,0x08,0x04,0x04,0x02,0x02,0x00};

rt_uint8_t calendar[] = {0x08,0x08,0xF8,0x04,0x04,0x02,0xF8,0x08,0x08,0x08,0xFF,0x00,0x00,0x00,0x00,0x00,
                    0x00,0x00,0x3F,0x01,0x01,0x01,0x1F,0x01,0x01,0x01,0x7F,0x01,0x01,0x01,0x01,0x01,/*"年",0*/
                    0x00,0xF8,0x08,0x08,0x08,0xF8,0x08,0x08,0x08,0xF8,0x08,0x08,0x04,0x04,0x02,0x01,
                    0x00,0x1F,0x10,0x10,0x10,0x1F,0x10,0x10,0x10,0x1F,0x10,0x10,0x10,0x10,0x14,0x08,/*"月",1*/
                    0x00,0xF8,0x08,0x08,0x08,0x08,0x08,0xF8,0x08,0x08,0x08,0x08,0x08,0x08,0xF8,0x08,
                    0x00,0x0F,0x08,0x08,0x08,0x08,0x08,0x0F,0x08,0x08,0x08,0x08,0x08,0x08,0x0F,0x08,/*"日",2*/
                    0x00,0xF8,0x08,0xF8,0x08,0xF8,0x80,0x88,0xF8,0x84,0x82,0xF8,0x80,0x80,0xFE,0x00,
                    0x00,0x0F,0x08,0x0F,0x08,0x0F,0x00,0x00,0x1F,0x00,0x00,0x0F,0x00,0x00,0x3F,0x00,/*"星",3*/
                    0x44,0x44,0xFE,0x44,0x44,0x7C,0x44,0x44,0x7C,0x44,0x44,0xFF,0x20,0x44,0x82,0x41,
                    0x00,0x3E,0x22,0x22,0x22,0x3E,0x22,0x22,0x22,0x3E,0x22,0x22,0x21,0x21,0x28,0x10};/*"期",4*/


rt_uint8_t weekday[] = {0x00,0xF8,0x08,0x08,0x08,0x08,0x08,0xF8,0x08,0x08,0x08,0x08,0x08,0x08,0xF8,0x08,
                    0x00,0x0F,0x08,0x08,0x08,0x08,0x08,0x0F,0x08,0x08,0x08,0x08,0x08,0x08,0x0F,0x08,/*"日",0*/
                    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"一",1*/
                    0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,
                    0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,/*"二",2*/
                    0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,
                    0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,/*"三",3*/
                    0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0x22,0x12,0x12,0x0A,0x06,0x02,0xFE,0x02,0x00,
                    0x00,0x00,0x3F,0x22,0x22,0x22,0x22,0x22,0x22,0x3C,0x20,0x20,0x20,0x3F,0x20,0x00,/*"四",4*/
                    0x00,0xFE,0x40,0x40,0x40,0x40,0xFC,0x20,0x20,0x20,0x20,0x10,0x10,0x10,0xFF,0x00,
                    0x00,0x3F,0x00,0x00,0x00,0x00,0x0F,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x7F,0x00,/*"五",5*/
                    0x40,0x80,0x00,0x00,0x00,0xFF,0x00,0x00,0x20,0x20,0x10,0x10,0x08,0x04,0x02,0x00,
                    0x00,0x00,0x01,0x01,0x00,0x7F,0x00,0x00,0x02,0x04,0x08,0x10,0x10,0x20,0x20,0x00};/*"六",6*/

rt_uint8_t rect[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,\
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};/* rect */

rt_uint8_t ship[] ={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFC,0xFD,0x01,0x00,0x00,0x1E,0x00,
                    0x04,0x21,0x20,0x00,0x00,0x00,0x77,0x00,0x04,0x21,0x20,0x00,0x00,0x00,0x63,0x00,
                    0x04,0x21,0x20,0x00,0x00,0x78,0x3E,0x00,0xFC,0x20,0x20,0x00,0x00,0x48,0x00,0x00,
                    0x34,0x20,0x20,0x00,0xE0,0x79,0xC0,0x01,0x44,0x20,0x20,0x00,0xE0,0x01,0x40,0x0F,
                    0x84,0x20,0x20,0x00,0xF0,0x00,0x40,0x38,0x04,0x21,0x20,0x00,0x90,0x07,0x40,0x20,
                    0x00,0x00,0x00,0x00,0x90,0x05,0xC0,0x21,0x00,0x00,0x00,0xE0,0xFF,0x0F,0x40,0x2F,
                    0x00,0x00,0x00,0xFF,0x11,0x18,0x40,0x38,0xF0,0x7F,0x80,0xBF,0xCF,0x1B,0x40,0x00,
                    0x70,0x7B,0xC0,0xA1,0x4C,0x32,0x40,0x00,0xF0,0xFF,0xF3,0xA1,0xCF,0xE3,0xFF,0x00,
                    0xF0,0x7F,0xDE,0xA0,0xFF,0xCF,0xD7,0x00,0xE0,0x7B,0xFC,0xFF,0xFF,0xFF,0x7F,0x00,
                    0xE0,0x2F,0xF8,0x7F,0x3C,0x1E,0x30,0x00,0x40,0x00,0x00,0xDC,0x66,0x33,0x10,0x00,
                    0xC0,0x00,0x00,0x84,0x42,0x21,0x18,0x00,0x80,0x01,0x00,0x8C,0x42,0x31,0x08,0x00,
                    0x00,0x01,0x00,0xF8,0x7E,0x1F,0x0C,0x00,0x00,0xF3,0xFF,0xFF,0xFF,0xFF,0x07,0x00,
                    0x00,0x3E,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x07,0x00,
                    0x00,0x18,0x03,0x30,0xC0,0x00,0x07,0x38,0x60,0x90,0x07,0x78,0xF0,0x83,0x0F,0x78,
                    0xF0,0xF0,0x3D,0xDE,0x7F,0xFE,0xF8,0xFF,0xBE,0xFF,0xF3,0x3F,0xF0,0x01,0xC7,0x39,
                    0x7B,0x66,0x7E,0xFF,0x3F,0xFF,0xFF,0xFF,0xCE,0x3F,0xF8,0x01,0x07,0x00,0xE0,0xC0};

rt_uint8_t happy[] ={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x0E,
                    0x06,0x03,0x00,0x00,0x00,0x00,0x7E,0x3F,0x06,0x03,0x00,0x00,0x00,0x00,0xFE,0x3F,
                    0x06,0x03,0x00,0x00,0x00,0x00,0xEF,0x7B,0x06,0xE3,0xE3,0xC7,0xCF,0x31,0xC7,0x71,
                    0xFE,0xE3,0xE7,0xCF,0x9F,0x31,0xC7,0x71,0xFE,0x03,0x66,0xCC,0x98,0x19,0x07,0x70,
                    0x06,0xE3,0x67,0xCC,0x98,0x19,0x07,0x70,0x06,0x33,0x66,0xCC,0x18,0x1B,0x0E,0x38,
                    0x06,0x33,0x67,0xCC,0x18,0x0F,0x1E,0x38,0x06,0xF3,0xE7,0xC7,0x0F,0x0F,0x1C,0x3C,
                    0x06,0xE3,0xE6,0xC7,0x0F,0x0E,0x3C,0x1E,0x00,0x00,0x60,0xC0,0x00,0x06,0x78,0x0F,
                    0x00,0x00,0x60,0xC0,0x00,0x07,0xF0,0x07,0x00,0x00,0x60,0xC0,0xC0,0x03,0xE0,0x03,
                    0xF0,0x03,0x00,0x00,0xC0,0x01,0xC0,0x01,0xF0,0xC7,0x01,0xC6,0x00,0x30,0x00,0x00,
                    0x30,0x06,0x00,0xC6,0x00,0x30,0x00,0x00,0x30,0xC6,0x6C,0xDF,0x0F,0x3E,0x9F,0x63,
                    0xF0,0xC3,0x7C,0xDF,0x1F,0x3F,0x3F,0x63,0xF0,0xC7,0x1C,0xC6,0x98,0x31,0x30,0x33,
                    0x30,0xCC,0x0C,0xC6,0x98,0x31,0x3F,0x33,0x30,0xCC,0x0C,0xC6,0x98,0xB1,0x31,0x36,
                    0x30,0xCC,0x0C,0xC6,0x98,0xB1,0x39,0x1E,0xF0,0xC7,0x0C,0xDE,0x98,0xBF,0x3F,0x1E,
                    0xF0,0xC3,0x0C,0xDC,0x18,0x37,0x37,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,
                    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x07,
                    0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

rt_uint8_t  Bmp003[]={
0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC8,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,
0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,
0xBF,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0x08,0x00,0x00,0x00,0x00,0x00,0x00,
0xA4,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0xA4,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,
0x24,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x14,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0xC8,0x2F,0x00,0x00,0x00,0x00,0x00,0x00,
0x14,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x21,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};


rt_uint8_t zhufu[] ={0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x60,0x06,0x60,0x06,0x00,0x00,
                    0x98,0x3F,0x60,0x06,0x60,0x06,0x00,0x00,0x80,0x21,0xFE,0x7F,0xFE,0x7F,0x00,0x00,
                    0xBE,0x21,0x60,0x06,0x60,0x06,0x00,0x00,0x90,0x21,0x60,0x06,0x60,0x06,0x00,0x00,
                    0x98,0x21,0xFC,0x3F,0xFC,0x3F,0x00,0x00,0xBC,0x3F,0x04,0x20,0x04,0x20,0x00,0x00,
                    0x6E,0x0A,0xFE,0x2F,0xFE,0x2F,0x00,0x00,0x0A,0x0B,0x80,0x01,0x80,0x01,0x00,0x00,
                    0x08,0x0B,0x80,0x01,0x80,0x01,0x00,0x00,0x08,0x09,0xF8,0x1F,0xF8,0x1F,0x00,0x00,
                    0x88,0x49,0x80,0x0F,0x80,0x0F,0x00,0x00,0xC8,0xC8,0x80,0x09,0x80,0x09,0x00,0x00,
                    0x78,0x78,0xFE,0x7F,0xFE,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                    0x00,0x30,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x30,0x00,0x00,0x10,0x0C,0x00,0x30,
                    0x00,0x32,0xC0,0xFF,0x10,0x0C,0xF0,0x7F,0x00,0x33,0x40,0xC0,0x74,0x7F,0x30,0x01,
                    0x00,0xFF,0x47,0xC0,0x7C,0x6C,0x10,0x03,0x00,0x31,0x40,0xC0,0x54,0x6C,0x10,0x03,
                    0x80,0x31,0x40,0xC0,0x14,0x6C,0x10,0x03,0xC0,0x30,0xC0,0xFF,0x14,0x64,0xF8,0x7F,
                    0x00,0xFF,0x43,0xC0,0xD0,0xFF,0x00,0x03,0x00,0x30,0x40,0xC0,0x10,0x0C,0x60,0x1B,
                    0x00,0x30,0x40,0xC0,0x10,0x1E,0x20,0x33,0x00,0x30,0x40,0xC0,0x10,0x33,0x30,0x33,
                    0x00,0x30,0x40,0xC0,0x90,0x61,0x18,0x63,0xC0,0xFF,0xCF,0xFF,0xF0,0xC0,0xCC,0x43,
                    0x00,0x00,0x40,0xC0,0x50,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

rt_uint8_t kands[] ={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
                    0xE1,0x80,0x0F,0x38,0x70,0x00,0xF8,0x87,0xE1,0xC0,0x07,0xFE,0xFC,0x01,0xFE,0x87,
                    0xE1,0xE0,0x03,0xFF,0xFF,0x03,0xFF,0x87,0xE1,0xF0,0x01,0xEF,0x9F,0x83,0x0F,0x84,
                    0xE1,0xF0,0x80,0x87,0x8F,0x87,0x07,0x80,0xE1,0xF8,0x80,0x83,0x07,0x87,0x07,0x80,
                    0xE1,0x7C,0x80,0x03,0x03,0x87,0x0F,0x80,0xE1,0x3E,0x80,0x03,0x00,0x87,0x3F,0x80,
                    0xE1,0x1F,0x80,0x03,0x00,0x07,0xFF,0x80,0xE1,0x1F,0x00,0x07,0x80,0x07,0xFE,0x83,
                    0xE1,0x1F,0x00,0x07,0x80,0x03,0xF8,0x87,0xE1,0x3E,0x00,0x0F,0xC0,0x03,0xE0,0x87,
                    0xE1,0x7C,0x00,0x0E,0xC0,0x01,0x80,0x8F,0xE1,0xFC,0x00,0x1E,0xE0,0x01,0x00,0x8F,
                    0xE1,0xF8,0x01,0x3C,0xF0,0x00,0x00,0x8F,0xE1,0xF0,0x01,0x78,0x78,0x80,0x00,0x8F,
                    0xE1,0xE0,0x03,0xF0,0x3D,0x80,0x83,0x8F,0xE1,0xC0,0x07,0xE0,0x1F,0x80,0xFF,0x87,
                    0xE1,0xC0,0x0F,0xC0,0x0F,0x80,0xFF,0x83,0xE1,0x80,0x1F,0x00,0x03,0x00,0xFF,0x80,
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
                    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

rt_uint8_t zhongqiu[] ={0x80,0x80,0x80,0x80,0xFC,0x84,0x84,0x84,0x84,0x84,0xFC,0x84,0x80,0x80,0x80,0x80,
                    0x00,0x00,0x00,0x00,0x1F,0x10,0x10,0x10,0x10,0x10,0x1F,0x10,0x00,0x00,0x00,0x00,/*"中",0*/
                    0x10,0x38,0x0F,0x08,0x88,0xBF,0x88,0x4C,0x1C,0x2A,0x2A,0x09,0x88,0x88,0x48,0x28,
                    0x02,0x02,0x02,0x02,0x22,0x22,0x12,0x0A,0x02,0x05,0x05,0x09,0x08,0x10,0x20,0x40,/*"秋",1*/
                    0x08,0x08,0x08,0xC8,0x18,0x2A,0x0A,0x0A,0xE9,0x08,0x08,0x08,0x88,0x88,0x48,0x28,
                    0x02,0x02,0x02,0x1F,0x12,0x12,0x12,0x12,0x7F,0x02,0x05,0x05,0x08,0x08,0x10,0x60,/*"快",2*/
                    0x00,0x00,0xF8,0x08,0x88,0x84,0x84,0xFC,0x80,0x90,0x90,0x88,0x84,0x82,0xA0,0x40,
                    0x04,0x0F,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x04,0x08,0x10,0x20,0x20,0x00,0x00};/*"乐",3*/


/* 0~9 */
rt_uint8_t num[] = {0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00,\
                    0x00,0x00,0x00,0x10,0x1C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,\
                    0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x40,0x20,0x10,0x08,0x04,0x42,0x7E,0x00,0x00,\
                    0x00,0x00,0x00,0x3C,0x42,0x42,0x40,0x20,0x18,0x20,0x40,0x42,0x42,0x3C,0x00,0x00,\
                    0x00,0x00,0x00,0x20,0x30,0x30,0x28,0x24,0x24,0x22,0xFE,0x20,0x20,0xF8,0x00,0x00,\
                    0x00,0x00,0x00,0x7E,0x02,0x02,0x02,0x1E,0x22,0x40,0x40,0x42,0x22,0x1C,0x00,0x00,\
                    0x00,0x00,0x00,0x18,0x24,0x02,0x02,0x3A,0x46,0x42,0x42,0x42,0x44,0x38,0x00,0x00,\
                    0x00,0x00,0x00,0x7E,0x42,0x20,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x00,0x00,\
                    0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00,\
                    0x00,0x00,0x00,0x1C,0x22,0x42,0x42,0x42,0x62,0x5C,0x40,0x40,0x24,0x18,0x00,0x00};


rt_uint8_t solid[] = {
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
};

 rt_uint8_t loongson[]=
{
/*------------------------------------------------------------------------------
;  源文件 / 文字 : 开源创客 横向取模 字节倒序
;  宽×高（像素）: 64×16
------------------------------------------------------------------------------*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x80,0xFD,0x07,0x83,0x01,0x03,0x00,0xFC,0x0F,0xCF,0x80,0x87,0xF9,0x7F,0x00,
0x30,0x03,0x6C,0xC0,0xEC,0xD9,0x60,0x00,0x30,0x03,0xFC,0x63,0xF8,0xC1,0x1F,0x00,
0x30,0x83,0x3D,0xC3,0xEF,0x61,0x18,0x00,0x30,0x03,0xFF,0xC3,0xEC,0xF1,0x0C,0x00,
0xFE,0x1F,0x3C,0xC3,0xEC,0x81,0x07,0x00,0x30,0x03,0xFC,0xC3,0xEC,0xF9,0x7C,0x00,
0x30,0x03,0xCC,0xC0,0xE7,0xE1,0x1F,0x00,0x18,0x03,0xFF,0xC3,0x98,0x61,0x18,0x00,
0x18,0x83,0xDD,0xC6,0x98,0xE1,0x1F,0x00,0x0C,0x03,0xE6,0x80,0xDF,0x61,0x18,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*------------------------------------------------------------------------------
;  源文件 / 文字 : 龙众创芯
;  宽×高（像素）: 64×16
------------------------------------------------------------------------------*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x06,0x60,0x00,0x06,0x83,0x19,0x00,
0xC0,0x0C,0x60,0x00,0x0F,0x83,0x19,0x00,0xC0,0x00,0xF0,0x80,0xD9,0xF3,0xFF,0x00,
0xFC,0x3F,0x98,0xC1,0xF0,0x83,0x19,0x00,0xC0,0x03,0x0C,0x83,0xDF,0x03,0x00,0x00,
0x60,0x03,0x07,0x8E,0xD9,0x03,0x06,0x00,0x60,0x1B,0x98,0x81,0xD9,0x83,0x0D,0x00,
0x60,0x0F,0x98,0x81,0xD9,0xE3,0x6D,0x00,0x30,0x07,0x98,0x81,0xCF,0xE3,0xC1,0x00,
0x30,0x33,0xFC,0x83,0x31,0xE3,0xF1,0x00,0x98,0x33,0x66,0x86,0x31,0xB3,0xF1,0x00,
0xCC,0x3E,0x33,0x0C,0xBF,0x03,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

rt_uint8_t zhilongzhuban[]={
/*智龙主板*/
/*------------------------------------------------------------------------------
;  源文件 / 文字 : 智龙主板
;  宽×高（像素）: 64×16
------------------------------------------------------------------------------*/
0x0C,0x00,0xC0,0x00,0xC0,0x00,0x18,0x00,0xFC,0x3F,0xC0,0x06,0x80,0x01,0x18,0x78,
0x36,0x33,0xC0,0x0C,0xFC,0x3F,0xD8,0x0F,0x30,0x33,0xC0,0x00,0x80,0x01,0xFE,0x00,
0xFE,0x33,0xFE,0x7F,0x80,0x01,0xD8,0x00,0x78,0x33,0xC0,0x03,0x80,0x01,0xD8,0x3F,
0xCC,0x3F,0x60,0x33,0x80,0x01,0xFC,0x33,0x06,0x00,0x60,0x1B,0xF8,0x1F,0xFC,0x33,
0xF8,0x1F,0x60,0x0F,0x80,0x01,0xDE,0x33,0x18,0x18,0x30,0x07,0x80,0x01,0xD8,0x1E,
0xF8,0x1F,0x30,0x03,0x80,0x01,0xD8,0x1E,0x18,0x18,0x98,0x63,0x80,0x01,0x78,0x0C,
0xF8,0x1F,0xEC,0x63,0x80,0x01,0x78,0x1E,0x18,0x18,0x06,0x7E,0xFE,0x7F,0xB8,0x73,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*------------------------------------------------------------------------------
;  源文件 / 文字 : 开源创客
;  宽×高（像素）: 64×16
------------------------------------------------------------------------------*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x80,0xFD,0x07,0x83,0x01,0x03,0x00,0xFC,0x0F,0xCF,0x80,0x87,0xF9,0x7F,0x00,
0x30,0x03,0x6C,0xC0,0xEC,0xD9,0x60,0x00,0x30,0x03,0xFC,0x63,0xF8,0xC1,0x1F,0x00,
0x30,0x83,0x3D,0xC3,0xEF,0x61,0x18,0x00,0x30,0x03,0xFF,0xC3,0xEC,0xF1,0x0C,0x00,
0xFE,0x1F,0x3C,0xC3,0xEC,0x81,0x07,0x00,0x30,0x03,0xFC,0xC3,0xEC,0xF9,0x7C,0x00,
0x30,0x03,0xCC,0xC0,0xE7,0xE1,0x1F,0x00,0x18,0x03,0xFF,0xC3,0x98,0x61,0x18,0x00,
0x18,0x83,0xDD,0xC6,0x98,0xE1,0x1F,0x00,0x0C,0x03,0xE6,0x80,0xDF,0x61,0x18,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

rt_uint8_t zhilongshiyan[]={
/*智龙嵌入式实验箱*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x80,0x00,0x80,0x00,0x10,0x00,
0xF0,0x7D,0x80,0x04,0x84,0x10,0x20,0x00,0x48,0x44,0x80,0x08,0x84,0x10,0x20,0x00,
0x40,0x44,0x80,0x00,0xFC,0x1F,0x40,0x00,0xF8,0x47,0xFC,0x7F,0x00,0x02,0x40,0x00,
0xA0,0x44,0x80,0x02,0x24,0x02,0xA0,0x00,0x10,0x7D,0x40,0x22,0x7E,0x3E,0xA0,0x00,
0x08,0x00,0x40,0x12,0x24,0x21,0x10,0x01,0xE0,0x3F,0x40,0x0A,0xA4,0x14,0x10,0x01,
0x20,0x20,0x20,0x06,0x3C,0x04,0x08,0x02,0xE0,0x3F,0x20,0x02,0x24,0x0A,0x08,0x02,
0x20,0x20,0x10,0x43,0x24,0x0A,0x04,0x04,0xE0,0x3F,0xC8,0x42,0x3C,0x11,0x02,0x08,
0x20,0x20,0x04,0x7C,0xA4,0x20,0x01,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x28,0x80,0x00,0x00,0x02,0x04,0x01,
0x00,0x48,0x00,0x01,0x0E,0x02,0x3C,0x1F,0x00,0x08,0xFC,0x7F,0x08,0x05,0x8A,0x04,
0xF8,0xFF,0x04,0x40,0x88,0x08,0x51,0x08,0x00,0x08,0x40,0x04,0x4A,0x10,0x08,0x00,
0x00,0x08,0x80,0x04,0xAA,0x2F,0x88,0x0F,0xF0,0x09,0x10,0x04,0x0A,0x00,0xBF,0x08,
0x40,0x08,0x20,0x04,0x1E,0x11,0x88,0x08,0x40,0x08,0x00,0x02,0x10,0x12,0x8C,0x0F,
0x40,0x10,0xFC,0x7F,0x58,0x12,0x9C,0x08,0x40,0x90,0x00,0x05,0x96,0x08,0xAA,0x0F,
0xC0,0xA3,0x80,0x08,0x90,0x08,0x89,0x08,0x78,0xC0,0x60,0x10,0x10,0x04,0x88,0x08,
0x00,0x80,0x18,0x20,0xEC,0x3F,0x88,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

};

rt_uint8_t loongsonzhongke[] = { 
/*龙芯 俱乐部*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xC0,0x0C,0x00,0x00,
0x00,0x00,0x60,0x06,0x60,0x0C,0x00,0x00,0x00,0x00,0x60,0x0C,0xFE,0x7F,0x00,0x00,
0x00,0x00,0xFF,0x3F,0x60,0x06,0x00,0x00,0x00,0x00,0xB0,0x01,0x30,0x06,0x00,0x00,
0x00,0x00,0xF0,0x0C,0x60,0x00,0x00,0x00,0x00,0x00,0xD8,0x06,0xD8,0x00,0x00,0x00,
0x00,0x00,0xD8,0x03,0xCC,0x00,0x00,0x00,0x00,0x00,0xEC,0x01,0x0F,0x0C,0x00,0x00,
0x00,0x00,0xE6,0x80,0x0D,0x18,0x00,0x00,0x00,0x00,0x73,0xC0,0x07,0x1B,0x00,0x00,
0x00,0x80,0x3D,0x06,0x06,0x03,0x00,0x00,0x00,0xC0,0x36,0x06,0xFE,0x03,0x00,0x00,
0x00,0x60,0xF0,0x07,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x0C,0x00,0x00,0x06,0x18,0x00,0x00,0x00,0xFC,0x0F,0x80,0x0F,0x30,0xFC,0x00,
0x00,0x3C,0x0C,0xFC,0x00,0xFE,0xCF,0x00,0x00,0x36,0x0C,0x0C,0x00,0x00,0x6C,0x00,
0x00,0xF6,0x0F,0xCC,0x00,0x8C,0x6D,0x00,0x00,0x37,0x0C,0xC6,0x00,0xD8,0x3C,0x00,
0x00,0xF7,0x0F,0xC6,0x00,0xFF,0x6F,0x00,0x80,0x37,0x0C,0xFE,0x3F,0x00,0x6C,0x00,
0xC0,0xF6,0x0F,0xC0,0x00,0x00,0xCC,0x00,0x00,0x36,0x0C,0xD8,0x06,0xFC,0xCD,0x00,
0x00,0x36,0x0C,0xD8,0x0C,0x8C,0xCD,0x00,0x00,0xFE,0x3F,0xCC,0x18,0x8C,0x7D,0x00,
0x00,0x06,0x00,0xC6,0x30,0x8C,0x3D,0x00,0x00,0x66,0x06,0xC3,0x30,0xFC,0x0D,0x00,
0x00,0x36,0x0C,0xF0,0x00,0x8C,0x0D,0x00,0x00,0x1E,0x18,0x60,0x00,0x00,0x0C,0x00,
};

rt_uint8_t rttzi[] = {
    /*rtt 物联网系统*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0xC0,0x37,0x00,0x00,0x00,0x30,
0x22,0x15,0x40,0x25,0x00,0x00,0x00,0x20,0x22,0x04,0x00,0x21,0x00,0x00,0x00,0x20,
0x1E,0x04,0x00,0xA1,0xB1,0x71,0x38,0x3C,0x0A,0xC4,0x0F,0x61,0x62,0x88,0x44,0x22,
0x12,0x04,0x00,0x21,0x22,0xF8,0x70,0x22,0x12,0x04,0x00,0x21,0x22,0x08,0x48,0x22,
0x22,0x04,0x00,0x21,0x22,0x88,0x44,0x22,0x67,0x0E,0x80,0x73,0xF7,0x70,0xF8,0x7C,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x24,0x00,0x44,0xFC,0x1F,0xE0,0x41,0x08,
0x24,0xE0,0x2B,0x04,0x10,0x1F,0x40,0x10,0xE5,0x47,0x01,0x04,0x10,0x08,0x20,0x7E,
0x5F,0x45,0x7D,0x8C,0x18,0x84,0x90,0x08,0x45,0xC5,0x11,0x54,0x15,0x7E,0x70,0x24,
0x44,0x45,0x11,0x24,0x12,0x30,0x40,0x42,0x2C,0xC5,0xFF,0x24,0x12,0x0C,0x21,0x7E,
0xA7,0x44,0x11,0x54,0x15,0xFF,0xF3,0x54,0x94,0x44,0x2B,0x8C,0x18,0x10,0x02,0x14,
0x44,0xE4,0x29,0x04,0x10,0x92,0xC0,0x14,0x24,0x04,0x45,0x04,0x10,0x11,0x31,0x52,
0x14,0x03,0x83,0x04,0x9C,0x18,0x02,0x61,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
rt_uint8_t loongdiannao[] = {
/*龙芯开发者 电脑*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xB0,0x01,0x33,0x00,0x00,0xD8,0x00,0x06,0x30,0x03,0x33,0xF8,0x9F,0x99,0x01,0x66,
0x30,0xE0,0xFF,0x61,0x86,0x19,0xE0,0x3F,0xFF,0x0F,0x33,0x60,0x86,0xFF,0x07,0x1E,
0xF0,0x00,0x00,0x60,0x06,0x0C,0xF0,0xFF,0xD8,0x00,0x0C,0x60,0x06,0x0C,0x00,0x03,
0xD8,0x06,0x1B,0xFC,0x3F,0xFC,0xC1,0x7F,0xD8,0xC3,0xDB,0x60,0x06,0x9E,0xF1,0x60,
0xCC,0xC1,0x83,0x61,0x06,0xF6,0xC0,0x7F,0xCC,0xCC,0xE3,0x31,0x06,0x63,0xC0,0x60,
0xE6,0x6C,0xE3,0x31,0x86,0xF9,0xC1,0x7F,0xB3,0x0F,0x7E,0x18,0x06,0x0E,0xC7,0x60,
0x64,0x21,0x11,0x02,0x01,0x01,0xD8,0x00,0x02,0x3E,0xE0,0x83,0x00,0x01,0x07,0x07,
0x00,0x00,0x03,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x03,0x00,0xF0,0x61,0x00,0x00,
0x00,0x00,0x03,0x00,0xB0,0x61,0x00,0x00,0x00,0xF8,0x7F,0x00,0xB0,0xFF,0x07,0x00,
0x00,0x18,0x63,0x00,0xB0,0x01,0x00,0x00,0x00,0x18,0x63,0x00,0xF0,0x01,0x00,0x00,
0x00,0x18,0x63,0x00,0xB0,0xD9,0x00,0x00,0x00,0xF8,0x7F,0x00,0xB0,0xF7,0x03,0x00,
0x00,0x18,0x63,0x00,0xB0,0x67,0x03,0x00,0x00,0x18,0x63,0x00,0xF0,0x67,0x03,0x00,
0x00,0x18,0x63,0x00,0xB0,0xF7,0x03,0x00,0x00,0xF8,0x7F,0x00,0xB0,0xDF,0x03,0x00,
0x00,0x18,0xE3,0x01,0xB0,0x07,0x03,0x00,0x00,0x00,0x83,0x01,0xB0,0x07,0x03,0x00,
0x00,0x00,0x83,0x01,0xB0,0xFF,0x03,0x00,0x00,0x00,0xFE,0x01,0xD8,0x01,0x03,0x00,
};

rt_uint8_t loongpi[] = {
/*龙芯派二代*/
0x00,0x18,0x03,0x18,0x06,0x00,0x30,0x00,0x00,0x18,0x06,0x18,0x06,0x0C,0x7C,0x00,
0x00,0x18,0x86,0xFF,0x7F,0xF8,0x07,0x00,0x00,0x18,0x00,0x18,0x06,0x78,0x00,0x00,
0xC0,0xFF,0x3F,0x18,0x06,0x63,0x78,0x00,0x00,0xD8,0x00,0x60,0x00,0xE6,0x0F,0x00,
0x00,0xD8,0x0C,0xC0,0x00,0xE6,0x0D,0x00,0x00,0xD8,0x0C,0x80,0x01,0xF8,0xCD,0x00,
0x00,0xD8,0x06,0x30,0x18,0xF8,0x6D,0x00,0x00,0xCC,0x03,0x36,0x30,0xEC,0x3D,0x00,
0x00,0xCC,0x01,0x36,0x60,0xEF,0x19,0x00,0x00,0xC6,0x30,0x33,0x60,0xEC,0x19,0x00,
0x00,0xE6,0xB0,0x31,0x0C,0xEC,0x31,0x00,0x00,0xF3,0x30,0x30,0x0C,0xBC,0x67,0x00,
0x80,0x99,0x3F,0xE0,0x0F,0xBC,0xC3,0x00,0xC0,0x00,0x00,0x00,0x00,0x98,0x01,0x00,
0x00,0x00,0x00,0x00,0x80,0xD9,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x99,0x01,0x00,
0x00,0x00,0x00,0x00,0x80,0x99,0x01,0x00,0x00,0xF8,0x7F,0x00,0xC0,0x18,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0xF8,0x07,0x00,0x00,0x00,0x00,0x00,0xE0,0x3F,0x00,0x00,
0x00,0x00,0x00,0x00,0xE0,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x30,0x00,0x00,
0x00,0x00,0x00,0x00,0xD8,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x30,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x60,0x06,0x00,
0x00,0xFE,0xFF,0x01,0xC0,0xC0,0x06,0x00,0x00,0x00,0x00,0x00,0xC0,0x80,0x07,0x00,
0x00,0x00,0x00,0x00,0xC0,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x06,0x00,
};;