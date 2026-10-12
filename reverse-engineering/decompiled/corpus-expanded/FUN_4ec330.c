/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ec330; label: FUN_004ec330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ec330(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_00803bb0 = 0xffffffff;
  iVar1 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"float_skiff_2",1);
  if ((iVar1 != 0) && (*(int *)(param_1 + 0x295c) != 0)) {
    uVar2 = FUN_005cffb0(&DAT_0087aad8);
    DAT_00803bb0 = FUN_0067c760(uVar2);
  }
  return;
}

