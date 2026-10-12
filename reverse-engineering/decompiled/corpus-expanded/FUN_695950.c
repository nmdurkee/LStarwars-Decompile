/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x695950; label: FUN_00695950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00695950(float param_1)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int *piVar6;
  float local_14;
  float fStack_10;
  float fStack_c;
  int local_8;
  
  if (in_ECX == 0) {
    return;
  }
  if (DAT_02962b8c == 0) {
    return;
  }
  if (*(float *)(in_ECX + 0x1a0) != *(float *)(in_ECX + 0x19c)) {
    if (*(float *)(in_ECX + 0x1a0) <= *(float *)(in_ECX + 0x19c)) {
      fVar2 = *(float *)(in_ECX + 0x19c) - param_1 * *(float *)(in_ECX + 0x1a4);
      *(float *)(in_ECX + 0x19c) = fVar2;
      if (fVar2 <= *(float *)(in_ECX + 0x1a0)) goto LAB_006959fc;
    }
    else {
      fVar2 = param_1 * *(float *)(in_ECX + 0x1a4) + *(float *)(in_ECX + 0x19c);
      *(float *)(in_ECX + 0x19c) = fVar2;
      if (*(float *)(in_ECX + 0x1a0) < fVar2 != (*(float *)(in_ECX + 0x1a0) == fVar2)) {
LAB_006959fc:
        *(undefined4 *)(in_ECX + 0x1a4) = 0;
        *(undefined4 *)(in_ECX + 0x19c) = *(undefined4 *)(in_ECX + 0x1a0);
      }
    }
  }
  uVar1 = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x1a8) = 0x3f800000;
  *(undefined4 *)(in_ECX + 0x1b0) = 0x3f800000;
  iVar3 = *(int *)(in_ECX + 0x134 + *(int *)(in_ECX + 0x144) * 4);
  if ((iVar3 != 0) && (*(int *)(in_ECX + 0x148) == 7)) {
    if (*(float *)(iVar3 + 0x2c) <= 1.0) {
      uVar1 = *(undefined4 *)(iVar3 + 0x2c);
    }
    *(undefined4 *)(in_ECX + 0x1a8) = uVar1;
    fVar2 = 1.0 / *(float *)(iVar3 + 0x30);
    if (fVar2 <= 1.0) {
      fVar2 = 1.0;
    }
    *(float *)(in_ECX + 0x1b0) = fVar2;
  }
  iVar3 = *(int *)(in_ECX + 0x168 + *(int *)(in_ECX + 0x178) * 4);
  if ((iVar3 != 0) && (*(int *)(in_ECX + 0x17c) == 7)) {
    if (*(float *)(iVar3 + 0x2c) <= *(float *)(in_ECX + 0x1a8)) {
      uVar1 = *(undefined4 *)(iVar3 + 0x2c);
    }
    else {
      uVar1 = *(undefined4 *)(in_ECX + 0x1a8);
    }
    *(undefined4 *)(in_ECX + 0x1a8) = uVar1;
    fVar2 = 1.0 / *(float *)(iVar3 + 0x30);
    if (fVar2 <= *(float *)(in_ECX + 0x1b0)) {
      fVar2 = *(float *)(in_ECX + 0x1b0);
    }
    *(float *)(in_ECX + 0x1b0) = fVar2;
  }
  if (*(float *)(in_ECX + 0x1ac) <= *(float *)(in_ECX + 0x1a8)) {
    if (*(float *)(in_ECX + 0x1a8) <= *(float *)(in_ECX + 0x1ac)) goto LAB_00695b5b;
    fVar2 = *(float *)(in_ECX + 0x1b0) * param_1 + *(float *)(in_ECX + 0x1ac);
    if (*(float *)(in_ECX + 0x1a8) < fVar2) goto LAB_00695b4d;
  }
  else {
    fVar2 = *(float *)(in_ECX + 0x1ac) - *(float *)(in_ECX + 0x1b0) * param_1;
    if (fVar2 < *(float *)(in_ECX + 0x1a8)) {
LAB_00695b4d:
      fVar2 = *(float *)(in_ECX + 0x1a8);
    }
  }
  *(float *)(in_ECX + 0x1ac) = fVar2;
LAB_00695b5b:
  local_8 = 2;
  piVar6 = (int *)(in_ECX + 0x130);
  do {
    iVar3 = piVar6[piVar6[5] + 1];
    if (param_1 != 0.0) {
      iVar4 = FUN_006984c0(*piVar6 * 2);
      if ((piVar6[6] == 7) && ((float)piVar6[10] != 0.0)) {
        fVar2 = (float)piVar6[10] * param_1 + (float)piVar6[7];
        piVar6[7] = (int)fVar2;
        local_14 = fVar2;
        if (1.0 < fVar2) {
          local_14 = 1.0;
        }
        if (0.0 <= local_14) {
          local_14 = fVar2;
          if (1.0 < fVar2) {
            local_14 = 1.0;
          }
        }
        else {
          local_14 = 0.0;
        }
        piVar6[7] = (int)local_14;
        if (local_14 == 0.0) {
          piVar6[10] = 0;
          if ((*(byte *)(piVar6 + 0xc) & 1) == 0) {
            if (*(int *)(iVar3 + 0x1c) == 0) {
              FUN_00698440(*piVar6 * 2);
              if (piVar6[6] != 3) {
                piVar6[6] = 3;
                piVar6[0xb] = 0;
              }
            }
            else {
              iVar5 = FUN_006953b0(2,*piVar6,3,
                                   *(undefined4 *)(iVar3 + 0xc + piVar6[piVar6[5] + 3] * 4),9,0,6,0,
                                   10,(double)*(float *)(iVar3 + 0x24),1);
              piVar6[9] = 0;
              FUN_00693e10();
              if ((iVar5 != 0) && (piVar6[6] != 4)) {
                piVar6[6] = 4;
                piVar6[0xb] = 0;
              }
            }
          }
          else {
            FUN_00698400(*piVar6 * 2);
            if (piVar6[6] != 0) {
              piVar6[0xb] = 0;
              piVar6[6] = 0;
            }
            piVar6[0xc] = piVar6[0xc] & 0xfffffffe;
          }
        }
        else if (local_14 == 1.0) {
          piVar6[10] = 0;
        }
      }
      switch(piVar6[6]) {
      case 0:
        if (iVar4 == 0) {
          piVar6[0xb] = 0;
          piVar6[6] = 1;
          piVar6[10] = 0;
          piVar6[5] = 0;
          piVar6[7] = 0;
          piVar6[1] = 0;
        }
        break;
      case 4:
        if (iVar4 == 2) {
          piVar6[0xb] = 0;
          piVar6[6] = 5;
        }
        else if ((iVar4 == 0) && (0.25 < (float)piVar6[0xb])) {
          piVar6[0xb] = 0;
          piVar6[6] = 5;
        }
        break;
      case 5:
        if (iVar4 != 2) {
          piVar6[0xb] = 0;
          piVar6[6] = 3;
        }
        break;
      case 6:
        if (iVar4 == 1) {
          piVar6[0xb] = 0;
          piVar6[6] = 7;
        }
        break;
      case 7:
        if (iVar4 == 0) {
          piVar6[0xb] = 0;
          piVar6[6] = 3;
          if ((piVar6[piVar6[5] + 1] != 0) &&
             (FUN_00698400(*piVar6 * 2), *(int *)(piVar6[piVar6[5] + 1] + 0x14) == 8)) {
            FUN_00695640();
          }
        }
      }
      local_14 = *(float *)(in_ECX + 0x1ac);
      fStack_10 = 1.0;
      fStack_c = 1.0;
      if (iVar3 != 0) {
        if (((*(byte *)(iVar3 + 0x38) & 1) != 0) || (*(float *)(iVar3 + 0x2c) != 1.0)) {
          local_14 = 1.0;
        }
        iVar4 = 0;
        do {
          if (*(int *)(iVar3 + 0x14) == 1 << ((byte)iVar4 & 0x1f)) goto LAB_00695dfe;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 6);
        iVar4 = -1;
LAB_00695dfe:
        fStack_10 = *(float *)(in_ECX + 0x1b4 + iVar4 * 4);
        fStack_c = *(float *)(iVar3 + 0x34);
      }
      fVar2 = *(float *)(in_ECX + 0x198) * local_14 * (float)piVar6[7] * fStack_10 *
              *(float *)(in_ECX + 0x19c) * fStack_c * *(float *)(in_ECX + 0x1cc);
      piVar6[8] = (int)fVar2;
      if (fVar2 != (float)piVar6[9]) {
        FUN_006e6b90();
        FUN_00698460();
        piVar6[9] = piVar6[8];
      }
    }
    local_8 = local_8 + -1;
    piVar6[0xb] = (int)(param_1 + (float)piVar6[0xb]);
    piVar6 = piVar6 + 0xd;
    if (local_8 == 0) {
      if (_DAT_00810bf0 == 1.0) {
        return;
      }
      *(float *)(in_ECX + 0x1ac) = _DAT_00810bf0;
      return;
    }
  } while( true );
}

