
uint FUN_005ca450(int *param_1)

{
  if ((0x414e4933 < *param_1) && (*param_1 < 0x414e4936)) {
    return (uint)*(ushort *)(param_1 + 1);
  }
  return (int)(short)param_1[1];
}

