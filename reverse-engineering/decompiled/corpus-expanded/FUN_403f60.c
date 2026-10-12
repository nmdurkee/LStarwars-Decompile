/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x403f60; label: FUN_00403f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00403f60(int param_1,char *param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  float10 fVar10;
  float local_68;
  float local_60;
  char *local_5c;
  int local_54;
  int local_50;
  char *local_4c;
  undefined4 local_3c;
  float local_38;
  undefined4 local_34;
  float local_30 [2];
  float local_28;
  float local_24 [2];
  float local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  puVar2 = *(undefined4 **)(param_2 + 0xcc0);
  local_50 = -1;
  FUN_005b3620(local_24,&DAT_0080250c,*(undefined2 *)(param_2 + 0x5a));
  iVar9 = 0;
  local_60 = 64.0;
  pcVar6 = (char *)0x0;
  local_68 = 16.0;
  local_5c = (char *)0x0;
  pcVar8 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if ((((((((*(uint *)(pcVar8 + 0x1fc) & 1) != 0) && ((*(uint *)(pcVar8 + 0x1fc) & 0x1000) != 0)
              ) && (pcVar8[0x28b] == '\0')) &&
            ((cVar1 = pcVar8[0x7b5], (*(uint *)(PTR_PTR_007fb0e4 + cVar1 * 0x10 + 8) & 0x8000) == 0
             && (pcVar8[0x288] != '\0')))) && (pcVar8 != param_2)) &&
          (((pcVar8[0x280] == -1 && (cVar1 != ';')) &&
           ((cVar1 != '9' &&
            (((cVar1 != '<' && ((*(uint *)(param_2 + 0x1f8) & 0x10004) == 0)) &&
             (((*(uint *)(pcVar8 + 0x1f8) ^ *(uint *)(param_2 + 0x1f8)) & 1) != 0)))))))) &&
         (iVar3 = FUN_00403e70(), iVar3 == 0)) {
        if (param_3 == 0) {
          if (((ABS(*(float *)(pcVar8 + 0xc5c) - (float)puVar2[0x22]) < 0.1) &&
              (ABS(*(float *)(pcVar8 + 0xc60) - (float)puVar2[0x23]) < 0.2)) &&
             (fVar10 = (float10)FUN_005b3c50(pcVar8 + 0x80,param_2 + 0x80,local_30), pcVar7 = pcVar8
             , fVar10 < (float10)64.0)) break;
        }
        else {
          fVar10 = (float10)FUN_005b3c50(pcVar8 + 0x80,param_2 + 0x80,local_30);
          if ((0.0 < local_24[0] * local_30[0] + local_1c * local_28) && ((float)fVar10 < local_68))
          {
            pcVar6 = pcVar8;
            local_68 = (float)fVar10;
          }
        }
      }
      iVar9 = iVar9 + 1;
      pcVar7 = (char *)0x0;
      pcVar8 = pcVar8 + 0x10d8;
    } while (iVar9 < DAT_0093d500);
    if ((pcVar6 != (char *)0x0) && (local_68 < 64.0)) {
      local_60 = local_68;
      pcVar7 = pcVar6;
    }
    if (pcVar7 != (char *)0x0) {
      local_3c = *(undefined4 *)(pcVar7 + 0x80);
      local_50 = 0;
      local_38 = (*(float *)(pcVar7 + 0x194) + *(float *)(pcVar7 + 0x84)) * 0.5;
      local_34 = *(undefined4 *)(pcVar7 + 0x88);
      local_5c = pcVar7;
    }
  }
  if (param_3 == 0) {
    pcVar6 = &DAT_008569e1;
    iVar9 = 10;
    do {
      if (((pcVar6[-1] != '\0') && (*pcVar6 != '\0')) && (*(float *)(pcVar6 + 7) != 0.0)) {
        uVar4 = (uint)*(byte *)(puVar2 + 0x1f);
        iVar3 = 0;
        puVar5 = puVar2;
        if (uVar4 != 0) {
          do {
            if ((char *)*puVar5 == pcVar6 + -0x29) break;
            iVar3 = iVar3 + 1;
            puVar5 = puVar5 + 5;
          } while (iVar3 < (int)uVar4);
        }
        if ((((int)uVar4 <= iVar3) && (ABS(*(float *)(pcVar6 + -0x11) - (float)puVar2[0x22]) < 0.1))
           && (ABS(*(float *)(pcVar6 + -0xd) - (float)puVar2[0x23]) < 0.1)) {
          fVar10 = (float10)FUN_005b3c50(pcVar6 + -0x1d,param_2 + 0x80,0);
          if ((float)fVar10 < local_60) {
            local_3c = *(undefined4 *)(pcVar6 + -0x1d);
            local_38 = *(float *)(pcVar6 + -0x19);
            local_5c = pcVar6 + -0x29;
            local_34 = *(undefined4 *)(pcVar6 + -0x15);
            local_50 = 1;
            local_60 = (float)fVar10;
          }
        }
      }
      pcVar6 = pcVar6 + 0x38;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  local_54 = -1;
  pcVar6 = *(char **)(param_1 + 0x50c8);
  local_68 = 16.0;
  iVar9 = 0;
  local_4c = (char *)0x0;
  if (0 < *(int *)(param_1 + 0x50c0)) {
    do {
      uVar4 = *(uint *)(pcVar6 + 0x94);
      if (((((uVar4 & 1) == 0) && ((uVar4 & 0x800000) != 0)) &&
          (((uVar4 & 0x4000) != 0 &&
           (((uVar4 & 0x8000) != 0 && ((*(uint *)(pcVar6 + 0x98) & 1) != 0)))))) &&
         (((*(uint *)(pcVar6 + 0x98) & 0x20) == 0 || (DAT_0087baf0 != 0)))) {
        uVar4 = (uint)*(byte *)(puVar2 + 0x1f);
        iVar3 = 0;
        puVar5 = puVar2;
        if (uVar4 != 0) {
          do {
            if ((char *)*puVar5 == pcVar6) break;
            iVar3 = iVar3 + 1;
            puVar5 = puVar5 + 5;
          } while (iVar3 < (int)uVar4);
        }
        if ((int)uVar4 <= iVar3) {
          if (param_3 == 0) {
            if (((ABS(*(float *)(pcVar6 + 0x40) - (float)puVar2[0x22]) < 0.1) &&
                (ABS(*(float *)(pcVar6 + 0x44) - (float)puVar2[0x23]) < 0.1)) &&
               (fVar10 = (float10)FUN_005b3c50(pcVar6 + 0x4c,param_2 + 0x80,local_30),
               pcVar8 = pcVar6, fVar10 < (float10)local_60)) break;
          }
          else {
            fVar10 = (float10)FUN_005b3c50(pcVar6 + 0x4c,param_2 + 0x80,local_30);
            if ((0.0 < local_24[0] * local_30[0] + local_1c * local_28) &&
               ((float)fVar10 < local_68)) {
              local_68 = (float)fVar10;
              local_4c = pcVar6;
            }
          }
        }
      }
      iVar9 = iVar9 + 1;
      pcVar6 = pcVar6 + 0x114;
      pcVar8 = (char *)0x0;
    } while (iVar9 < *(int *)(param_1 + 0x50c0));
    if ((local_4c != (char *)0x0) && (local_68 < local_60)) {
      pcVar8 = local_4c;
    }
    if (pcVar8 != (char *)0x0) {
      local_3c = *(undefined4 *)(pcVar8 + 0x4c);
      local_38 = *(float *)(pcVar8 + 0x50);
      local_34 = *(undefined4 *)(pcVar8 + 0x54);
      local_54 = (int)*(short *)(pcVar8 + 0x102);
      local_50 = 2;
      local_5c = pcVar8;
    }
  }
  if (local_5c != (char *)0x0) {
    local_18 = *(undefined4 *)(param_2 + 0x80);
    local_14 = (*(float *)(param_2 + 0x194) + *(float *)(param_2 + 0x84)) * 0.5;
    local_10 = *(undefined4 *)(param_2 + 0x88);
    FUN_005b3800(local_c,&local_3c,&local_18);
    iVar9 = FUN_0067b430(&local_18,local_c,0,0x3f800000,0,0x1f);
    if ((((iVar9 == 0) || ((local_54 != -1 && (iVar9 = FUN_0067fb40(), iVar9 == local_54)))) &&
        (local_50 != -1)) && (iVar9 = FUN_00403ea0(local_50), iVar9 == 2)) {
      return 1;
    }
  }
  return 0;
}

