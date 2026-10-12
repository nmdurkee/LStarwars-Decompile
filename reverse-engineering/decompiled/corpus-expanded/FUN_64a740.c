/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64a740; label: FUN_0064a740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064a740(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
LAB_0064a750:
  do {
    uVar1 = FUN_005b9e10(&DAT_008102e8);
    *(char *)(param_1 + 0x142 + iVar3) = (char)(((ulonglong)uVar1 % 0xffff) / 0x5555) + '\x01';
    if (iVar3 == 1) {
      if (*(char *)(param_1 + 0x143) == *(char *)(param_1 + 0x142)) goto LAB_0064a750;
    }
    FUN_005b9d90(&DAT_008102e8);
    uVar2 = FUN_006e6b90();
    *(undefined4 *)(param_1 + 0x130 + iVar3 * 4) = uVar2;
    iVar3 = iVar3 + 1;
    if (1 < iVar3) {
      return;
    }
  } while( true );
}

