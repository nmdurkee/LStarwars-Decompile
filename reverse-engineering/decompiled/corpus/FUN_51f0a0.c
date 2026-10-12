/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51f0a0; label: FUN_0051f0a0
 */

void FUN_0051f0a0(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  if (*(float *)(param_2 + 0x1c0) <= *(float *)(param_2 + 0x1c4)) {
    uVar2 = *(undefined4 *)(param_2 + 0x1c4);
  }
  else {
    uVar2 = *(undefined4 *)(param_2 + 0x1c0);
  }
  FUN_005b3800(&local_18,param_3 + 0x5c,param_2 + 0x1b4);
  uVar1 = FUN_005be2d0(local_18,local_10);
  local_18 = 0;
  local_10 = uVar2;
  FUN_005b3620(&local_18,&local_18,uVar1);
  FUN_005b37d0(local_c,param_2 + 0x1b4,&local_18);
  if ((*(uint *)(param_2 + 0x1e8) & 0x200) == 0) {
    uVar2 = FUN_005be590(uVar1,0x4000);
  }
  else {
    uVar2 = FUN_005be5b0();
  }
  local_18 = 0;
  local_14 = 0;
  local_10 = 0x3f000000;
  FUN_005b3620(&local_18,&local_18,uVar2);
  FUN_005b37d0(param_2 + 0x104,local_c,&local_18);
  *(undefined4 *)(param_2 + 0x110) = 0;
  *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) | 0x400;
  return;
}

