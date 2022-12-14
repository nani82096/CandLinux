int rotate_bit(unsigned int num, unsigned int nbit, int dir)
{

	if ( dir == 1) {
		//num = (num >> nbit) | (( num & ( ~((~0) << nbit)) ) << ( (sizeof(int) * 8-1) -(nbit-1) )) ;
		num = (num >> nbit) | (num << (32 - nbit));
	}
	if ( dir == 0)
		num = (num << nbit) | (( num & ( ((~0) << sizeof(int)*8- nbit)) ) >> ( (sizeof(int) * 8-1) -(nbit-1) )) ;

	return num;
}
