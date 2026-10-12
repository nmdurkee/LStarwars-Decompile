
float10 FUN_005ca470(float *param_1)

{
  if ((0x414e4933 < (int)*param_1) && ((int)*param_1 < 0x414e4936)) {
    return (float10)((float)*(ushort *)((int)param_1 + 10) + (float)*(ushort *)((int)param_1 + 0xe))
    ;
  }
  return (float10)*param_1;
}

