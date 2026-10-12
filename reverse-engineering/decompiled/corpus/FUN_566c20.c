/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x566c20; label: FUN_00566c20
 */

void FUN_00566c20(int param_1)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  undefined4 uVar4;
  
  iVar1 = param_1;
  if (param_1 == 0) {
    return;
  }
  FUN_00566ba0();
  if (((DAT_00951154 == 0) || (DAT_00951288 == 0)) || ((*(uint *)(iVar1 + 0x98) & 0x1000000) == 0))
  {
    if ((*(uint *)(iVar1 + 0x94) & 0x4000) == 0) goto LAB_00566c96;
    iVar2 = *(int *)(iVar1 + 0xa4);
    uVar4 = 1;
  }
  else {
    iVar2 = FUN_005cfac0(*(int *)(iVar1 + 0xa4) + 0x30);
    if (iVar2 == 0) goto LAB_00566c96;
    iVar2 = *(int *)(iVar1 + 0xa4);
    uVar4 = 0;
  }
  FUN_005cfc00(iVar2 + 0x30,uVar4);
LAB_00566c96:
  iVar2 = FUN_005cfac0(*(int *)(iVar1 + 0xa4) + 0x3c);
  if (iVar2 != 0) {
    FUN_005cfc00(*(int *)(iVar1 + 0xa4) + 0x3c,0);
  }
  *(undefined4 *)(iVar1 + 0xbc) = 0;
  *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) & 0xfdf1e401;
  *(undefined1 *)(iVar1 + 0x10e) = *(undefined1 *)(iVar1 + 0x10f);
  *(undefined1 *)(iVar1 + 0x110) = *(undefined1 *)(iVar1 + 0x111);
  iVar2 = FUN_005d0420(*(int *)(iVar1 + 0xa4) + 0x30);
  if (iVar2 != 0) {
    if (((DAT_00951154 != 0) && (DAT_00951288 != 0)) &&
       (((*(uint *)(iVar1 + 0x98) & 0x1000000) != 0 && ((*(uint *)(iVar1 + 0x94) & 0x100000) != 0)))
       ) {
      *(uint *)(iVar2 + 0x50) = *(uint *)(iVar2 + 0x50) | 1;
    }
    if (((*(uint *)(iVar2 + 0x50) & 1) != 0) && ((*(uint *)(iVar2 + 0x50) & 8) != 0)) {
      *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) | 0x480000;
    }
  }
  if (*(short *)(iVar1 + 0x102) != -1) {
    FUN_0067c8e0((int)*(short *)(iVar1 + 0x102),1);
  }
  iVar2 = 0xa4;
  do {
    psVar3 = (short *)(*(int *)(iVar1 + 0xa4) + iVar2);
    if (*psVar3 != -1) {
      param_1 = 0xffffffff;
      FUN_00690460(&param_1,(int)*psVar3,iVar1 + 0x4c,1);
    }
    iVar2 = iVar2 + 2;
  } while (iVar2 < 0xa8);
  return;
}

