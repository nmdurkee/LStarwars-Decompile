/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635a20; label: FUN_00635a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00635a20(void)

{
  int iVar1;
  int iVar2;
  
  if (_DAT_02913970 != 0) {
    iVar1 = FUN_00547580(_DAT_02913970,0);
    while (iVar1 != 0) {
      iVar2 = FUN_00547580(_DAT_02913970,iVar1);
      FUN_005474d0(iVar1);
      iVar1 = iVar2;
    }
    _DAT_02913978 = 0;
  }
  return DAT_02913974;
}

