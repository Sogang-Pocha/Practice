using lint = long long;

//find ax + by = 1;
lint extgcd(lint a, lint b, lint& x, lint& y) {
	lint ret = a;
	if (b != 0) {
		ret = extgcd(b, a%b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return ret;
}