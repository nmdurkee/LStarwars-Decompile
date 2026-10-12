/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fbb40; label: FUN_004fbb40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fbb40(char *param_1,int *param_2,int *param_3,short param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  char cVar8;
  int iVar9;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  uint uVar10;
  undefined4 *puVar11;
  char *pcVar12;
  longlong lVar13;
  undefined8 uVar14;
  int *local_124;
  int *local_120;
  uint local_11c;
  int local_118;
  undefined4 local_114;
  uint local_110;
  int iStack_10c;
  char *local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_124;
  local_124 = param_3;
  local_120 = param_2;
  local_108 = param_1;
  local_114 = DAT_0091ee90;
  iVar3 = FUN_004fa3f0(param_1,(int)param_4,0,0);
  if (iVar3 != 0) {
    if (param_4 == 3) {
      do {
        iVar4 = FUN_004f01f0(iVar3);
      } while (iVar4 != 0);
    }
    if (DAT_0091ee9c != 0) {
      FUN_004f6de0(iVar3,DAT_0091ee9c,(int)DAT_0091ee9c >> 0x1f,0);
    }
    iVar4 = FUN_004fb550(iVar3,&local_110,8);
    while (iVar4 < 0) {
      do {
        FUN_004ef7b0();
        iVar4 = (int)DAT_0091ee9c >> 0x1f;
        if (iVar3 < 0x1000) {
          if (iVar3 < 0x400) {
            iVar5 = (iVar3 + -1) * 0x40;
            if (*(int *)(&DAT_008ceb7c + iVar5) == 0) {
              FUN_004ff430(iVar3 + -1,DAT_0091ee9c,iVar4,0);
              iVar4 = extraout_EDX;
            }
            else {
              *(uint *)(&DAT_008ceb58 + iVar5) = DAT_0091ee9c;
              *(int *)(&DAT_008ceb5c + iVar5) = iVar4;
            }
          }
          else if (iVar3 < 0x800) {
            iVar4 = iVar3 * 5 + -0x1400;
            iVar5 = DAT_0091ee9c + *(int *)(&DAT_02983740 + iVar4 * 4);
            *(int *)(&DAT_02983748 + iVar4 * 4) = iVar5;
            iVar4 = iVar5 - *(int *)(&DAT_02983740 + iVar4 * 4) >> 0x1f;
          }
          else {
            iVar5 = (iVar3 * 3 + -0x1800) * 0x10;
            puVar11 = (undefined4 *)
                      ((*(int *)(&DAT_0297dc80 + iVar5) + 3) * 0x10 +
                      *(int *)(&DAT_0297dc60 + iVar5));
            uVar14 = FUN_004f6de0(*puVar11,*(uint *)(&DAT_0297dc68 + iVar5) + DAT_0091ee9c,
                                  *(int *)(&DAT_0297dc6c + iVar5) + iVar4 +
                                  (uint)CARRY4(*(uint *)(&DAT_0297dc68 + iVar5),DAT_0091ee9c),0);
            *(undefined8 *)(&DAT_0297dc70 + iVar5) = uVar14;
            puVar11[2] = (int)uVar14;
            puVar11[3] = *(undefined4 *)(&DAT_0297dc74 + iVar5);
            iVar4 = *(int *)(&DAT_0297dc74 + iVar5);
          }
        }
        else {
          iVar4 = FUN_006dee90(iVar3 + -0x1000,DAT_0091ee9c,0,0);
          iVar4 = iVar4 >> 0x1f;
        }
      } while ((iVar4 < 1) && (iVar4 < 0));
      iVar4 = FUN_004fb550(iVar3,&local_110,8);
    }
    if (param_4 == 3) {
      do {
        iVar4 = FUN_004f01f0(iVar3);
      } while (iVar4 != 0);
    }
    iVar4 = (int)local_110 >> 0x1f;
    lVar13 = (longlong)(int)local_110;
    if ((-1 < (int)local_110 || iVar4 < 0) && (lVar13 = (longlong)(int)local_110, iVar4 < 0)) {
      lVar13 = __allmul(local_110,iVar4,0xffffff00,0xffffffff);
    }
    lVar13 = lVar13 + (int)DAT_0091ee9c;
    uVar10 = (uint)lVar13;
    local_118 = (int)((ulonglong)lVar13 >> 0x20);
    while( true ) {
      iVar4 = (int)((ulonglong)lVar13 >> 0x20);
      local_11c = (uint)lVar13;
      if (iVar3 < 0x1000) {
        if (iVar3 < 0x400) {
          iVar5 = (iVar3 + -1) * 0x40;
          if (*(int *)(&DAT_008ceb7c + iVar5) == 0) {
            FUN_004ff430(iVar3 + -1,uVar10,iVar4,0);
            lVar13 = CONCAT44(iVar4,local_11c);
            iVar4 = extraout_EDX_00;
          }
          else {
            *(uint *)(&DAT_008ceb58 + iVar5) = uVar10;
            *(int *)(&DAT_008ceb5c + iVar5) = iVar4;
          }
        }
        else if (iVar3 < 0x800) {
          iVar4 = iVar3 * 5 + -0x1400;
          iVar5 = uVar10 + *(int *)(&DAT_02983740 + iVar4 * 4);
          *(int *)(&DAT_02983748 + iVar4 * 4) = iVar5;
          iVar4 = iVar5 - *(int *)(&DAT_02983740 + iVar4 * 4) >> 0x1f;
        }
        else {
          iVar4 = (iVar3 * 3 + -0x1800) * 0x10;
          puVar11 = (undefined4 *)
                    ((*(int *)(&DAT_0297dc80 + iVar4) + 3) * 0x10 + *(int *)(&DAT_0297dc60 + iVar4))
          ;
          uVar14 = FUN_004f6de0(*puVar11,*(uint *)(&DAT_0297dc68 + iVar4) + uVar10,
                                *(int *)(&DAT_0297dc6c + iVar4) + ((int)uVar10 >> 0x1f) +
                                (uint)CARRY4(*(uint *)(&DAT_0297dc68 + iVar4),uVar10),0);
          lVar13 = CONCAT44(local_118,local_11c);
          *(undefined8 *)(&DAT_0297dc70 + iVar4) = uVar14;
          puVar11[2] = (int)uVar14;
          puVar11[3] = *(undefined4 *)(&DAT_0297dc74 + iVar4);
          iVar4 = *(int *)(&DAT_0297dc74 + iVar4);
        }
      }
      else {
        iVar5 = FUN_006dee90(iVar3 + -0x1000,uVar10,0,0);
        lVar13 = CONCAT44(iVar4,local_11c);
        iVar4 = iVar5 >> 0x1f;
      }
      local_11c = (uint)lVar13;
      if ((0 < iVar4) || (-1 < iVar4)) break;
      FUN_004ef7b0();
      lVar13 = CONCAT44((int)((ulonglong)lVar13 >> 0x20),local_11c);
    }
    if (param_4 == 3) {
      do {
        iVar4 = FUN_004f01f0(iVar3);
      } while (iVar4 != 0);
    }
    (**(code **)(PTR_DAT_00800478 + 0x22c))(PTR_DAT_00800478,local_104,local_108,0x100);
    iVar4 = 0;
    cVar8 = local_104[0];
    while (cVar8 != '\0') {
      cVar8 = local_104[iVar4 + 1];
      iVar4 = iVar4 + 1;
    }
    uVar10 = iVar4 + 0x10U & 0xfffffff0;
    iVar4 = iStack_10c + 0xc0 + uVar10;
    if (local_120 == (int *)0x0) {
      FUN_004ef790();
      FUN_004f99e0(iVar3);
    }
    else {
      piVar2 = (int *)*local_120;
      *local_120 = (int)piVar2 + iVar4;
      if (local_124 != (int *)0x0) {
        *local_124 = iVar4;
      }
      piVar6 = piVar2 + 0x30;
      *(undefined2 *)(piVar2 + 0x2c) = 0;
      piVar2[0x2e] = (int)piVar6;
      local_124 = (int *)((int)piVar2 + uVar10 + 0xc0);
      if (local_104[0] != '\0') {
        iVar4 = 1 - (int)piVar6;
        cVar8 = local_104[0];
        do {
          *(char *)piVar6 = cVar8;
          cVar8 = *(char *)((int)piVar6 + (int)(local_104 + iVar4));
          piVar6 = (int *)((int)piVar6 + 1);
        } while (cVar8 != '\0');
      }
      *(undefined1 *)piVar6 = 0;
      iVar5 = FUN_004fb550(iVar3,local_124,iStack_10c);
      uVar10 = local_11c;
      iVar4 = local_118;
      while (iVar5 < 0) {
        do {
          FUN_004ef7b0();
          if (iVar3 < 0x1000) {
            if (iVar3 < 0x400) {
              iVar5 = (iVar3 + -1) * 0x40;
              if (*(int *)(&DAT_008ceb7c + iVar5) == 0) {
                FUN_004ff430(iVar3 + -1,uVar10,iVar4,0);
                iVar5 = extraout_EDX_01;
              }
              else {
                *(uint *)(&DAT_008ceb58 + iVar5) = uVar10;
                *(int *)(&DAT_008ceb5c + iVar5) = iVar4;
                iVar5 = iVar4;
              }
            }
            else if (iVar3 < 0x800) {
              iVar5 = iVar3 * 5 + -0x1400;
              iVar9 = uVar10 + *(int *)(&DAT_02983740 + iVar5 * 4);
              *(int *)(&DAT_02983748 + iVar5 * 4) = iVar9;
              iVar5 = iVar9 - *(int *)(&DAT_02983740 + iVar5 * 4) >> 0x1f;
            }
            else {
              iVar4 = (iVar3 * 3 + -0x1800) * 0x10;
              puVar11 = (undefined4 *)
                        ((*(int *)(&DAT_0297dc80 + iVar4) + 3) * 0x10 +
                        *(int *)(&DAT_0297dc60 + iVar4));
              uVar14 = FUN_004f6de0(*puVar11,*(uint *)(&DAT_0297dc68 + iVar4) + uVar10,
                                    *(int *)(&DAT_0297dc6c + iVar4) + ((int)uVar10 >> 0x1f) +
                                    (uint)CARRY4(*(uint *)(&DAT_0297dc68 + iVar4),uVar10),0);
              *(undefined8 *)(&DAT_0297dc70 + iVar4) = uVar14;
              puVar11[2] = (int)uVar14;
              puVar11[3] = *(undefined4 *)(&DAT_0297dc74 + iVar4);
              iVar5 = *(int *)(&DAT_0297dc74 + iVar4);
              iVar4 = local_118;
              uVar10 = local_11c;
            }
          }
          else {
            iVar5 = FUN_006dee90(iVar3 + -0x1000,uVar10,0,0);
            iVar5 = iVar5 >> 0x1f;
          }
        } while ((iVar5 < 1) && (iVar5 < 0));
        iVar5 = FUN_004fb550(iVar3,local_124,iStack_10c);
      }
      if (param_4 == 3) {
        do {
          iVar4 = FUN_004f01f0(iVar3);
        } while (iVar4 != 0);
      }
      *piVar2 = *local_124;
      iVar4 = local_124[1];
      piVar6 = local_124 + 2;
      piVar2[2] = (int)piVar6;
      piVar6 = piVar6 + iVar4 * 4;
      piVar2[1] = iVar4;
      iVar4 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar2[4] = (int)piVar6;
      piVar2[3] = iVar4;
      piVar2[5] = piVar6[iVar4 * 2];
      piVar6 = piVar6 + iVar4 * 2 + 1;
      piVar2[6] = (int)piVar6;
      if (0 < iVar4) {
        iVar4 = 0;
        do {
          piVar1 = (int *)(piVar2[4] + 4 + iVar4 * 8);
          *piVar1 = *piVar1 + (int)piVar6;
          iVar4 = iVar4 + 1;
        } while (iVar4 < piVar2[3]);
      }
      *(undefined4 *)(piVar2[4] + 4) = 0;
      iVar4 = (int)piVar6 + piVar2[5];
      piVar2[7] = 0;
      piVar2[8] = 0;
      piVar2[9] = 0;
      piVar2[10] = 0;
      if (*piVar2 < -1) {
        piVar2[7] = iVar4;
        iVar5 = piVar2[1] * 4;
        piVar2[8] = *(int *)(iVar4 + iVar5);
        pcVar7 = (char *)(iVar4 + iVar5 + 8);
        piVar2[9] = *(int *)(iVar4 + iVar5 + 4);
        piVar2[10] = (int)pcVar7;
        if (0 < piVar2[8]) {
          iVar4 = piVar2[8];
          do {
            iVar9 = 0;
            cVar8 = *pcVar7;
            while (cVar8 != '\0') {
              iVar9 = iVar9 + 1;
              cVar8 = pcVar7[iVar9];
            }
            pcVar7 = pcVar7 + iVar9 + 1;
            if (((uint)pcVar7 & 1) != 0) {
              pcVar7 = pcVar7 + 1;
            }
            pcVar7 = pcVar7 + 2;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        iVar4 = piVar2[4];
        FUN_004ef660(iVar4,piVar2[7],iVar5);
        piVar2[7] = iVar4;
        iVar4 = iVar4 + piVar2[1] * 4;
        if (piVar2[9] != 0) {
          piVar2[10] = iVar4;
          FUN_004ef660(iVar4,iVar4,piVar2[9]);
          iVar4 = iVar4 + piVar2[9];
        }
        *local_120 = iVar4;
        piVar2[4] = 0;
        piVar2[3] = 0;
        piVar2[5] = 0;
        piVar2[6] = 0;
      }
      piVar2[0xd] = -1;
      piVar2[0x11] = -1;
      piVar2[0x10] = 0;
      piVar2[0x12] = 0;
      piVar2[0x13] = 0;
      piVar2[0x15] = -1;
      piVar2[0x14] = 0;
      piVar2[0x16] = 0;
      piVar2[0x17] = 0;
      piVar2[0x19] = -1;
      piVar2[0x18] = 0;
      piVar2[0x1a] = 0;
      piVar2[0x1b] = 0;
      piVar2[0x1d] = -1;
      piVar2[0x1c] = 0;
      piVar2[0x1e] = 0;
      piVar2[0x1f] = 0;
      piVar2[0x21] = -1;
      piVar2[0x20] = 0;
      piVar2[0x22] = 0;
      piVar2[0x23] = 0;
      piVar2[0x25] = -1;
      piVar2[0x24] = 0;
      piVar2[0x26] = 0;
      piVar2[0x27] = 0;
      piVar2[0x29] = -1;
      piVar2[0x28] = 0;
      piVar2[0x2a] = 0;
      piVar2[0x2b] = 0;
      piVar2[0xc] = iVar3;
      piVar2[0xe] = 0;
      piVar2[0xf] = 0;
      *(short *)((int)piVar2 + 0xb2) = param_4;
      if ((DAT_00800474 != 0) && (*(int *)PTR_DAT_00800478 == 2)) {
        pcVar7 = local_104;
        cVar8 = '\\';
        iVar3 = 0x75a205 - (int)pcVar7;
        do {
          *pcVar7 = cVar8;
          cVar8 = pcVar7[iVar3];
          pcVar7 = pcVar7 + 1;
        } while (cVar8 != '\0');
        *pcVar7 = '\0';
        pcVar12 = PTR_DAT_00800478 + 0xac;
        pcVar7 = local_104;
        cVar8 = local_104[0];
        while (cVar8 != '\0') {
          pcVar7 = pcVar7 + 1;
          cVar8 = *pcVar7;
        }
        if (pcVar12 != (char *)0x0) {
          do {
            *pcVar7 = *pcVar12;
            cVar8 = *pcVar12;
            pcVar7 = pcVar7 + 1;
            pcVar12 = pcVar12 + 1;
          } while (cVar8 != '\0');
        }
        pcVar7 = local_104;
        cVar8 = local_104[0];
        while (cVar8 != '\0') {
          pcVar7 = pcVar7 + 1;
          cVar8 = *pcVar7;
        }
        pcVar12 = local_108;
        if (local_108 != (char *)0x0) {
          do {
            cVar8 = *pcVar12;
            *pcVar7 = cVar8;
            pcVar7 = pcVar7 + 1;
            pcVar12 = pcVar12 + 1;
          } while (cVar8 != '\0');
        }
        pcVar12 = ";1";
        pcVar7 = local_104;
        while (local_104[0] != '\0') {
          pcVar7 = pcVar7 + 1;
          local_104[0] = *pcVar7;
        }
        do {
          cVar8 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        } while (cVar8 != '\0');
      }
      piVar2[0x2d] = 0;
    }
  }
  DAT_0091ee90 = local_114;
  __security_check_cookie(local_4 ^ (uint)&local_124);
  return;
}

