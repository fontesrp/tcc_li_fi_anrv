#ifndef encoding_8b10b_h
#define encoding_8b10b_h

#define TABLE_MAIN_INDEX_SIZE 256 // Quantity of 8-bit values
#define TABLE_SUB_INDEX_SIZE  3   // 0: rd negative; 1: rd positive; 2: update rd's signal

unsigned int searchTable[TABLE_MAIN_INDEX_SIZE][TABLE_SUB_INDEX_SIZE];
unsigned char tableInitialized = 0;
char rd;

void createSearchTable();

#endif
