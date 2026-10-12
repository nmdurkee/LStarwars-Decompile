/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d3690; label: FUN_004d3690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d3690(int param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c [12];
  undefined1 auStack_40 [64];
  
  pbVar1 = *(byte **)(param_1 + 0xcc4) + (**(byte **)(param_1 + 0xcc4) + 4) * 0xc;
  local_58 = *(undefined4 *)pbVar1;
  local_54 = *(undefined4 *)(pbVar1 + 4);
  local_50 = *(undefined4 *)(pbVar1 + 8);
  (**(code **)(PTR_PTR_008040bc + 0x14))(param_1,local_4c);
  FUN_004d2100();
  if (((PTR_DAT_00802c54 == (undefined *)0x0) || (*(int *)(PTR_DAT_00802c54 + 300) == 0)) ||
     ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 4) == 0)) {
    uVar2 = 0xf;
  }
  else {
    uVar2 = 0x10;
  }
  FUN_00582e70(param_1,&local_58,auStack_40,uVar2,0);
  **(char **)(param_1 + 0xcc4) = **(char **)(param_1 + 0xcc4) + -1;
  pbVar1 = (byte *)(*(int *)(param_1 + 0xcc4) + 1);
  *pbVar1 = *pbVar1 | 2;
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    FUN_00576960(0x289);
  }
  return;
}

