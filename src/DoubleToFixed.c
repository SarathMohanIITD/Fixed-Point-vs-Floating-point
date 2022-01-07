
long long DoubleToFixed(double Double,int shift)
{
   long long Fixed = Double * (1<<shift);
    return Fixed;
}
