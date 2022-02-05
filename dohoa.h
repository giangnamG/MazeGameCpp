// Hàm thay doi kich co cua khung cmd voi tham so truyen vao là chieu cao, chieu rong.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Hàm dich chuyen con tro den toa do x, y.
void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm lay Key tu bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => bat su kien phím Esc */ 

// Hàm tu viet
void ToMau(int x, int y, char *a, int color) // x, y là t?a d? con tr? c?n nh?y d?n d? vi?t, a là chu?i c?n truy?n vào, color là màu truy?n vào.
{
	gotoxy(x, y);
	textcolor(color);
	textcolor(7);
}
