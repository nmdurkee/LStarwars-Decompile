/* Ghidra analysis pseudocode, not original source.
 * ev_b8d156e74790e07078a260599393ca89d6d858c624833fd21a4e8cf1d6239801
 * Entry: 0x6cf540; label: FUN_006cf540
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cf540(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 auStack_a4 [4];
  int local_a0;
  int *local_9c;
  undefined1 auStack_98 [132];
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)auStack_a4;
  iVar2 = *(int *)(param_2 + 0xc);
  local_a0 = param_1;
  if ((iVar2 < 0) || (DAT_02973bac <= iVar2)) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5 = (undefined4 *)(DAT_02973b90 + iVar2 * 0x18);
  }
  _DAT_0081fab0 = puVar5;
  piVar1 = (int *)FUN_00619250(*(int *)(param_2 + 0x1c) + *(int *)(param_1 + 0x1c),
                               *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0
                              );
  if (piVar1 != (int *)0x0) {
    local_9c = (int *)FUN_006c69a0(2,1);
    for (iVar2 = (**(code **)(*(int *)puVar5[5] + 0x14))(0); iVar2 != 0;
        iVar2 = (**(code **)(*(int *)puVar5[5] + 0x14))(iVar2)) {
      if ((local_9c == (int *)0x0) || ((*(byte *)(local_9c + 7) & 2) == 0)) {
        FUN_004f1f10(auStack_98,*puVar5);
      }
      else {
        (**(code **)(*local_9c + 4))(iVar2,DAT_02973ac4,auStack_98,0x80);
      }
      iVar3 = FUN_006c8b60(iVar2,puVar5,0xffffffff);
      if (iVar3 != 0) {
        uVar4 = FUN_00627a80(iVar2,&DAT_0081f9a0,0,0,&LAB_006cf4d0,auStack_98);
        FUN_00618e10(piVar1,uVar4);
      }
    }
    if (*piVar1 == 0) {
      uVar4 = FUN_00627a80(0,&DAT_0081f9a0,0,0,FUN_006bc8c0,"No Object");
      FUN_00618e10(piVar1,uVar4);
    }
    else {
      uVar4 = FUN_00626a80(0,&DAT_0081f9a0,"FILTER",&DAT_007516c0);
      FUN_00618e50(piVar1,uVar4);
    }
    FUN_006242b0(piVar1,5);
    FUN_00627930(piVar1,1);
    FUN_006279b0(local_a0,piVar1);
    FUN_00619060(piVar1);
  }
  __security_check_cookie(local_14 ^ (uint)auStack_a4);
  return;
}

