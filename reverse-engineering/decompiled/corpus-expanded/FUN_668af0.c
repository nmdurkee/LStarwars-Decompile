/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x668af0; label: FUN_00668af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00668af0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined2 local_4;
  
  iVar1 = DAT_029231a8;
  local_4 = (undefined2)(int)ROUND(*(float *)(param_2 + 0x54));
  (&DAT_02924b9e)[DAT_029231a8 * 0x2c] = local_4;
  local_4 = (undefined2)(int)ROUND(*(float *)(param_2 + 0x54));
  *(undefined2 *)((&DAT_02924b60)[iVar1 * 0x16] * 0x330 + 0x328 + DAT_029620a4) = local_4;
  return;
}

