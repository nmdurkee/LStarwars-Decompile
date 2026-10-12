/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e74f0; label: FUN_005e74f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e74f0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  undefined4 local_30;
  float local_2c;
  undefined1 local_20 [28];
  
  uVar1 = *(undefined4 *)(DAT_0080bbb4 + DAT_0080bbb0 * 0x28);
  piVar2 = *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28);
  piVar5 = *(int **)(DAT_0080bbdc + DAT_0080bbd8 * 0x28);
  if (*(char *)((int)piVar2 + 9) == '\0') {
    FUN_005f8ba0(piVar2[1],(char)piVar2[2]);
    *(undefined1 *)((int)piVar2 + 9) = 1;
  }
  if (*(char *)((int)piVar5 + 9) == '\0') {
    FUN_005f8ba0(piVar5[1],(char)piVar5[2]);
    *(undefined1 *)((int)piVar5 + 9) = 1;
  }
  local_30 = 0;
  local_2c = *(float *)(*(int *)(in_ECX + 0x1c) + 0x88) * _DAT_00806b70;
  FUN_005c5020(local_20);
  iVar3 = *piVar5;
  iVar7 = *piVar2;
  iVar4 = FUN_005f8a80(uVar1,0,0,0);
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_0060c2e0(*(int *)(in_ECX + 0x18),0,iVar7,0,DAT_009737fc,0);
  }
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  FUN_005c2760();
  FUN_006e5750(0x80,&local_30,2);
  FUN_005f7d00(iVar7,2,2,1);
  FUN_005f7cc0(iVar7,0,2);
  FUN_005f7ed0(iVar7,2,2);
  if (iVar7 != 0) {
    piVar5 = (int *)FUN_005f8460(iVar7);
    if ((DAT_0097f9b8 != *piVar5) || (DAT_0097f9bc != piVar5[1])) {
      uVar6 = FUN_005f8460(iVar7);
      FUN_005fa540(0,uVar6);
    }
  }
  FUN_005f8550(iVar7,0);
  FUN_005f7d00(iVar3,2,2,1);
  FUN_005f7ed0(iVar3,2,2);
  if (iVar3 != 0) {
    piVar5 = (int *)FUN_005f8460(iVar3);
    if ((DAT_0097f9d8 != *piVar5) || (DAT_0097f9dc != piVar5[1])) {
      uVar6 = FUN_005f8460(iVar3);
      FUN_005fa540(4,uVar6);
    }
  }
  FUN_005f8550(iVar3,4);
  if (*(int *)(in_ECX + 0x18) != 0) {
    iVar7 = *(int *)(in_ECX + 0x18);
  }
  if (iVar7 != 0) {
    piVar5 = (int *)FUN_005f8460(iVar7);
    if ((DAT_0097fa00 != *piVar5) || (DAT_0097fa04 != piVar5[1])) {
      uVar6 = FUN_005f8460(iVar7);
      FUN_005fa540(9,uVar6);
    }
  }
  FUN_005f8550(iVar7,9);
  FUN_005f8bf0(uVar1);
  FUN_005fb560();
  *piVar2 = iVar4;
  piVar2[1] = 0;
  *(undefined1 *)(piVar2 + 2) = 1;
  *(undefined1 *)((int)piVar2 + 9) = 0;
  *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28) = piVar2;
  return;
}

