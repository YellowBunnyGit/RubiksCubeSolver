#include <iostream>
#include <random>

#define mgoto(x) {std::cout << #x << std::endl; goto x;}

class Cube {
public:
	enum class Color {
		WHITE,
		RED,
		BLUE,
		ORANGE,
		GREEN,
		YELLOW
	};
	
	friend std::ostream &operator<< (std::ostream &stream, const Color &color) {
		char c = '?';
        switch (color) {
		case Color::WHITE:
			c = 'W';
			break;
		case Color::RED:
			c = 'R';
			break;
		case Color::BLUE:
			c = 'B';
			break;
		case Color::ORANGE:
			c = 'O';
			break;
		case Color::GREEN:
			c = 'G';
			break;
		case Color::YELLOW:
			c = 'Y';
			break;
		}
		return stream << c;
    }
	
private:
	Color U, F, R, B, L, D, UF, UR, UB, UL, FU, FR, FL, FD, RU, RF, RB, RD, BU, BR, BL, BD, LU, LF, LB, LD, DF, DR, DB, DL, UFR, UFL, UBR, UBL, FUR, FUL, FDR, FDL, RUF, RUB, RDF, RDB, BUR, BUL, BDR, BDL, LUF, LUB, LDF, LDB, DFR, DFL, DBR, DBL;
	
	constexpr static void cycle(Color &a, Color &b, Color &c, Color &d) {
		Color temp = d;
		d = c;
		c = b;
		b = a;
		a = temp;
	}
	
public:
	constexpr Cube &reset(void) noexcept {
		U = Color::WHITE;
		F = Color::RED;
		R = Color::BLUE;
		B = Color::ORANGE;
		L = Color::GREEN;
		D = Color::YELLOW;
		UF = Color::WHITE;
		UR = Color::WHITE;
		UB = Color::WHITE;
		UL = Color::WHITE;
		FU = Color::RED;
		FR = Color::RED;
		FL = Color::RED;
		FD = Color::RED;
		RU = Color::BLUE;
		RF = Color::BLUE;
		RB = Color::BLUE;
		RD = Color::BLUE;
		BU = Color::ORANGE;
		BR = Color::ORANGE;
		BL = Color::ORANGE;
		BD = Color::ORANGE;
		LU = Color::GREEN;
		LF = Color::GREEN;
		LB = Color::GREEN;
		LD = Color::GREEN;
		DF = Color::YELLOW;
		DR = Color::YELLOW;
		DB = Color::YELLOW;
		DL = Color::YELLOW;
		UFR = Color::WHITE;
		UFL = Color::WHITE;
		UBR = Color::WHITE;
		UBL = Color::WHITE;
		FUR = Color::RED;
		FUL = Color::RED;
		FDR = Color::RED;
		FDL = Color::RED;
		RUF = Color::BLUE;
		RUB = Color::BLUE;
		RDF = Color::BLUE;
		RDB = Color::BLUE;
		BUR = Color::ORANGE;
		BUL = Color::ORANGE;
		BDR = Color::ORANGE;
		BDL = Color::ORANGE;
		LUF = Color::GREEN;
		LUB = Color::GREEN;
		LDF = Color::GREEN;
		LDB = Color::GREEN;
		DFR = Color::YELLOW;
		DFL = Color::YELLOW;
		DBR = Color::YELLOW;
		DBL = Color::YELLOW;
		return *this;
	}
	
	constexpr Cube(void) noexcept:
		U{Color::WHITE}, F{Color::RED}, R{Color::BLUE}, B{Color::ORANGE}, L{Color::GREEN}, D{Color::YELLOW},
		UF{Color::WHITE}, UR{Color::WHITE}, UB{Color::WHITE}, UL{Color::WHITE},
		FU{Color::RED}, FR{Color::RED}, FL{Color::RED}, FD{Color::RED},
		RU{Color::BLUE}, RF{Color::BLUE}, RB{Color::BLUE}, RD{Color::BLUE},
		BU{Color::ORANGE}, BR{Color::ORANGE}, BL{Color::ORANGE}, BD{Color::ORANGE},
		LU{Color::GREEN}, LF{Color::GREEN}, LB{Color::GREEN}, LD{Color::GREEN},
		DF{Color::YELLOW}, DR{Color::YELLOW}, DB{Color::YELLOW}, DL{Color::YELLOW},
		UFR{Color::WHITE}, UFL{Color::WHITE}, UBR{Color::WHITE}, UBL{Color::WHITE},
		FUR{Color::RED}, FUL{Color::RED}, FDR{Color::RED}, FDL{Color::RED},
		RUF{Color::BLUE}, RUB{Color::BLUE}, RDF{Color::BLUE}, RDB{Color::BLUE},
		BUR{Color::ORANGE}, BUL{Color::ORANGE}, BDR{Color::ORANGE}, BDL{Color::ORANGE},
		LUF{Color::GREEN}, LUB{Color::GREEN}, LDF{Color::GREEN}, LDB{Color::GREEN},
		DFR{Color::YELLOW}, DFL{Color::YELLOW}, DBR{Color::YELLOW}, DBL{Color::YELLOW} {}
	
	Cube const &print(void) const {
		std::cout << "    " << UBL << UB << UBR << "\n    " << UL << U << UR << "\n    " << UFL << UF << UFR << '\n' << LUB << LU << LUF << ' ' << FUL << FU << FUR << ' ' <<  RUF << RU << RUB << ' ' << BUR << BU << BUL << '\n' << LB << L << LF << ' ' <<  FL << F << FR << ' ' <<  RF << R << RB << ' ' << BR << B << BL << '\n' << LDB << LD << LDF << ' ' <<  FDL << FD << FDR << ' ' <<  RDF << RD << RDB << ' ' << BDR << BD << BDL << '\n' << "    " << DFL << DF << DFR << "\n    " << DL << D << DR << "\n    " << DBL << DF << DBR << "\n\n";
		return *this;
	}
	
	constexpr Cube &move_U(void) noexcept {
		cycle(UBL, UBR, UFR, UFL);
		cycle(UB, UR, UF, UL);
		cycle(BUL, RUB, FUR, LUF);
		cycle(BU, RU, FU, LU);
		cycle(BUR, RUF, FUL, LUB);
		return *this;
	}
	
	constexpr Cube &move_R(void) noexcept {
		cycle(RUF, RUB, RDB, RDF);
		cycle(RU, RB, RD, RF);
		cycle(UFR, BUR, DBR, FDR);
		cycle(UR, BR, DR, FR);
		cycle(UBR, BDR, DFR, FUR);
		return *this;
	}
	
	constexpr Cube &move_D(void) noexcept {
		cycle(DBL, DFL, DFR, DBR);
		cycle(DB, DL, DF, DR);
		cycle(BDL, LDF, FDR, RDB);
		cycle(BD, LD, FD, RD);
		cycle(BDR, LDB, FDL, RDF);
		return *this;
	}
	
	constexpr Cube &move_Y(void) noexcept {
		cycle(UBL, UBR, UFR, UFL);
		cycle(UB, UR, UF, UL);
		cycle(BUL, RUB, FUR, LUF);
		cycle(BU, RU, FU, LU);
		cycle(BUR, RUF, FUL, LUB);
		cycle(BL, RB, FR, LF);
		cycle(B, R, F, L);
		cycle(BR, RF, FL, LB);
		cycle(DBL, DBR, DFR, DFL);
		cycle(DB, DR, DF, DL);
		cycle(BDL, RDB, FDR, LDF);
		cycle(BD, RD, FD, LD);
		cycle(BDR, RDF, FDL, LDB);
		return *this;
	}
	
	constexpr Cube &move_YP(void) noexcept {
		move_Y();
		move_Y();
		move_Y();
		return *this;
	}
	
	constexpr Cube &move_B(void) noexcept {
		move_Y();
		move_R();
		move_YP();
		return *this;
	}
	
	constexpr Cube &move_L(void) noexcept {
		move_Y();
		move_Y();
		move_R();
		move_Y();
		move_Y();
		return *this;
	}
	
	constexpr Cube &move_F(void) noexcept {
		move_YP();
		move_R();
		move_Y();
		return *this;
	}
	
	Cube &scramble(void) {
		static std::random_device dev;
		static std::mt19937 rng(dev());
		static std::uniform_int_distribution<std::mt19937::result_type> dist6(0u, 5u);
		for (size_t i = 0u; i < 42u; ++i) {
			switch(dist6(rng)) {
			case 0u:
				move_U();
				break;
			case 1u:
				move_F();
				break;
			case 2u:
				move_R();
				break;
			case 3u:
				move_B();
				break;
			case 4u:
				move_L();
				break;
			case 5u:
				move_D();
				break;
			default:
				std::cout << "ERROR";
				exit(0);
			}
		}
		return *this;
	}
	
	Cube &solve(void) {
	L1_Y:
		move_Y();
	L1:
		if (UF == D) goto L1_1;
		if (LF == D) goto L1_F;
		if (DF == D) goto L1_F;
		if (RF == D) goto L1_F;
		if (FD == D) goto L1_F;
		if (FU == D) goto L1_F;
		goto L1_U;
	L1_F:
		move_F();
	L1_U:
		move_U();
		move_YP();
		goto L1;
	L1_1:
		if (UR == D) goto L1_2;
		goto L1_Y;
	L1_2:
		if (UB == D) goto L1_3;
		goto L1_Y;
	L1_3:
		if (UL == D) mgoto(L2);
		goto L1_Y;
	L2:
		if (FU == F) goto L2_1;
		move_U();
		move_YP();
		goto L2;
	L2_1:
		move_F();
		move_F();
		move_YP();
		if (UF == D) goto L2;
	L3_Y:
		move_Y();
	L3:
		if (DFR == D) goto L3_2;
		if (FDR == D) goto L3_1;
		if (RDF == D) goto L3_1;
		move_R();
		move_U();
		move_R();
		move_R();
		move_R();
		move_U();
		goto L3;
	L3_1:
		if (DFR == D) goto L3_2;
		move_R();
		move_U();
		move_R();
		move_R();
		move_R();
		move_U();
		move_U();
		move_U();
		goto L3_1;
	L3_2:
		if (DBR == D) goto L3_3;
		goto L3_Y;
	L3_3:
		if (DBL == D) goto L3_4;
		goto L3_Y;
	L3_4:
		if (DFL == D) goto L4;
		goto L3_Y;
	L4_Y:
		move_Y();
	L4:
		if (FDR == F) goto L4_11;
	L4_1:
		move_R();
		move_U();
		move_R();
		move_R();
		move_R();
		if (DFR == D) goto L4;
	L4_2:
		if (UFL == L) goto L4_3;
		move_U();
		move_YP();
		goto L4_2;
	L4_3:
		move_L();
		move_L();
		move_L();
		move_U();
		move_U();
		move_U();
		move_L();
	L4_4:
		move_U();
		move_YP();
		if (DFR == D) goto L4_4;
		goto L4_1;
	L4_11:
		if (RDB == R) goto L4_12;
		goto L4_Y;
	L4_12:
		if (BDL == B) goto L5;
		goto L4_Y;
	L5:
		if (FR == U) goto L5_11;
		if (RF == U) goto L5_11;
	L5_1:
		if (LU == U) goto L5_2;
		if (UL == U) goto L5_2;
		move_U();
		goto L5_1;
	L5_2:
		move_U();
		move_F();
		move_F();
		move_F();
		move_U();
		move_F();
		move_U();
		move_R();
		move_U();
		move_U();
		move_U();
		move_R();
		move_R();
		move_R();
	L5_4:
		if (FR == U) goto L5_5;
		if (RF == U) goto L5_5;
		if (FR == F) goto L5_6;
		goto L5_2;
	L5_5:
		if (FD == F) goto L5;
	L5_6:
		if (RF == R) goto L6_0;
		goto L5_2;
	L5_11:
		if (RB == U) goto L5_12;
		if (BR == U) goto L5_12;
		goto L5_Y;
	L5_12:
		if (BL == U) goto L5_13;
		if (LB == U) goto L5_13;
		goto L5_Y;
	L5_13:
		if (LF == U) goto L6;
		if (FL == U) goto L6;
	L5_Y:
		move_Y();
		goto L5;
	L6:
		move_D();
	L6_0:
		move_Y();
		if (FR == F) goto L6_8;
	L6_1:
		if (UL == F) goto L6_3;
		if (LU == F) goto L6_2;
		goto L6_4;
	L6_2:
		if (UL == R) goto L5_2;
	L6_3:
		if (LU == R) goto L5_2;
	L6_4:
		move_U();
		goto L6_1;
	L6_8:
		if (RF == R) goto L6_9;
		goto L6_1;
	L6_9:
		move_D();
		move_D();
		move_D();
	L7:
		if (UL == U) goto L7_1;
		goto L7_3;
	L7_1:
		if (UF == U) goto L7_2;
		goto L7_4;
	L7_2:
		if (UR == U) goto L8;
	L7_3:
		move_Y();
	L7_4:
		move_F();
		move_R();
		move_U();
		move_R();
		move_R();
		move_R();
		move_U();
		move_U();
		move_U();
	L7_5:
		move_F();
		if (DF == D) goto L7;
		goto L7_5;
	L8:
		if (FU == F) goto L8_1;
		move_U();
		goto L8;
	L8_1:
		if (RU == R) goto L8_3;
		move_R();
		move_U();
		move_R();
		move_R();
		move_R();
		move_U();
		move_R();
		move_U();
		move_U();
	L8_2:
		move_R();
		if (DR == D) goto L8_1;
		goto L8_2;
	L8_3:
		if (BU == B) goto L9;
		move_YP();
		goto L8;
	L9:
		if (UFR == U) goto L9_1;
		move_D();
		move_F();
		move_D();
		move_D();
		move_D();
	L10_4:
		move_F();
		move_F();
		move_F();
		goto L9;
	L9_1:
		if (UBR == U) goto L9_2;
		goto L9_5;
	L9_2:
		if (UBL == U) goto L9_3;
		goto L9_5;
	L9_3:
		if (UFL == U) goto L9_4;
		goto L9_5;
	L9_4:
		if (FU == F) goto L10;
	L9_5:
		move_U();
		goto L9;
	L10:
		if (BUL == B) goto L10_2;
		if (LUF == L) goto L10_1;
		if (FUR == F) goto L10_1;
		if (RUB == R) goto L10_1;
		goto L10_3;
	L10_1:
		move_Y();
		goto L10;
	L10_2:
		if (LUF == L) goto L_EXIT;
	L10_3:
		move_U();
		move_U();
		move_U();
		move_B();
		move_B();
		move_B();
		move_U();
		move_F();
		move_U();
		move_U();
		move_U();
		move_B();
		move_U();
		goto L10_4;
	L_EXIT:
		
		return *this;
	}
};

int main() {
	Cube cube;
	cube.scramble();
	cube.print();
	cube.solve();
	cube.print();
}