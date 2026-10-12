
float10 FUN_005ca4b0(float *param_1)

{
  if ((0x414e4933 < (int)*param_1) && ((int)*param_1 < 0x414e4936)) {
    if (*(ushort *)((int)param_1 + 0x16) != 0) {
      return (float10)*(ushort *)((int)param_1 + 0x16);
    }
    return (float10)((uint)*(ushort *)((int)param_1 + 0xe) + (uint)*(ushort *)((int)param_1 + 10));
  }
  return (float10)*param_1;
}

