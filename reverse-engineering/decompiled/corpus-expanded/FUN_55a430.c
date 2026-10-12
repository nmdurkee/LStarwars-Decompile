/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x55a430; label: FUN_0055a430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055a430(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *local_134;
  char *local_130;
  int iStack_12c;
  char *local_128;
  int local_124;
  byte bStack_11e;
  int local_11c;
  undefined4 local_118;
  int *local_114;
  undefined1 auStack_110 [12];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_134;
  local_114 = param_1;
  local_118 = param_3;
  if (DAT_0093b268 == (int *)0x0) {
LAB_0055a948:
    __security_check_cookie(local_4 ^ (uint)&local_134);
    return;
  }
  iVar5 = thunk_FUN_004fa610(param_2);
  if (iVar5 != 0) {
    _sprintf(local_104,"%s.bak",param_2);
    FUN_004fd850(local_104,param_2);
  }
  FUN_006211c0(1);
  iVar5 = FUN_00621270(param_2,1);
  if (iVar5 == 0) goto LAB_0055a948;
  FUN_00621520(DAT_00802800);
  FUN_00621520(*DAT_0093b268);
  if (*DAT_0093b268 != 0) {
    local_130 = (char *)DAT_0093b268[2];
    local_124 = 0;
    if (0 < *DAT_0093b268) {
      local_134 = (int *)(*param_1 + 4);
      local_128 = local_130 + 0x20;
      do {
        pcVar7 = local_130;
        pcVar6 = local_130;
        do {
          cVar2 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar2 != '\0');
        pcVar6 = pcVar6 + (1 - (int)(local_130 + 1));
        FUN_00621520(pcVar6);
        if (pcVar6 != (char *)0x0) {
          FUN_00621440(pcVar7,pcVar6);
        }
        pcVar6 = local_128;
        if (3 < DAT_00802800) {
          iVar5 = FUN_004f1ff0(local_128);
          iVar5 = iVar5 + 1;
          FUN_00621600(iVar5);
          if (iVar5 != 0) {
            FUN_00621440(pcVar6,iVar5);
          }
        }
        piVar4 = local_134;
        FUN_00621520(*local_134);
        iVar5 = piVar4[2];
        local_11c = 0;
        if (0 < *piVar4) {
          do {
            if ((((DAT_0093b268 == (int *)0x0) || (iVar5 == 0)) ||
                (*DAT_0093b268 <= (int)(uint)*(byte *)(iVar5 + 6))) ||
               (pcVar3 = *(code **)((uint)*(byte *)(iVar5 + 6) * 0x9c + 0x44 + DAT_0093b268[2]),
               pcVar3 == (code *)0x0)) {
              pcVar6 = (char *)0x0;
LAB_0055a5e8:
              pcVar7 = (char *)0x0;
            }
            else {
              pcVar6 = (char *)(*pcVar3)(iVar5);
              if (pcVar6 == (char *)0x0) goto LAB_0055a5e8;
              pcVar7 = pcVar6;
              do {
                cVar2 = *pcVar7;
                pcVar7 = pcVar7 + 1;
              } while (cVar2 != '\0');
              pcVar7 = pcVar7 + (1 - (int)(pcVar6 + 1));
            }
            FUN_00621520(pcVar7);
            if (pcVar7 != (char *)0x0) {
              FUN_00621440(pcVar6,pcVar7);
            }
            if ((DAT_0093b268 == (int *)0x0) || (iVar5 == 0)) {
              iStack_12c = 0;
            }
            else if (((int)(uint)*(byte *)(iVar5 + 6) < *DAT_0093b268) &&
                    (pcVar3 = *(code **)((uint)*(byte *)(iVar5 + 6) * 0x9c + 0x50 + DAT_0093b268[2])
                    , pcVar3 != (code *)0x0)) {
              iStack_12c = (*pcVar3)(iVar5);
            }
            else {
              iStack_12c = 1;
            }
            iVar9 = iStack_12c;
            FUN_00621520(iStack_12c);
            iVar10 = 0;
            if (0 < iVar9) {
              do {
                if ((DAT_0093b268 == (int *)0x0) || (iVar5 == 0)) {
                  pcVar6 = (char *)0x0;
LAB_0055a6b9:
                  pcVar7 = (char *)0x0;
                }
                else {
                  if (((int)(uint)*(byte *)(iVar5 + 6) < *DAT_0093b268) &&
                     (pcVar3 = *(code **)((uint)*(byte *)(iVar5 + 6) * 0x9c + 0x4c + DAT_0093b268[2]
                                         ), pcVar3 != (code *)0x0)) {
                    pcVar6 = (char *)(*pcVar3)(iVar5,iVar10);
                    if (pcVar6 == (char *)0x0) goto LAB_0055a6b9;
                  }
                  else {
                    pcVar6 = "default";
                  }
                  pcVar7 = pcVar6;
                  do {
                    cVar2 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  } while (cVar2 != '\0');
                  pcVar7 = pcVar7 + (1 - (int)(pcVar6 + 1));
                }
                FUN_00621520(pcVar7);
                if (pcVar7 != (char *)0x0) {
                  FUN_00621440(pcVar6,pcVar7);
                }
                iVar10 = iVar10 + 1;
              } while (iVar10 < iStack_12c);
            }
            local_11c = local_11c + 1;
            iVar5 = iVar5 + 8;
          } while (local_11c < *local_134);
        }
        local_134 = local_134 + 5;
        local_130 = local_130 + 0x9c;
        local_128 = local_128 + 0x9c;
        local_124 = local_124 + 1;
      } while (local_124 < *DAT_0093b268);
    }
  }
  piVar4 = DAT_00956414;
  if (DAT_00802800 == 1) {
    if ((DAT_00956414 == (int *)0x0) || (*DAT_00956414 == 0)) goto LAB_0055a925;
    do {
      iVar9 = 0;
      iVar5 = *DAT_00956414;
      piVar8 = DAT_00956414;
      while (iVar5 != 0) {
        piVar8 = piVar8 + 2;
        iVar9 = iVar9 + 1;
        iVar5 = *piVar8;
      }
      FUN_00621520(iVar9);
      pcVar6 = (char *)*DAT_00956414;
      piVar8 = DAT_00956414;
      while (pcVar6 != (char *)0x0) {
        pcVar7 = pcVar6 + 1;
        do {
          cVar2 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar2 != '\0');
        pcVar6 = pcVar6 + (1 - (int)pcVar7);
        FUN_00621520(pcVar6);
        if (pcVar6 != (char *)0x0) {
          FUN_00621440(*piVar8,pcVar6);
        }
        piVar1 = piVar8 + 2;
        piVar8 = piVar8 + 2;
        pcVar6 = (char *)*piVar1;
      }
    } while (*piVar4 != 0);
  }
  if (2 < DAT_00802800) {
    if ((3 < DAT_00802800) && (DAT_00805ebc != -1)) {
      iVar5 = DAT_00805ebc * 0x9c + DAT_0093b268[2] + 0x20;
      iVar9 = FUN_004f1ff0(iVar5);
      iVar9 = iVar9 + 1;
      FUN_00621600(iVar9);
      if (iVar9 != 0) {
        FUN_00621440(iVar5,iVar9);
      }
      bStack_11e = (byte)DAT_00805ebc;
      iVar5 = FUN_0055a160(local_114,&local_124);
      FUN_00621600(iVar5);
      iVar9 = 0;
      if (0 < iVar5) {
        do {
          if ((DAT_0093b268 == (int *)0x0) || (local_114 == (int *)0x0)) {
            pcVar6 = (char *)0x0;
LAB_0055a898:
            iVar10 = 0;
          }
          else if (((int)(uint)bStack_11e < *DAT_0093b268) &&
                  (pcVar3 = *(code **)((uint)bStack_11e * 0x9c + 0x4c + DAT_0093b268[2]),
                  pcVar3 != (code *)0x0)) {
            pcVar6 = (char *)(*pcVar3)(&local_124,iVar9);
            if (pcVar6 == (char *)0x0) goto LAB_0055a898;
            iVar10 = FUN_004f1ff0(pcVar6);
            iVar10 = iVar10 + 1;
          }
          else {
            pcVar6 = "default";
            iVar10 = FUN_004f1ff0("default");
            iVar10 = iVar10 + 1;
          }
          FUN_00621520(iVar10);
          if (iVar10 != 0) {
            FUN_00621440(pcVar6,iVar10);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar5);
      }
    }
    iVar5 = FUN_005da840(local_118);
    FUN_00621520(iVar5);
    iVar9 = 0;
    if (0 < iVar5) {
      do {
        FUN_005da860(auStack_110,local_118,iVar9);
        pcVar7 = (char *)FUN_005cfa50(auStack_110);
        pcVar6 = pcVar7;
        do {
          cVar2 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar2 != '\0');
        FUN_00621520(pcVar6 + (1 - (int)(pcVar7 + 1)));
        FUN_00621440(pcVar7,pcVar6 + (1 - (int)(pcVar7 + 1)));
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar5);
    }
  }
LAB_0055a925:
  FUN_006213e0();
  __security_check_cookie(local_4 ^ (uint)&local_134);
  return;
}

