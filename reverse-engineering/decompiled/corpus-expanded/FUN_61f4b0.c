/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f4b0; label: FUN_0061f4b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

