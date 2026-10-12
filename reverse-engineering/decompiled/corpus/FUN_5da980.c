/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5da980; label: FUN_005da980
 */

void FUN_005da980(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [16];
  
  if (DAT_009739a8 == '\0') {
    local_4c = *(undefined4 *)(param_1 + 0x1ac);
    local_48 = *(undefined4 *)(param_1 + 0x1b0);
    local_44 = *(undefined4 *)(param_1 + 0x1b4);
    local_58 = *(undefined4 *)(param_1 + 0x1b8);
    local_54 = *(undefined4 *)(param_1 + 0x1bc);
    local_50 = *(undefined4 *)(param_1 + 0x1c0);
    FUN_006042e0(&local_4c,&local_58,param_2,0,0);
    return;
  }
  FUN_005b3800(&local_58,param_1 + 0x1b8,param_1 + 0x1ac);
  FUN_005b3830(&local_58,&local_58,0x3f000000);
  FUN_005b37b0(&local_4c,&local_58);
  puVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_005b4960(local_40,param_3 + 0x30);
  FUN_006042e0(&local_4c,&local_58,local_40,0,0);
  return;
}

