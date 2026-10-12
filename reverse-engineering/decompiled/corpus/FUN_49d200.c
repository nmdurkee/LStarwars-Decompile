/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49d200; label: FUN_0049d200
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_0049d200(float param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int unaff_ESI;
  char cVar3;
  
  cVar3 = false;
  bVar1 = false;
  *(undefined4 *)(unaff_ESI + 0x790) = 0;
  *(undefined4 *)(unaff_ESI + 0x794) = 0;
  if ((((*(byte *)(unaff_ESI + 0x1fc) & 0x80) != 0) && (param_3 == 0)) &&
     (0.0 < *(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28))) {
    iVar2 = FUN_0049ca80();
    cVar3 = iVar2 != 0;
    *(int *)(unaff_ESI + 0x790) = iVar2;
    bVar1 = true;
  }
  if (((*(int *)(unaff_ESI + 0x790) == 0) &&
      (*(undefined4 **)(unaff_ESI + 0x39c) != (undefined4 *)0x0)) &&
     (*(float *)(unaff_ESI + 0x3a0) < param_1)) {
    _DAT_0087b89c = *(undefined4 *)(unaff_ESI + 0x3a0);
    *(undefined4 *)(unaff_ESI + 0x790) = **(undefined4 **)(unaff_ESI + 0x39c);
    cVar3 = '\x01';
    goto LAB_0049d3e0;
  }
  if ((*(byte *)(unaff_ESI + 0x1fc) & 0x80) == 0) {
    if (((*(byte *)(unaff_ESI + 0xeec) & 0x40) == 0) && (*(char *)(unaff_ESI + 0xf00) != '\x05'))
    goto LAB_0049d3e0;
    iVar2 = FUN_00569980();
    *(int *)(unaff_ESI + 0x794) = iVar2;
    if (iVar2 == 0) goto LAB_0049d3e0;
LAB_0049d31c:
    cVar3 = '\x04';
    _DAT_0087b89c = _DAT_00950bb4;
  }
  else {
    if (!bVar1) {
      iVar2 = FUN_0049ca80();
      *(int *)(unaff_ESI + 0x790) = iVar2;
      if (iVar2 != 0) {
        cVar3 = true;
      }
    }
    if (*(int *)(unaff_ESI + 0x790) == 0) {
      iVar2 = FUN_00569980();
      *(int *)(unaff_ESI + 0x794) = iVar2;
      if (iVar2 != 0) goto LAB_0049d31c;
      iVar2 = FUN_0049cfe0();
      *(int *)(unaff_ESI + 0x790) = iVar2;
      if (iVar2 != 0) {
        cVar3 = '\x02';
        _DAT_0087b89c = _DAT_0087b88c;
        goto LAB_0049d3e0;
      }
    }
    if (((bool)cVar3 == false) && (!bVar1)) {
      iVar2 = FUN_0049ca80();
      *(int *)(unaff_ESI + 0x790) = iVar2;
      if (iVar2 != 0) {
        cVar3 = '\x01';
      }
    }
  }
LAB_0049d3e0:
  if ((((param_2 != 0) && (*(int *)(unaff_ESI + 0x790) == 0)) &&
      (0.0 < *(float *)(*(int *)(unaff_ESI + 0xca4) + 0x28))) &&
     ((*(uint *)(unaff_ESI + 0xe20) & 0x200000) != 0)) {
    *(undefined2 *)(unaff_ESI + 0x5a) = *(undefined2 *)(unaff_ESI + 0xe0c);
    return cVar3;
  }
  return cVar3;
}

