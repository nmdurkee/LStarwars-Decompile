/* Ghidra analysis pseudocode, not original source.
 * ev_8e6c58f632ba894c996161736f16e550f9c9cdfbb0c94bd06c2a8d698c289bc5
 * Entry: 0x5d3400; label: FUN_005d3400
 */

void FUN_005d3400(int param_1)

{
  int *piVar1;
  
  FUN_004ffaa0(DAT_0080b6d4);
  piVar1 = DAT_009738d8;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      FUN_004ffac0();
      return;
    }
    if (*piVar1 == param_1) break;
    piVar1 = (int *)piVar1[1];
  }
  if (piVar1[1] != 0) {
    *(int *)(piVar1[1] + 8) = piVar1[2];
  }
  if (piVar1[2] == 0) {
    DAT_009738d8 = (int *)piVar1[1];
  }
  else {
    *(int *)(piVar1[2] + 4) = piVar1[1];
  }
  piVar1[1] = (int)DAT_009738dc;
  DAT_009738dc = piVar1;
  (*(code *)PTR_FUN_00800824)();
  FUN_004ffac0();
  return;
}

