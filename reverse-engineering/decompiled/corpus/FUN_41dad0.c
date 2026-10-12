/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41dad0; label: FUN_0041dad0
 */

/* WARNING: Removing unreachable block (ram,0x0041dee1) */
/* WARNING: Removing unreachable block (ram,0x0041def5) */
/* WARNING: Removing unreachable block (ram,0x0041def7) */
/* WARNING: Removing unreachable block (ram,0x0041df12) */
/* WARNING: Removing unreachable block (ram,0x0041df06) */
/* WARNING: Removing unreachable block (ram,0x0041df14) */

void FUN_0041dad0(int param_1,int param_2,float param_3)

{
  char cVar1;
  bool bVar2;
  short sVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  int local_154;
  int local_150;
  int local_148;
  int local_13c [5];
  float local_128;
  float local_124;
  float local_120;
  int local_110 [16];
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  int local_c0 [16];
  undefined1 local_80 [64];
  int local_40 [16];
  
  sVar3 = 0;
  local_13c[0] = -1;
  local_13c[1] = 0xffffffff;
  local_13c[2] = 0xffffffff;
  local_13c[3] = 0xffffffff;
  local_110[0] = -1;
  local_110[1] = 0xffffffff;
  local_110[2] = 0xffffffff;
  local_110[3] = 0xffffffff;
  bVar4 = false;
  if ((0.0 < param_3) &&
     ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x200000) == 0)) {
    local_148 = 0;
    do {
      local_13c[4] = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xf8 + local_148);
      if ((local_13c[4] == -1) ||
         (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + local_13c[4] * 4) == 0)) {
LAB_0041e17b:
        if ((bVar4) && (*(short *)(param_1 + 0x1064) != DAT_007f1968)) {
          return;
        }
      }
      else {
        iVar9 = 0;
        local_150 = 0;
        iVar7 = 0;
        bVar2 = false;
        iVar5 = FUN_0056e160(0xf);
        if ((iVar5 != 0) &&
           ((cVar1 = *(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116), cVar1 == '\x01'
            || (cVar1 == '\b')))) {
          local_13c[0] = 0x59;
LAB_0041dbe0:
          iVar5 = local_13c[0];
          if (*(short *)(param_1 + 0x1064) == DAT_007f19e0) {
            sVar3 = -0x2e38;
          }
          else if ((((local_13c[0] == 0x65) || (local_13c[0] == 0x67)) || (local_13c[0] == 0x69)) ||
                  (local_13c[0] == 0x6b)) {
            if (*(char *)(param_1 + 0x280) == -1) {
LAB_0041dc53:
              if (iVar5 != 0x65) {
                if (iVar5 == 0x67) {
                  iVar9 = 1;
                }
                else {
                  if (iVar5 != 0x69) goto LAB_0041dc76;
                  iVar7 = 1;
                }
              }
            }
            else {
              iVar6 = FUN_0056e160(0x19);
              if (iVar6 == 0) {
                if ((*(char *)(param_1 + 0x280) == -1) ||
                   (iVar6 = FUN_0041af30(param_1), iVar6 == 0)) goto LAB_0041dc53;
LAB_0041dc76:
                local_150 = 1;
              }
            }
            FUN_00418fb0(iVar9,iVar7,local_150);
            bVar4 = true;
          }
LAB_0041de73:
          iVar7 = 0;
          iVar9 = 0;
          do {
            if (local_13c[iVar9] != -1) {
              if (iVar9 != 3) {
                iVar7 = iVar7 + 1;
              }
              iVar5 = FUN_0057a390(local_13c[iVar9]);
              local_110[iVar9] = iVar5;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < 4);
          if (0 < iVar7) {
            piVar8 = (int *)(local_13c[4] * 0x40 + 0x804 + param_1);
            piVar10 = local_110 + 4;
            for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
              *piVar10 = *piVar8;
              piVar8 = piVar8 + 1;
              piVar10 = piVar10 + 1;
            }
            local_120 = param_3;
            local_124 = param_3;
            local_128 = param_3;
            bVar2 = false;
            if (sVar3 != 0) {
              FUN_005b4dd0(local_110 + 4,sVar3);
            }
            FUN_005b4c30(local_110 + 4,&local_128);
            piVar8 = local_110 + 4;
            piVar10 = local_40;
            for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
              *piVar10 = *piVar8;
              piVar8 = piVar8 + 1;
              piVar10 = piVar10 + 1;
            }
            local_154 = 1;
            do {
              iVar9 = 0;
              do {
                if (((!bVar2) || (local_13c[iVar9] != -1)) &&
                   (iVar7 = local_13c[iVar9], iVar7 != -1)) {
                  if (iVar9 == 3) {
                    fStack_d0 = *(float *)(param_1 + 0xc50) + fStack_d0;
                    fStack_cc = *(float *)(param_1 + 0xc54) + fStack_cc;
                    fStack_c8 = *(float *)(param_1 + 0xc58) + fStack_c8;
                  }
                  piVar8 = local_c0;
                  if (iVar7 != -1) {
                    piVar8 = local_110 + 4;
                  }
                  FUN_00552bc0(0,iVar7,piVar8);
                  if (param_2 != 0) {
                    iVar5 = local_110[iVar9];
                    if ((iVar5 == -1) ||
                       (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar5 * 0x10) == '\0')
                       ) {
                      iVar5 = iVar7;
                    }
                    iVar7 = FUN_00550490(piVar8,*(undefined1 *)(param_1 + 0x107b),
                                         *(undefined4 *)(param_1 + 0x1014),
                                         *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),
                                         local_80);
                    if (iVar7 != 0) {
                      FUN_005d4690(0);
                      FUN_00552bc0(0,iVar5,local_80);
                      FUN_005d46b0();
                    }
                  }
                }
                iVar9 = iVar9 + 1;
              } while (iVar9 < 4);
              if ((((!bVar2) && (*(short *)(param_1 + 0x1064) == DAT_007f1880)) &&
                  (*(char *)(param_1 + 0x280) != -1)) &&
                 ((iVar9 = FUN_0056e160(0x19), iVar9 != 0 ||
                  ((*(char *)(param_1 + 0x280) != -1 &&
                   ((iVar9 = FUN_0056e160(0x1c), iVar9 != 0 || (0.0 < *(float *)(param_1 + 0xdec))))
                   ))))) {
                local_120 = 1.0;
                local_128 = 1.0;
                piVar8 = local_40;
                piVar10 = local_110 + 4;
                for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
                  *piVar10 = *piVar8;
                  piVar8 = piVar8 + 1;
                  piVar10 = piVar10 + 1;
                }
                local_124 = -1.0;
                bVar2 = true;
                FUN_005b4c30(local_110 + 4,&local_128);
                local_154 = local_154 + 1;
              }
              local_154 = local_154 + -1;
            } while (0 < local_154);
          }
          goto LAB_0041e17b;
        }
        iVar5 = *(int *)(param_1 + 0x54);
        iVar6 = *(int *)(iVar5 + 0x24);
        local_13c[0] = (int)*(short *)(iVar6 + 0xec);
        if (local_13c[0] != -1) goto LAB_0041dbe0;
        if (DAT_00876580 == 0) {
          if (DAT_007f39e4 == 0) {
            if ((*(short *)(param_1 + 0x1064) == DAT_007f1810) ||
               ((*(byte *)(iVar5 + 4) & 0x80) != 0)) {
              local_13c[0] = 0xc;
            }
          }
          else if (((byte)*(undefined4 *)(iVar5 + 4) & 0x90) == 0x80) {
            local_13c[0] = 0xd;
          }
          else {
            if (*(short *)(param_1 + 0x1064) == DAT_007f19dc) {
              if ((*(uint *)(param_1 + 0xef0) & 0x200) == 0) {
LAB_0041dd53:
                iVar7 = 1;
              }
              else {
                iVar9 = 1;
              }
            }
            else {
              iVar5 = FUN_004190e0(param_1);
              if (iVar5 == 0) {
                cVar1 = *(char *)(iVar6 + 0x117);
                if (cVar1 == '\0') {
                  bVar2 = true;
                }
                else if (cVar1 == '\x01') {
                  iVar9 = 1;
                }
                else {
                  if (cVar1 == '\x02') goto LAB_0041dd53;
                  if (cVar1 != '\x03') goto LAB_0041de73;
                  local_150 = 1;
                }
              }
              else {
                iVar9 = 1;
              }
            }
            if ((*(char *)(param_1 + 0x280) == -1) || (iVar5 = FUN_0056e160(0x19), iVar5 == 0)) {
              if ((!bVar2) && (((iVar9 == 0 && (iVar7 == 0)) && (local_150 == 0))))
              goto LAB_0041de73;
              if ((*(char *)(param_1 + 0x280) == -1) || (iVar5 = FUN_0041af30(param_1), iVar5 == 0))
              {
                if ((iVar9 != 0) &&
                   ((*(short *)(param_1 + 0x1064) == DAT_007f1968 &&
                    ((local_148 == 0 || (local_148 == 3)))))) {
                  iVar9 = 0;
                  iVar7 = 1;
                }
                if ((((!bVar2) && (iVar9 == 0)) && (iVar7 == 0)) && (local_150 == 0))
                goto LAB_0041de73;
              }
              else {
                iVar9 = 0;
                local_150 = 1;
                iVar7 = 0;
              }
            }
            else {
              iVar9 = 0;
              local_150 = 0;
              iVar7 = 0;
            }
            FUN_00418fb0(iVar9,iVar7,local_150);
            bVar4 = true;
          }
          goto LAB_0041de73;
        }
        if (*(short **)(param_1 + 0x7f4) != (short *)0x0) {
          local_13c[0] = (int)**(short **)(param_1 + 0x7f4);
        }
        if (local_13c[0] != -1) goto LAB_0041de73;
      }
      local_148 = local_148 + 1;
    } while (local_148 < 4);
  }
  return;
}

