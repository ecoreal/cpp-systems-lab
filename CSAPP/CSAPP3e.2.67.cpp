/*A： 在C中，左移操作的位移数不能大于等于数据类型的宽度。
因为超出类型宽度的位移是未定义行为，可能会导致程序出现不可预测的结果。*/

/*B解答如下*/

int bad_int_size_is_more32() 
{

    int set_msb =  1 << 31;
    
	int beyond_msb =  set_msb<<1;

    return set_msb && !beyond_msb;
}

/*C解答如下*/
int bad_int_size_is_more16() 
{

    int set_msb =  1 << 15;
    
	int beyond_msb =  set_msb<<1;

    return set_msb && !beyond_msb;
}
