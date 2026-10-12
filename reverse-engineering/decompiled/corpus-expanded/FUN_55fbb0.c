/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55fbb0; label: FUN_0055fbb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055fbb0(int param_1)

{
  ushort *puVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x5048) != 0) && (iVar2 = 0, 0 < *(int *)(param_1 + 0x504c))) {
    puVar1 = (ushort *)(*(int *)(param_1 + 0x5048) + 0xc);
    do {
      *puVar1 = *puVar1 & 0xfff9;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 8;
    } while (iVar2 < *(int *)(param_1 + 0x504c));
  }
  return;
}

