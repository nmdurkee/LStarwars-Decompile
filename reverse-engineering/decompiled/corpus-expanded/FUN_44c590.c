/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x44c590; label: FUN_0044c590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0044c590(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  float10 fVar2;
  
  if (param_6 == 0) {
    return 1;
  }
  iVar1 = 0;
  if (param_5 < 1) {
    return 1;
  }
  do {
    fVar2 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar1 * 4));
    _DAT_00855f74 = (float)fVar2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < param_5);
  return 1;
}

