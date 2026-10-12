/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c52a0; label: FUN_004c52a0
 */

void FUN_004c52a0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [16];
  
  iVar1 = FUN_005cfac0(param_1);
  if (iVar1 != 0) {
    local_4c = param_2;
    local_48 = param_2;
    local_44 = param_2;
    puVar2 = (undefined4 *)FUN_005d0330(param_1);
    puVar3 = local_40;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005b4c30(local_40,&local_4c);
    FUN_005f33b0(param_1,local_40);
  }
  return;
}

