#include"Controller.h"

void Controller::start() {
	model->start();
	unsigned char val = 0;

	try {
		while (val != 27) {
			val = _getch();
			if (val == 224) {
				val = _getch();
			}
			switch (val) {
			case 80:
				model->move(DOWN);
				break;
			case 72:
				model->move(UP);
				break;
			case 77:
				model->move(RIGHT);
				break;
			case 75:
				model->move(LEFT);
				break;
			default:
				break;
			}
		}
	}
	catch (ERR_HPZero exc) { system("cls"); exc.show(); }
	catch (ERR_Exit exc) { system("cls"); exc.show(); }
	catch (ERR_Victory exc) { system("cls"); exc.show(); }
}