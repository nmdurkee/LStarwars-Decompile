/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x667160; label: FUN_00667160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00667160(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = (&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330;
    if ((*(byte *)(param_2 + 0x11) & 1) != 0) {
      *(undefined1 *)(*(int *)(DAT_0296209c + *(short *)(iVar1 + 0x182 + DAT_029620a4) * 4) + 0x2f3)
           = 1;
      return;
    }
    *(undefined1 *)(*(int *)(DAT_0296209c + *(short *)(iVar1 + 0x182 + DAT_029620a4) * 4) + 0x2f3) =
         0;
  }
  return;
}

