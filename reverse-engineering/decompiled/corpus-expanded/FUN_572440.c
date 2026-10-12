/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x572440; label: FUN_00572440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00572440(int param_1,int param_2,float param_3)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 local_4;
  
  if (param_3 == 2e+06) {
    iVar5 = 0;
    *(undefined4 *)(param_1 + 0x1014) = 0x49f42400;
    local_4 = 0;
    *(undefined1 *)(param_1 + 0x107b) = 0;
    *(undefined2 *)(param_1 + 0x106c) = 0xffff;
  }
  else {
    iVar3 = FUN_0067a600();
    if ((iVar3 < 0) || (iVar5 = iVar3, 0x1f < iVar3)) {
      iVar5 = 0;
    }
    *(undefined1 *)(param_1 + 0x107b) = 2;
    if (((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x8000) != 0) ||
       (((&DAT_008034cc)[iVar5 * 0xc] & 2) == 0)) {
      param_3 = 2e+06;
    }
    *(float *)(param_1 + 0x1014) = param_3;
    uVar2 = FUN_0067a6e0();
    *(undefined2 *)(param_1 + 0x106c) = uVar2;
    local_4 = (undefined1)iVar3;
  }
  if (param_2 != 0) {
    *(undefined1 *)(param_1 + 0xe42) = local_4;
    *(char *)(param_1 + 0x285) = (char)iVar5;
    if (*(float *)(param_1 + 0x21c) == 2e+06) {
      *(undefined4 *)(param_1 + 0xf24) = DAT_00802500;
      *(undefined4 *)(param_1 + 0xf28) = DAT_00802504;
      uVar4 = DAT_00802508;
    }
    else {
      *(undefined4 *)(param_1 + 0xf24) = DAT_0292fdb8;
      *(undefined4 *)(param_1 + 0xf28) = DAT_0292fdbc;
      uVar4 = DAT_0292fdc0;
    }
    *(undefined4 *)(param_1 + 0xf2c) = uVar4;
  }
  *(undefined4 *)(param_1 + 0x220) = _DAT_02920d84;
  if (*(float *)(param_1 + 0x220) != 2e+06) {
    cVar1 = FUN_0067a670();
    *(char *)(param_1 + 0x283) = cVar1;
    if (((DAT_00951288 == 0) || (DAT_00951154 == 0)) || ((cVar1 != '\a' && (cVar1 != '\x10')))) {
      if ((cVar1 < '\0') || ('\x10' < cVar1)) {
        *(undefined1 *)(param_1 + 0x283) = 0;
      }
      *(byte *)(param_1 + 0x283) =
           *(byte *)(param_1 + 0x283) & ~((byte)DAT_008034c4 | (byte)DAT_0095100c | 0x40);
      FUN_0054fec0(&DAT_02962000,0,0);
      *(undefined2 *)(param_1 + 0x105c) = DAT_0092b0c4;
      *(undefined2 *)(param_1 + 0x105e) = DAT_0092b0c0;
      goto LAB_005725ac;
    }
    *(undefined4 *)(param_1 + 0x220) = 0x49f42400;
  }
  *(undefined2 *)(param_1 + 0x105e) = 0;
  *(undefined2 *)(param_1 + 0x105c) = 0;
  *(undefined1 *)(param_1 + 0x283) = 0xff;
LAB_005725ac:
  *(undefined4 *)(param_1 + 0x224) = _DAT_02921864;
  if (*(float *)(param_1 + 0x224) == 2e+06) {
    *(undefined1 *)(param_1 + 0x284) = 0xff;
  }
  else {
    cVar1 = FUN_0067a690();
    *(char *)(param_1 + 0x284) = cVar1;
    if ((cVar1 < '\0') || ('\x1f' < cVar1)) {
      *(undefined1 *)(param_1 + 0x284) = 0;
    }
  }
  if (DAT_00951010 != (code *)0x0) {
    (*DAT_00951010)(param_1);
  }
  return;
}

