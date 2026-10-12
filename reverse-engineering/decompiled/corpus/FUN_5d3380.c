/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d3380; label: FUN_005d3380
 */

void FUN_005d3380(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    FUN_004ffaa0(DAT_0080b6d4);
    piVar2 = DAT_009738dc;
    if (DAT_009738dc != (int *)0x0) {
      piVar1 = DAT_009738dc + 1;
      if (DAT_009738dc[1] == 0) {
        FUN_004feaa0("Ran out of texture anim slots!");
      }
      DAT_009738dc = (int *)DAT_009738dc[1];
      *piVar1 = (int)DAT_009738d8;
      piVar2[2] = 0;
      *piVar2 = param_1;
      if (DAT_009738d8 != (int *)0x0) {
        DAT_009738d8[2] = (int)piVar2;
      }
      DAT_009738d8 = piVar2;
    }
    FUN_004ffac0();
    return;
  }
  return;
}

