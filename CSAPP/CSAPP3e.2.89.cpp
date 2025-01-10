//A表达式 (float)x==(float)dx总是为1
//因为double精度和范围大于float
//dx是由int 转为double类型，值不变 所以表达式总是1

//B表达式 dx-dy==(double)(x-y)不总是为1 
//因为当y=Tmin时 -y大于Tmax会造成溢出 x-y的值会发生改变 
//又因为转为double类型的dx，dy 表达的范围更广 即值不会发生改变 
//所以B不总是为1 

//C表达式 (dx + dy) + dz == dx + (dy + dz)总是为1
//因为dx dy dz 均是原值 也不会发生溢出现象

//D表达式 (dx * dy) * dz == dx * (dy * dz)不总是为1
//因为dx dy dz 值很大的时候  (dx * dy) (dy * dz)会发生溢出
//而溢出之后的值是不确定的所以 二者不总是相等 值不总是为1

//E表达式 dx / dx == dz / dz不总是为1
//因为当 dx 和 dz 都为0时，dx / dx 和 dz / dz 都是未定义的，
//因此这个表达式的结果也是未定义的。所以结果不总是为1 
