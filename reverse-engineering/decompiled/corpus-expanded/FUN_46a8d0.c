/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x46a8d0; label: FUN_0046a8d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046a8d0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (DAT_00951288 == 0) {
    iVar1 = FUN_0062c350(0x41200000,_DAT_00925018);
    if (0 < iVar1) {
      iVar1 = FUN_0054fa60(param_2);
      FUN_0062c560(*(undefined4 *)(param_1 + 0x134),
                   (int)*(short *)(&DAT_00804e38 + (iVar1 / 0x2aab) * 2));
    }
  }
  return;
}

