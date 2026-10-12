/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c53d0; label: FUN_004c53d0
 */

void FUN_004c53d0(undefined4 param_1,undefined4 param_2,float param_3)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [52];
  float local_c;
  
  iVar1 = FUN_005cfac0(in_EAX + 0x68);
  if (iVar1 != 0) {
    local_44 = param_2;
    local_48 = param_2;
    local_4c = param_2;
    FUN_005b45a0(local_40,&local_4c);
    FUN_004c0db0();
    FUN_004c0e90();
    uVar2 = FUN_004c0f70();
    FUN_005b4900(uVar2,param_1);
    local_c = local_c + param_3;
    FUN_005f33b0(in_EAX + 0x68,local_40);
  }
  return;
}

