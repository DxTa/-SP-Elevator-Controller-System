int Motorspeed = 1;

void goUp(int *pos) {
	*pos += Motorspeed;
}

void goDown(int *pos) {
	*pos -= Motorspeed;
}


void brake() {
	Motorspeed = 0;
}

void speedUp(int val) {
	Motorspeed = val;
}
