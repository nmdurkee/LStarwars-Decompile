/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x531ef0; label: FUN_00531ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00531ef0(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  void *_Dst;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  float local_c;
  int local_8;
  int local_4;
  
  _memset((void *)(DAT_009238e4 + 0x3cbd8),0,0x48);
  iVar7 = 0;
  do {
    FUN_004f1310(DAT_009238e4 + 0x3cbd0,iVar7 + 0x383d0 + DAT_009238e4);
    iVar7 = iVar7 + 0x48;
  } while (iVar7 < 0x4800);
  _memset((void *)(DAT_009238e4 + 0x41200),0,0x118);
  iVar7 = 0;
  do {
    FUN_004f1310(DAT_009238e4 + 0x411f8,iVar7 + 0x3cbe8 + DAT_009238e4);
    iVar7 = iVar7 + 0x118;
  } while (iVar7 < 0x4600);
  if (*(int *)(DAT_009238e4 + 100) != 0) {
    iVar7 = *(int *)(DAT_009238e4 + 100);
    local_4 = 0;
    if (0 < *(int *)(iVar7 + 0x24)) {
      local_8 = 0;
      do {
        pcVar8 = (char *)(*(int *)(iVar7 + 0x28) + local_8);
        uVar3 = *(undefined4 *)(pcVar8 + 0x1c);
        iVar7 = FUN_004f1440(DAT_009238e4 + 0x3cbd0);
        if (iVar7 != 0) {
          FUN_004f1410(DAT_009238e4 + 0x3cbd0,iVar7);
          FUN_004f1310(DAT_009238e4 + 0x3cbd8,iVar7);
          *(undefined4 *)(iVar7 + 0x18) = *(undefined4 *)(pcVar8 + 0x10);
          *(undefined4 *)(iVar7 + 0x1c) = *(undefined4 *)(pcVar8 + 0x14);
          *(undefined4 *)(iVar7 + 0x20) = *(undefined4 *)(pcVar8 + 0x18);
          *(undefined4 *)(iVar7 + 0x24) = uVar3;
        }
        pcVar2 = pcVar8;
        do {
          cVar1 = *pcVar2;
          pcVar2[(iVar7 - (int)pcVar8) + 8] = cVar1;
          pcVar2 = pcVar2 + 1;
        } while (cVar1 != '\0');
        uVar3 = FUN_00524b00(*(undefined4 *)(pcVar8 + 0x20));
        local_c = 0.0;
        piVar4 = (int *)(iVar7 + 0x28);
        FUN_00524900(iVar7 + 0x18,piVar4,uVar3,0);
        iVar6 = *piVar4;
        while (iVar6 == 0) {
          local_c = local_c + 0.01;
          FUN_00524900(iVar7 + 0x18,piVar4,uVar3,local_c);
          iVar6 = *piVar4;
        }
        uVar3 = FUN_005be5b0(*(undefined4 *)(iVar7 + 0x24),*(undefined4 *)(iVar7 + 0x40));
        local_8 = local_8 + 0x3c;
        *(undefined4 *)(iVar7 + 0x40) = uVar3;
        iVar7 = *(int *)(DAT_009238e4 + 100);
        local_4 = local_4 + 1;
      } while (local_4 < *(int *)(iVar7 + 0x24));
    }
    iVar7 = *(int *)(DAT_009238e4 + 100);
    iVar6 = 0;
    if (0 < *(int *)(iVar7 + 0x2c)) {
      iVar5 = 0;
      do {
        pcVar8 = (char *)(*(int *)(iVar7 + 0x30) + iVar5);
        _Dst = (void *)FUN_004f1440(DAT_009238e4 + 0x411f8);
        if (_Dst != (void *)0x0) {
          FUN_004f1410(DAT_009238e4 + 0x411f8,_Dst);
          _memset(_Dst,0,0x118);
          FUN_004f1310(DAT_009238e4 + 0x41200,_Dst);
        }
        if ((pcVar8 != (char *)0x0) && (_Dst != (void *)0x0)) {
          pcVar2 = pcVar8;
          do {
            cVar1 = *pcVar2;
            pcVar2[(int)_Dst + (8 - (int)pcVar8)] = cVar1;
            pcVar2 = pcVar2 + 1;
          } while (cVar1 != '\0');
          iVar7 = 0;
          if ('\0' < pcVar8[0x10]) {
            piVar4 = (int *)((int)_Dst + 0x18);
            do {
              *piVar4 = DAT_009238e4 + 0x383d0 +
                        (uint)*(byte *)(*(int *)(pcVar8 + 0x14) + iVar7) * 0x48;
              iVar7 = iVar7 + 1;
              piVar4 = piVar4 + 1;
            } while (iVar7 < pcVar8[0x10]);
          }
        }
        iVar7 = *(int *)(DAT_009238e4 + 100);
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x1c;
      } while (iVar6 < *(int *)(iVar7 + 0x2c));
    }
  }
  iVar7 = DAT_009238e4;
  if (*(int *)(DAT_009238e4 + 0x41208) != 0) {
    pcVar8 = (char *)(*(int *)(DAT_009238e4 + 0x41208) + 8);
    pcVar2 = &DAT_00921f10;
    do {
      cVar1 = *pcVar8;
      *pcVar2 = cVar1;
      pcVar8 = pcVar8 + 1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  pcVar8 = &DAT_00921f10;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  if (pcVar8 != &DAT_00921f11) {
    uVar3 = FUN_00521c50();
    *(undefined4 *)(DAT_009238e4 + 0x41208) = uVar3;
    return;
  }
  *(undefined4 *)(iVar7 + 0x41208) = 0;
  return;
}

