/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d2880; label: FUN_005d2880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d2880(int param_1,uint *param_2,undefined1 *param_3)

{
  char cVar1;
  uint *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *local_98;
  int local_94;
  undefined4 local_90;
  uint *local_8c;
  int local_88;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_98;
  local_8c = param_2;
  if (DAT_0080b6d0 != 0) {
    FUN_004f1f10(local_84,param_1);
    puVar3 = (undefined1 *)FUN_004f1fc0(local_84,0x2e);
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0;
    }
    FUN_004f1e80(local_84,&DAT_00764690);
    local_94 = FUN_004fa690(local_84);
    if (local_94 == 0) goto LAB_005d2c55;
    pcVar8 = (char *)((int)param_3 - local_94 & 0xfffffff0);
    local_98 = pcVar8;
    iVar4 = FUN_004fd9f0(local_84,&local_98,param_3,0x10);
    if (iVar4 != 0) {
      iVar5 = FUN_004f1fc0(param_1,0x2f);
      if ((iVar5 != 0) || (iVar5 = FUN_004f1fc0(param_1,0x5c), iVar5 != 0)) {
        param_1 = iVar5 + 1;
      }
      FUN_004f1f10(local_84,param_1);
      puVar3 = (undefined1 *)FUN_004f1fc0(local_84,0x2e);
      if (puVar3 != (undefined1 *)0x0) {
        *puVar3 = 0;
      }
      FUN_004f1e80(local_84,&DAT_00764688);
      iVar5 = FUN_004f9de0(iVar4,local_84);
      if (iVar5 == 0) {
        iVar5 = FUN_005c12e0(local_84);
      }
      FUN_004f0f30(iVar4,iVar5,&local_90,&local_94);
      iVar5 = FUN_004f02d0(local_90,local_94,0);
      local_88 = iVar5;
      if (iVar5 != 0) {
        iVar6 = FUN_004fc750(iVar5);
        if (iVar6 != 0) {
          pcVar8 = pcVar8 + -1;
          *pcVar8 = '\0';
          iVar7 = FUN_004fc5b0(iVar6);
          while (iVar7 != 0) {
            FUN_004f7fb0(iVar6);
            if (**(char **)(iVar6 + 0x510) == '\0') {
              FUN_005c12e0(*(undefined4 *)(iVar6 + 0x51c));
            }
            iVar5 = FUN_004f1fc0(*(undefined4 *)(iVar6 + 0x510),0x2f);
            if ((iVar5 == 0) &&
               (iVar5 = FUN_004f1fc0(*(undefined4 *)(iVar6 + 0x510),0x5c), iVar5 == 0)) {
              iVar5 = *(int *)(iVar6 + 0x510);
            }
            else {
              iVar5 = iVar5 + 1;
            }
            iVar7 = FUN_004f1ff0(iVar5);
            pcVar8 = pcVar8 + (-1 - iVar7);
            FUN_004f1f10(pcVar8,iVar5);
            iVar7 = FUN_004fc5b0(iVar6);
            iVar5 = local_88;
          }
          FUN_004f12e0(iVar6);
        }
        FUN_004f99e0(iVar5);
      }
      cVar1 = *pcVar8;
      local_98 = pcVar8;
      while (cVar1 != '\0') {
        iVar5 = FUN_004f9de0(iVar4,local_98);
        if (iVar5 == 0) {
          iVar5 = FUN_005c12e0(local_98);
        }
        FUN_004f0f30(iVar4,iVar5,&local_90,&local_94);
        iVar5 = FUN_004f02d0(local_90,local_94,0);
        if (iVar5 != 0) {
          iVar6 = FUN_005d26d0(iVar5,local_8c,pcVar8,0);
          if (iVar6 == 0) {
            FUN_005c1300(local_98);
          }
          FUN_004f99e0(iVar5);
        }
        iVar5 = FUN_004f1ff0(local_98);
        local_98 = local_98 + iVar5 + 1;
        cVar1 = *local_98;
      }
      goto LAB_005d2c55;
    }
    if (DAT_009738e0 == 0) {
      FUN_005c1300(param_1);
    }
    else {
      FUN_005c12e0();
    }
    *local_8c = *local_8c + 0xf & 0xfffffff0;
  }
  puVar2 = local_8c;
  *param_3 = 0;
  pcVar8 = param_3 + -1;
  iVar4 = FUN_004fc860(param_1);
  if (iVar4 != 0) {
    *pcVar8 = '\0';
    iVar5 = FUN_004fc5b0(iVar4);
    while (iVar5 != 0) {
      FUN_004f7fb0(iVar4);
      if (**(char **)(iVar4 + 0x510) == '\0') {
        FUN_005c12e0(*(undefined4 *)(iVar4 + 0x51c));
      }
      iVar5 = FUN_004f1ff0(*(undefined4 *)(iVar4 + 0x510));
      pcVar8 = pcVar8 + (-1 - iVar5);
      FUN_004f1f10(pcVar8,*(undefined4 *)(iVar4 + 0x510));
      iVar5 = FUN_004fc5b0(iVar4);
    }
    FUN_004fa300(iVar4);
  }
  cVar1 = *pcVar8;
  local_98 = pcVar8;
  while (cVar1 != '\0') {
    iVar4 = FUN_004fa5f0(local_98,0);
    if (iVar4 == 0) {
LAB_005d2c1e:
      FUN_005c1300(local_98);
    }
    else {
      iVar5 = FUN_005d26d0(iVar4,puVar2,pcVar8,0);
      FUN_004f99e0(iVar4);
      if (iVar5 == 0) goto LAB_005d2c1e;
    }
    iVar4 = FUN_004f1ff0(local_98);
    local_98 = local_98 + iVar4 + 1;
    cVar1 = *local_98;
  }
  *puVar2 = *puVar2 + 0xf & 0xfffffff0;
LAB_005d2c55:
  __security_check_cookie(local_4 ^ (uint)&local_98);
  return;
}

