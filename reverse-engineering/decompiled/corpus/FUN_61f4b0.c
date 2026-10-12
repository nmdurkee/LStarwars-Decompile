/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61f4b0; label: FUN_0061f4b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0061f4b0(void)

{
  float *in_ECX;
  
  if ((((*in_ECX < _DAT_0080f550 != (*in_ECX == _DAT_0080f550)) &&
       (in_ECX[1] < _DAT_0080f554 != (in_ECX[1] == _DAT_0080f554))) &&
      (_DAT_0080f550 < in_ECX[2] + *in_ECX)) && (_DAT_0080f554 < in_ECX[3] + in_ECX[1])) {
    return 1;
  }
  return 0;
}

