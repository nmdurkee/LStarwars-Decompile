/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d3380; label: FUN_005d3380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

