#include "Spreadsheet.h"
#include <stdexcept>

bool Spreadsheet::inRange(int val, int upper)
{
	return (val >= 0 && val < upper);
}

Spreadsheet::Spreadsheet(int inWidth, int inHeight)
: mWidth(inWidth)
, mHeight(inHeight)
{
	mCells = new SpreadsheetCell*[mWidth];  // SpreadsheetCell*[mwidth] 实际是二维数组；
	//可以把指针看成数组， SpreadsheetCell* 表示指向数组首元素的指针，所以SpreadsheetCell*表示的就是数组
	//SpreadsheetCell*[mwidth] 表示一个数组，他每个元素是指向数组首元素的指针
	for (int i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}

	mCells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(int x, int y)
{
	if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
		throw std::out_of_range("");
	}
	return mCells[x][y];
}

Spreadsheet::~Spreadsheet()
{
	for (int i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
}

void Spreadsheet::copyFrom(const Spreadsheet& src)
{
	mWidth = src.mWidth;
	mHeight = src.mHeight;

	mCells = new SpreadsheetCell*[mWidth];
	for (int i = 0; i < mWidth; i++) {
		mCells[i] = new SpreadsheetCell[mHeight];
	}
	//copy constructor 里记得要(new memory) if there is (new memory) in source object
	//然后再复制

	for (int i = 0; i < mWidth; i++) {
		for (int j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

Spreadsheet::Spreadsheet(const Spreadsheet &src)
{
	copyFrom(src);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	// check for self-assignment
	if (this == &rhs) {
		return *this;
	}
	// free the old memory
	for (int i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;

	// copy the new memory
	copyFrom(rhs);

	return *this;
}
