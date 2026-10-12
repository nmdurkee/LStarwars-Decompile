/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e6a80; label: FUN_005e6a80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e6a80(int param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *local_28 [10];
  
  uVar4 = FUN_005f8a50();
  if (param_1 == 0) {
    param_1 = FUN_005f8a60(1);
  }
  iVar5 = FUN_005f8a60(0);
  uVar6 = FUN_005f8a80(uVar4,0,0,0);
  uVar7 = FUN_005f8a80(uVar4,1,0,0);
  uVar8 = FUN_005f8a80(uVar4,2,0,0);
  uVar9 = FUN_005f8a80(uVar4,2,0,0);
  uVar4 = FUN_005f8a80(uVar4,4,0,0);
  FUN_005f8bc0(0);
  _DAT_0080bb54 = 2;
  _DAT_0080bb60 = 2;
  DAT_0080bb40 = 1;
  DAT_0080bb41 = 1;
  _DAT_0080bb48 = 1;
  DAT_0080bb4c = 1;
  DAT_0080bb4d = 1;
  DAT_0080bb58 = 1;
  DAT_0080bb59 = 1;
  DAT_0080bb64 = 1;
  DAT_0080bb65 = 1;
  _DAT_0080bb6c = 4;
  DAT_0080bb70 = 1;
  DAT_0080bb71 = 1;
  _DAT_0080bb3c = 0;
  _DAT_0080bb38 = uVar6;
  _DAT_0080bb44 = uVar7;
  _DAT_0080bb50 = uVar8;
  _DAT_0080bb5c = uVar9;
  _DAT_0080bb68 = uVar4;
  *(undefined **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28) = &DAT_0080bb38;
  *(undefined **)(DAT_0080bbc4 + DAT_0080bbc0 * 0x28) = &DAT_0080bb44;
  *(undefined **)(DAT_0080bbcc + DAT_0080bbc8 * 0x28) = &DAT_0080bb50;
  *(undefined **)(DAT_0080bbd4 + DAT_0080bbd0 * 0x28) = &DAT_0080bb5c;
  *(undefined **)(DAT_0080bbdc + DAT_0080bbd8 * 0x28) = &DAT_0080bb68;
  D3DPERF_BeginEvent(0xffffffff,L"Post-processing-effect render");
  iVar10 = 0;
  local_28[0] = (int *)0x0;
  if (DAT_009737f0 != (int *)0x0) {
    cVar3 = (**(code **)(*DAT_009737f0 + 0x20))();
    if (cVar3 != '\0') {
      local_28[0] = DAT_009737f0;
      iVar10 = 1;
    }
  }
  if (DAT_009737e4 != (int *)0x0) {
    cVar3 = (**(code **)(*DAT_009737e4 + 0x20))();
    if (cVar3 != '\0') {
      local_28[iVar10] = DAT_009737e4;
      iVar10 = iVar10 + 1;
    }
  }
  if (DAT_009737e0 != (int *)0x0) {
    cVar3 = (**(code **)(*DAT_009737e0 + 0x20))();
    if (cVar3 != '\0') {
      local_28[iVar10] = DAT_009737e0;
      iVar10 = iVar10 + 1;
    }
  }
  if (DAT_009737e8 != (int *)0x0) {
    cVar3 = (**(code **)(*DAT_009737e8 + 0x20))();
    if (cVar3 != '\0') {
      local_28[iVar10] = DAT_009737e8;
      iVar10 = iVar10 + 1;
    }
  }
  if (DAT_009737ec != (int *)0x0) {
    cVar3 = (**(code **)(*DAT_009737ec + 0x20))();
    if (cVar3 != '\0') {
      local_28[iVar10] = DAT_009737ec;
      iVar10 = iVar10 + 1;
    }
  }
  DAT_02854c18 = 0;
  DAT_02854c1c = 0;
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  iVar12 = 0;
  if (iVar10 != 0) {
    do {
      iVar1 = iVar12 + 1;
      iVar11 = iVar5;
      if (iVar10 <= iVar1) {
        iVar11 = param_1;
      }
      *(int *)(DAT_0080bbb4 + DAT_0080bbb0 * 0x28) = iVar11;
      piVar2 = local_28[iVar12];
      (**(code **)(*piVar2 + 0x14))();
      (**(code **)(*piVar2 + 0x18))();
      iVar12 = 0;
      do {
        FUN_005f8550(0,iVar12);
        iVar12 = iVar12 + 1;
      } while (iVar12 != 6);
      iVar12 = iVar1;
    } while (iVar1 < iVar10);
  }
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,1);
  FUN_006e5340(0x1b,1);
  FUN_006e5340(7,1);
  FUN_006e5340(0x17,4);
  _DAT_009737d8 = _DAT_009737d8 + 1;
  D3DPERF_EndEvent();
  return;
}

