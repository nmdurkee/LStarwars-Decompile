/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x5728a0; label: FUN_005728a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005728a0(int param_1)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  float10 fVar5;
  
  fVar5 = (float10)FUN_005506f0(param_1,param_1 + 0x5c,0x40a00000,0xffffffff);
  fVar1 = (float)fVar5;
  *(float *)(param_1 + 0x21c) = fVar1;
  if (fVar1 == 2e+06) {
    FUN_00572440(param_1,0,fVar1);
    *(undefined4 *)(param_1 + 0xd6c) = 0;
    *(undefined1 *)(param_1 + 0x285) = 0;
    *(undefined1 *)(param_1 + 0xe42) = 0;
    *(undefined4 *)(param_1 + 0xf24) = DAT_00802500;
    *(undefined4 *)(param_1 + 0xf28) = DAT_00802504;
    *(undefined4 *)(param_1 + 0xf2c) = DAT_00802508;
  }
  else {
    FUN_00572440(param_1,1,fVar1);
    if (((&DAT_008034cc)[*(char *)(param_1 + 0x285) * 0xc] & 8) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 0x3f800000;
    }
    *(undefined4 *)(param_1 + 0xd6c) = uVar3;
    FUN_0054fec0(param_1 + 0xf24,0,0);
    *(undefined2 *)(param_1 + 0x1056) = DAT_0092b0c4;
    *(undefined2 *)(param_1 + 0x1052) = DAT_0092b0c4;
    *(undefined2 *)(param_1 + 0x1058) = DAT_0092b0c0;
    *(undefined2 *)(param_1 + 0x1054) = DAT_0092b0c0;
  }
  cVar2 = *(char *)(param_1 + 0x283);
  if (((cVar2 != '\x01') && (cVar2 != '\t')) ||
     (*(float *)(param_1 + 0x220) < *(float *)(param_1 + 0x84))) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  *(undefined1 *)(param_1 + 0x286) = uVar4;
  if ((cVar2 == '\x01') || (cVar2 == '\t')) {
    if (*(float *)(param_1 + 0x220) <= *(float *)(param_1 + 0x188)) {
      if (*(float *)(param_1 + 0x17c) <= *(float *)(param_1 + 0x220)) {
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0;
  }
  *(undefined4 *)(param_1 + 0x220) = 0x49f42400;
  *(undefined1 *)(param_1 + 0x287) = uVar4;
  *(undefined4 *)(param_1 + 0x224) = 0x49f42400;
  *(undefined1 *)(param_1 + 0x283) = 0xff;
  *(undefined1 *)(param_1 + 0x284) = 0xff;
  FUN_00572440(param_1,1,*(undefined4 *)(param_1 + 0x21c));
  if ((((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x8000) == 0) &&
      (*(float *)(param_1 + 0x1014) == 2e+06)) && (*(short *)(param_1 + 0x106c) != -1)) {
    fVar5 = (float10)FUN_00553500(param_1 + 0x5c);
    if ((float)fVar5 != 2e+06) {
      *(float *)(param_1 + 0x1014) = (float)fVar5;
      *(undefined1 *)(param_1 + 0x107b) = 2;
    }
  }
  if (DAT_00951010 != (code *)0x0) {
    (*DAT_00951010)(param_1);
  }
  return;
}

