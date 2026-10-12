/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ef280; label: FUN_004ef280
 */

void FUN_004ef280(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *_Memory;
  uint uVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  int *piVar5;
  
  if (DAT_0088ab28 != 0) {
    FUN_004eeda0();
  }
  if (param_1 == 0) {
    FUN_004eedc0(param_2,param_3);
    return;
  }
  _Memory = (int *)(param_1 + -0x20);
  piVar5 = (int *)(*(int *)(param_1 + -0x10) + param_1);
  uVar1 = 0xc;
  pcVar3 = s_MEMBLKTAIL01_00800454;
  piVar4 = piVar5;
  do {
    if (*piVar4 != *(int *)pcVar3) goto LAB_004ef2d9;
    uVar1 = uVar1 - 4;
    pcVar3 = (char *)((int)pcVar3 + 4);
    piVar4 = piVar4 + 1;
  } while (3 < uVar1);
  if (uVar1 != 0) {
LAB_004ef2d9:
    if ((char)*piVar4 == (char)*(int *)pcVar3) {
      if (uVar1 == 1) goto LAB_004ef33b;
      if (*(char *)((int)piVar4 + 1) == *(char *)((int)pcVar3 + 1)) {
        if (uVar1 == 2) goto LAB_004ef33b;
        if (*(char *)((int)piVar4 + 2) == *(char *)((int)pcVar3 + 2)) {
          if ((uVar1 == 3) || (*(char *)((int)piVar4 + 3) == *(char *)((int)pcVar3 + 3)))
          goto LAB_004ef33b;
        }
      }
    }
    FUN_004eedc0(param_2,param_3,piVar5);
  }
LAB_004ef33b:
  uVar1 = 0xc;
  pcVar3 = s_MEMBLKHEADER_00800444;
  piVar4 = (int *)(param_1 + -0xc);
  do {
    if (*piVar4 != *(int *)pcVar3) goto LAB_004ef368;
    uVar1 = uVar1 - 4;
    pcVar3 = (char *)((int)pcVar3 + 4);
    piVar4 = piVar4 + 1;
  } while (3 < uVar1);
  if (uVar1 != 0) {
LAB_004ef368:
    if ((char)*piVar4 == (char)*(int *)pcVar3) {
      if (uVar1 == 1) goto LAB_004ef3ca;
      if (*(char *)((int)piVar4 + 1) == *(char *)((int)pcVar3 + 1)) {
        if (uVar1 == 2) goto LAB_004ef3ca;
        if (*(char *)((int)piVar4 + 2) == *(char *)((int)pcVar3 + 2)) {
          if ((uVar1 == 3) || (*(char *)((int)piVar4 + 3) == *(char *)((int)pcVar3 + 3)))
          goto LAB_004ef3ca;
        }
      }
    }
    FUN_004eedc0(param_2,param_3,(int *)(param_1 + -0xc));
  }
LAB_004ef3ca:
  iVar2 = *_Memory;
  if (iVar2 == 0) {
    if (*(int *)(param_1 + -0x1c) == 0) {
      FUN_004eedc0(param_2,param_3);
    }
    iVar2 = *_Memory;
    if (iVar2 == 0) goto LAB_004ef3f3;
  }
  *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(param_1 + -0x1c);
LAB_004ef3f3:
  if (*(int **)(param_1 + -0x1c) == (int *)0x0) {
    DAT_0088ab18 = *_Memory;
  }
  else {
    **(int **)(param_1 + -0x1c) = *_Memory;
  }
  DAT_0088ab1c = DAT_0088ab1c - *(int *)(param_1 + -0x10);
  *_Memory = 0;
  *(undefined4 *)(param_1 + -0x1c) = 0;
  if (DAT_0088ab2c != 0) {
    FUN_004efb00(DAT_0088ab2c);
    return;
  }
  _free(_Memory);
  return;
}

