/* Ghidra analysis pseudocode, not original source.
 * ev_f48dedfde503d95163bfd3eb2ed6449a9a2f0083b079fa518a64f4b7b72b2f93
 * Entry: 0x447ac0; label: FUN_00447ac0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00447ac0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  ushort *puVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float10 fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  float fVar13;
  undefined1 local_c [12];
  
  if (((param_3 == 0) || (piVar3 = *(int **)(param_3 + 0xd0), piVar3 == (int *)0x0)) ||
     (*piVar3 == 0)) {
    return 1;
  }
  iVar4 = *piVar3;
  DAT_00876cd0 = 1;
  if (param_6 != 0) {
    iVar8 = 0;
    if (0 < param_5) {
      do {
        iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),"goalrange");
        if (iVar6 == 0) {
          iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),"range");
          if (iVar6 != 0) {
            iVar6 = iVar6 + 6;
            goto LAB_00447b56;
          }
          iVar6 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar8 * 4),"jediGoodie_attack");
          if (iVar6 == 0) {
            *(undefined1 *)(param_2 + 0x69) = 1;
          }
          else {
            iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),"attack_override");
            if (iVar6 != 0) {
              iVar6 = iVar6 + 0x10;
              iVar7 = FUN_004f8b10(iVar6,"PUNCH_1");
              if (iVar7 == 0) {
                *(undefined2 *)(param_2 + 0x6a) = 1;
              }
              else {
                iVar7 = FUN_004f8b10(iVar6,"PUNCH_2");
                if (iVar7 == 0) {
                  *(undefined2 *)(param_2 + 0x6a) = 2;
                }
                else {
                  iVar7 = FUN_004f8b10(iVar6,"PUNCH_3");
                  if (iVar7 == 0) {
                    *(undefined2 *)(param_2 + 0x6a) = 3;
                  }
                  else {
                    iVar7 = FUN_004f8b10(iVar6,"PUNCH_BEHIND");
                    if (iVar7 == 0) {
                      *(undefined2 *)(param_2 + 0x6a) = 4;
                    }
                    else {
                      iVar7 = FUN_004f8b10(iVar6,"PUNCH_SPECIAL");
                      if (iVar7 == 0) {
                        *(undefined2 *)(param_2 + 0x6a) = 5;
                      }
                      else {
                        iVar7 = FUN_004f8b10(iVar6,"BLOCK");
                        if (iVar7 == 0) {
                          *(undefined2 *)(param_2 + 0x6a) = 6;
                        }
                        else {
                          iVar6 = FUN_004f8b10(iVar6,"SHOOT");
                          *(ushort *)(param_2 + 0x6a) = (-(ushort)(iVar6 != 0) & 0xfff9) + 7;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else {
          iVar6 = iVar6 + 10;
LAB_00447b56:
          fVar9 = (float10)FUN_005147c0(param_2,iVar6);
          *(float *)(param_3 + 0x180) = (float)fVar9;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < param_5);
    }
    *(undefined4 *)(param_2 + 0x70) = 0x3e4ccccd;
  }
  if (*(short *)(param_2 + 0x6a) != 0) {
    *(undefined1 *)(iVar4 + 0x1085) = *(undefined1 *)(param_2 + 0x6a);
  }
  piVar3 = *(int **)(param_3 + 0xe4);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  if (piVar3[1] == 0) {
    return 0;
  }
  iVar8 = *piVar3;
  *(uint *)(iVar4 + 0xeec) = *(uint *)(iVar4 + 0xeec) | 0x20;
  uVar5 = *(uint *)(iVar8 + 0x1fc);
  if ((uVar5 & 1) == 0) {
    return 0;
  }
  if ((uVar5 & 0x1000) == 0) {
    return 0;
  }
  if (*(char *)(iVar8 + 0x28b) != '\0') {
    return 0;
  }
  if (*(char *)(iVar8 + 0x7b5) == '+') {
    return 0;
  }
  if (((char)uVar5 < '\0') && (1.5 < *(float *)(iVar8 + 0x1000))) {
    return 0;
  }
  iVar6 = iVar8 + 0x5c;
  fVar9 = (float10)FUN_005b3c50(iVar6,*(int *)(param_3 + 0xd0) + 0x5c,local_c);
  if ((*(uint *)(iVar4 + 0xef4) & 0x2000) != 0) {
    iVar7 = FUN_0043d410(iVar4,**(undefined4 **)(iVar4 + 0x3ac));
    if (iVar7 == 0) {
      fVar10 = (float10)FUN_0043d450(iVar4);
      *(float *)(param_3 + 0x180) = (float)fVar10;
      *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 2;
    }
    else {
      *(undefined4 *)(param_3 + 0x180) = 0;
      *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) & 0xfd;
    }
  }
  if ((*(byte *)(param_2 + 0x68) & 2) == 0) {
    fVar13 = *(float *)(iVar8 + 1000) + *(float *)(param_3 + 0x180) + *(float *)(param_3 + 0x120);
    uVar12 = 1;
    uVar11 = 0;
  }
  else {
    fVar13 = *(float *)(param_3 + 0x180) - _DAT_007f682c;
    if ((float)fVar9 < fVar13 * fVar13) {
      fVar13 = *(float *)(param_3 + 0x180);
      uVar12 = 2;
      uVar11 = *(undefined4 *)(param_3 + 0x120);
    }
    else {
      fVar13 = _DAT_007f682c + *(float *)(param_3 + 0x180);
      if ((float)fVar9 <= fVar13 * fVar13) {
        *(int *)(param_3 + 0x1e4) = iVar6;
        goto LAB_00447e4e;
      }
      fVar13 = *(float *)(param_3 + 0x180);
      uVar12 = 1;
      uVar11 = *(undefined4 *)(param_3 + 0x120);
    }
  }
  FUN_0052fcb0(param_3,iVar8 + 0x438,uVar11,iVar8 + 0x420,uVar12,fVar13);
  *(undefined1 *)(param_3 + 0x13f) = 0;
LAB_00447e4e:
  if (*(float *)(param_2 + 0x70) <= 0.0) {
    puVar1 = (ushort *)(*(int *)(iVar4 + 0xca4) + 0x5a);
    *puVar1 = *puVar1 | 2;
  }
  else {
    if (*(char *)(iVar8 + 0x7b5) == 'Z') {
      return 0;
    }
    fVar9 = (float10)FUN_005b3c50(iVar6,*(int *)(param_3 + 0xd0) + 0x5c,local_c);
    fVar13 = *(float *)(iVar8 + 1000) + *(float *)(param_2 + 0x70) + *(float *)(iVar4 + 1000);
    if (fVar13 * fVar13 <= (float)fVar9) {
      return 0;
    }
  }
  puVar2 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
  *puVar2 = *puVar2 | DAT_0080227c;
  if (*(char *)(param_2 + 0x69) != '\0') {
    *(uint *)(iVar4 + 0xeec) = *(uint *)(iVar4 + 0xeec) | 0x400;
  }
  return 0;
}

