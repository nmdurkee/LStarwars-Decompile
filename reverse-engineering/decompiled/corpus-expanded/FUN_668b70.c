/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x668b70; label: FUN_00668b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00668b70(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_029231a8;
  (&DAT_02924ba0)[DAT_029231a8 * 0x58] = *(byte *)(param_2 + 0x11) & 1;
  *(byte *)((&DAT_02924b60)[iVar1 * 0x16] * 0x330 + 0x2f8 + DAT_029620a4) =
       *(byte *)(param_2 + 0x11) & 1;
  return;
}

