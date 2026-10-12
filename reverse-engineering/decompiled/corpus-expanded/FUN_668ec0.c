/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x668ec0; label: FUN_00668ec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00668ec0(undefined4 param_1,int param_2)

{
  *(byte *)(*(int *)(DAT_0296209c + (&DAT_02924b5c)[DAT_029231a8 * 0x16] * 4) + 0x412) =
       *(byte *)(param_2 + 0x11) & 1;
  return;
}

