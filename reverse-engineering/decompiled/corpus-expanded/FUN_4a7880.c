/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a7880; label: FUN_004a7880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a7880(int param_1)

{
  char cVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  float local_10;
  float local_c;
  
  if ((DAT_007f39e4 != 0) && (DAT_00876580 == 0)) {
    return;
  }
  uVar6 = *(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000;
  if (uVar6 == 0) {
    local_10 = 0.25;
    local_c = 0.125;
    fVar3 = 0.625;
  }
  else {
    local_10 = 0.15;
    local_c = 0.1;
    fVar3 = 0.5;
  }
  if (((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x4000000) == 0) &&
     (uVar6 == 0)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  if ((((*(char *)(param_1 + 0x283) == '\x01') || (*(char *)(param_1 + 0x283) == '\x06')) &&
      (*(float *)(param_1 + 0x17c) < *(float *)(param_1 + 0x220))) &&
     (fVar4 = *(float *)(param_1 + 0x17c) -
              (*(float *)(param_1 + 0x60) - *(float *)(param_1 + 0x90)),
     *(float *)(param_1 + 0x220) < fVar4 != (*(float *)(param_1 + 0x220) == fVar4))) {
    if (*(float *)(param_1 + 0x6c) < -1.0) {
      FUN_0062c610(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0xd,*(undefined4 *)(param_1 + 0x80),
                   *(undefined4 *)(param_1 + 0x220),*(undefined4 *)(param_1 + 0x88));
    }
    FUN_0054ab40(param_1);
  }
  cVar1 = *(char *)(param_1 + 0x7b5);
  cVar2 = *(char *)(param_1 + 0x283);
  if (cVar1 != 'K') {
    if (cVar2 != '\x01') {
      if (cVar2 != '\x06') {
        return;
      }
      if (!bVar5) {
        return;
      }
    }
    if (*(float *)(param_1 + 0x220) <=
        (*(float *)(param_1 + 0x188) - *(float *)(param_1 + 0x17c)) * local_10 +
        *(float *)(param_1 + 0x17c)) {
      return;
    }
    if ((cVar1 == '\0') && (0.0 < *(float *)(param_1 + 0x6c))) {
      return;
    }
    if (cVar1 == '[') {
      return;
    }
    *(undefined1 *)(param_1 + 0x7b5) = 0x4b;
    if ((*(int *)(param_1 + 0xcbc) != 0) &&
       ((*(byte *)(*(int *)(param_1 + 0xcbc) + 0xc) & 0x10) != 0)) {
      *(float *)(param_1 + 0x6c) = *(float *)(param_1 + 0x6c) * 0.25;
    }
    FUN_004a7840();
    *(undefined4 *)(param_1 + 0x77c) = 0;
    FUN_0058d930(param_1,0);
    FUN_0054ab40(param_1);
    FUN_004a25b0(param_1,0);
    return;
  }
  fVar4 = *(float *)(param_1 + 0x77c) + _DAT_00925018;
  *(float *)(param_1 + 0x77c) = fVar4;
  if ((cVar2 != '\x06') || (bVar5)) {
    if ((cVar2 == '\x01') || (cVar2 == '\x06')) {
      if (((((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) != 0) || (fVar4 < 0.6)) ||
          ((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802278) == 0)) ||
         (*(float *)(param_1 + 0x194) - *(float *)(param_1 + 0x220) <=
          (*(float *)(param_1 + 0x194) - *(float *)(param_1 + 0x1a0)) * local_c)) {
        if ((*(char *)(param_1 + 0x281) != '\0') &&
           (*(float *)(param_1 + 0x220) <
            (*(float *)(param_1 + 0x188) - *(float *)(param_1 + 0x17c)) * fVar3 +
            *(float *)(param_1 + 0x17c))) {
          *(undefined1 *)(param_1 + 0x7b5) = 0xff;
          goto LAB_004a7b26;
        }
        if ((*(float *)(param_1 + 0x188) - *(float *)(param_1 + 0x17c)) * local_10 +
            *(float *)(param_1 + 0x17c) <= *(float *)(param_1 + 0x220)) goto LAB_004a7b26;
        uVar10 = *(undefined4 *)(param_1 + 0x88);
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        uVar9 = *(undefined4 *)(param_1 + 0x220);
        uVar7 = *(undefined4 *)(PTR_DAT_00802c54 + 0x134);
        uVar8 = *(undefined4 *)(param_1 + 0x80);
      }
      else {
        FUN_00561ba0(param_1,0);
        uVar10 = *(undefined4 *)(param_1 + 0x88);
        *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x1000;
        uVar9 = *(undefined4 *)(param_1 + 0x220);
        uVar8 = *(undefined4 *)(param_1 + 0x80);
        uVar7 = *(undefined4 *)(PTR_DAT_00802c54 + 0x134);
      }
      FUN_0062c610(uVar7,0xd,uVar8,uVar9,uVar10);
    }
    else {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
LAB_004a7b26:
  if (*(char *)(param_1 + 0x7b5) == -1) {
    FUN_0054ab40(param_1);
    return;
  }
  if (*(char *)(param_1 + 0x7b5) != 'K') {
    return;
  }
  FUN_004a7840();
  return;
}

