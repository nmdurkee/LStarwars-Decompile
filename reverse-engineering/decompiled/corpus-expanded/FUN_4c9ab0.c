/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c9ab0; label: FUN_004c9ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c9ab0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  return;
}

