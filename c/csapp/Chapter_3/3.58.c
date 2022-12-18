long decode2(long x, long y, long z){
// x in rdi, y in rsi, z in rdx
	y -= z;
	x *= y;
	int val = y;
	val = (val << 63) >> 63;
	val ^= x;
	return val;
}