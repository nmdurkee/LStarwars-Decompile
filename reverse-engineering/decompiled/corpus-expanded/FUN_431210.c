/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x431210; label: FUN_00431210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00431210(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  float10 extraout_ST0;
  float10 fVar11;
  float10 extraout_ST0_00;
  undefined8 uVar12;
  uint local_73c;
  uint local_738;
  uint local_734;
  uint local_730;
  uint local_72c;
  uint local_728;
  int local_724;
  int *local_720;
  int local_71c;
  float local_718;
  float local_714;
  float local_710;
  undefined4 *local_70c;
  undefined4 *local_708;
  undefined4 local_704;
  int local_700 [64];
  undefined4 local_600 [192];
  undefined4 local_300 [192];
  
  local_724 = 0;
  local_738 = 0;
  local_73c = 0;
  local_72c = 0;
  local_734 = 0;
  local_728 = 0;
  local_730 = 0;
  if ((*(int *)(param_1 + 0x120) == -1) || ((*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 0x80) == 0)
     ) {
    fVar11 = (float10)0;
    if (0 < DAT_0093d500) {
      piVar9 = (int *)(DAT_0093d504 + 0x54);
      iVar8 = DAT_0093d500;
      do {
        uVar6 = piVar9[0x6a];
        if ((uVar6 & 1) != 0) {
          uVar12 = __allshl();
          local_704 = (undefined4)((ulonglong)uVar12 >> 0x20);
          uVar4 = (uint)uVar12;
          if ((char)piVar9[0x8b] != -1) {
            local_738 = local_738 | uVar4;
          }
          if ((float10)*(float *)(*(int *)(*piVar9 + 0x24) + 0x28) <= extraout_ST0) {
            local_72c = local_72c | uVar4;
          }
          else {
            local_73c = local_73c | uVar4;
          }
          uVar6 = uVar6 >> 7 & 1;
          if (((uVar6 != 0) || ((piVar9[0x3a8] & 0x80000U) != 0)) &&
             ((*(byte *)(*(int *)(*piVar9 + 0x24) + 0x90) & 0x40) == 0)) {
            local_734 = local_734 | uVar4;
          }
          if ((*(char *)((int)piVar9 + 0x761) == '=') && (uVar6 == 0)) {
            local_728 = local_728 | uVar4;
          }
          fVar11 = extraout_ST0;
          if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) && (DAT_009253a4 == 0)) &&
             (((short)piVar9[0x404] == DAT_007f1948 && ((char)piVar9[0x8b] != -1)))) {
            local_730 = local_730 | uVar4;
          }
        }
        piVar9 = piVar9 + 0x436;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    local_720 = local_700;
    puVar10 = local_300;
    puVar7 = local_600;
    local_71c = 0;
    iVar8 = DAT_0093d504;
    if (0 < DAT_0093d500) {
      do {
        if ((((((*(uint *)(iVar8 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0))
             && (*(char *)(iVar8 + 0x28b) == '\0')) &&
            ((*(char *)(iVar8 + 0x288) != '\0' && (1 < *(byte *)(iVar8 + 0x1079))))) &&
           (((((cVar1 = *(char *)(iVar8 + 0x7b5),
               (*(uint *)(PTR_PTR_007fb0e4 + cVar1 * 0x10 + 8) & 0x8000) == 0 &&
               ((cVar1 != ';' && (cVar1 != '<')))) && (cVar1 != '\x0f')) &&
             ((cVar1 != '9' &&
              (((cVar1 != '&' || (*(char *)(iVar8 + 0x7b7) == -1)) ||
               ((*(uint *)(iVar8 + 0x7bc) & 0x200) == 0)))))) &&
            (((cVar1 != '\x1f' || (*(char *)(iVar8 + 0x7b3) != '\x01')) &&
             (((*(uint *)(*(int *)(*(int *)(iVar8 + 0x54) + 0x24) + 0x90) & 0x8000) == 0 &&
              (((*(byte *)(iVar8 + 0xe20) & 0x20) == 0 &&
               ((cVar1 != 'G' || ((*(byte *)(*(int *)(iVar8 + 0x798) + 0x68) & 1) == 0)))))))))))) {
          *puVar10 = *(undefined4 *)(iVar8 + 0x178);
          local_724 = local_724 + 1;
          puVar10[1] = *(undefined4 *)(iVar8 + 0x17c);
          puVar10[2] = *(undefined4 *)(iVar8 + 0x180);
          *puVar7 = *(undefined4 *)(iVar8 + 0x184);
          puVar7[1] = *(undefined4 *)(iVar8 + 0x188);
          uVar2 = *(undefined4 *)(iVar8 + 0x18c);
          *local_720 = iVar8;
          puVar7[2] = uVar2;
          local_720 = local_720 + 1;
          *(undefined4 *)(iVar8 + 0x2a0) = 0;
          *(undefined4 *)(iVar8 + 0x2a4) = 0;
          local_708 = puVar10 + 3;
          local_70c = puVar7 + 3;
          if ((*(uint *)(*(int *)(*(int *)(iVar8 + 0x54) + 0x24) + 0x90) & 0x1000) != 0) {
            *(uint *)(iVar8 + 0x2a0) = local_728;
            *(undefined4 *)(iVar8 + 0x2a4) = 0;
          }
          if (*(short *)(iVar8 + 0x1070) != -1) {
            *(uint *)(iVar8 + 0x2a0) = *(uint *)(iVar8 + 0x2a0) | local_734;
            *(undefined4 *)(iVar8 + 0x2a4) = *(undefined4 *)(iVar8 + 0x2a4);
            piVar9 = &DAT_0093d7f0;
            do {
              iVar3 = *piVar9;
              if ((((iVar3 != 0) && ((*(uint *)(iVar3 + 0x1fc) & 1) != 0)) &&
                  ((*(uint *)(iVar3 + 0x1fc) & 0x1000) != 0)) &&
                 (((iVar8 != iVar3 && (fVar11 < (float10)*(float *)(iVar3 + 0xdc4))) &&
                  (*(short *)(iVar3 + 0x27e) == *(short *)(iVar8 + 0x1070))))) {
                if (*(short *)(iVar3 + 0x106c) == *(short *)(iVar8 + 0x1070)) {
                  if (*(char *)(iVar3 + 0x281) == '\0') {
                    iVar5 = FUN_0055d130(iVar3,0x40400000,0);
                    fVar11 = (float10)0;
                    if (iVar5 == 0) goto LAB_00431579;
                  }
                }
                else {
LAB_00431579:
                  local_718 = *(float *)(iVar8 + 0x80) - *(float *)(iVar3 + 0x80);
                  local_714 = (float)fVar11;
                  local_710 = *(float *)(iVar8 + 0x88) - *(float *)(iVar3 + 0x88);
                  FUN_005b3b30(&local_718,&local_718);
                  *(float *)(iVar8 + 0x200) = local_718;
                  *(float *)(iVar8 + 0x208) = local_710;
                  fVar11 = (float10)0;
                }
              }
              piVar9 = piVar9 + 1;
            } while ((int)piVar9 < 0x93d810);
          }
          puVar10 = local_708;
          puVar7 = local_70c;
          if ((*(char *)(iVar8 + 0x7b5) == '\0') && (*(int *)(iVar8 + 0xd1c) != 0)) {
            uVar12 = __allshl();
            *(uint *)(iVar8 + 0x2a0) = *(uint *)(iVar8 + 0x2a0) | (uint)uVar12;
            *(uint *)(iVar8 + 0x2a4) = *(uint *)(iVar8 + 0x2a4) | (uint)((ulonglong)uVar12 >> 0x20);
            fVar11 = extraout_ST0_00;
          }
          if ((((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) && (DAT_009253a4 == 0)) &&
              (*(short *)(iVar8 + 0x1064) == DAT_007f1948)) && (*(char *)(iVar8 + 0x280) != -1)) {
            *(uint *)(iVar8 + 0x2a0) = *(uint *)(iVar8 + 0x2a0) | local_730;
            *(undefined4 *)(iVar8 + 0x2a4) = *(undefined4 *)(iVar8 + 0x2a4);
          }
          if (((DAT_00951288 != 0) && (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b0e4)) &&
             (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b0f8)) {
            if (*(char *)(iVar8 + 0x280) == -1) {
              if (fVar11 == (float10)*(float *)(*(int *)(*(int *)(iVar8 + 0x54) + 0x24) + 0x28)) {
                *(uint *)(iVar8 + 0x2a0) = *(uint *)(iVar8 + 0x2a0) | ~local_738 & local_73c;
              }
              else {
                *(uint *)(iVar8 + 0x2a0) =
                     *(uint *)(iVar8 + 0x2a0) | local_73c & local_738 | local_72c;
              }
            }
            else if (fVar11 == (float10)*(float *)(*(int *)(*(int *)(iVar8 + 0x54) + 0x24) + 0x28))
            {
              *(uint *)(iVar8 + 0x2a0) = *(uint *)(iVar8 + 0x2a0) | ~local_738 & local_73c;
            }
            else {
              *(uint *)(iVar8 + 0x2a0) = *(uint *)(iVar8 + 0x2a0) | local_73c;
            }
            *(undefined4 *)(iVar8 + 0x2a4) = *(undefined4 *)(iVar8 + 0x2a4);
          }
        }
        local_71c = local_71c + 1;
        iVar8 = iVar8 + 0x10d8;
      } while (local_71c < DAT_0093d500);
    }
    FUN_0062c030(local_724,local_700,local_300,local_600,FUN_00430f20);
  }
  return;
}

