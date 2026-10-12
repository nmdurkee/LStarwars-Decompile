/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x59a4c0; label: FUN_0059a4c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059a4c0(int param_1)

{
  short sVar1;
  int iVar2;
  
  _DAT_00955fc0 = 0x40000000;
  iVar2 = FUN_0055f450();
  if ((*(int *)(iVar2 + 300) != 0) && (sVar1 = *(short *)(param_1 + 0xe6), sVar1 != -1)) {
    if (sVar1 == DAT_00803ba0) {
      DAT_00951238 = DAT_00951238 + 1;
      if (DAT_00951230 < DAT_00951238) {
        DAT_00951238 = DAT_00951230;
      }
    }
    else if (sVar1 == DAT_00803b9c) {
      if (((DAT_00951244 < DAT_00951240) &&
          (DAT_00951244 = DAT_00951244 + 1, DAT_00951244 == DAT_00951240)) && (9 < DAT_00951240)) {
        FUN_0042f3a0(2,1);
      }
    }
  }
  FUN_00547930(0x26,0,0,0);
  FUN_0054a910(0x3f19999a,0,0,0);
  FUN_00549de0(PTR_DAT_008021b4,0xbe4ccccd,0,0);
  return;
}

