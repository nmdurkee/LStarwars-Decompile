/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x599740; label: FUN_00599740
 */

undefined4 FUN_00599740(float param_1,float param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  iVar2 = (int)param_1;
  *(undefined4 *)((int)param_1 + 0xf18) = 0;
  *(undefined4 *)((int)param_1 + 0xf20) = 0;
  if (param_2 <= 0.0) {
    return 0;
  }
  cVar1 = *(char *)((int)param_1 + 0x7b3);
  if (((cVar1 == '\x03') || (cVar1 == '\x01')) && (*(short *)((int)param_1 + 0x7aa) != -1)) {
    iVar4 = *(int *)((int)param_1 + 0x50);
    iVar3 = (int)*(short *)((int)param_1 + 0x7aa);
    if (*(int *)(*(int *)(iVar4 + 0xc) + iVar3 * 4) == 0) goto LAB_005997a4;
LAB_00599790:
    fVar5 = (float10)FUN_0062f1c0(iVar4,iVar3);
    param_1 = (float)fVar5;
  }
  else {
LAB_005997a4:
    if (cVar1 != '\x03') {
      if (cVar1 != '\x06') {
        return 0;
      }
      if (DAT_00804ca4 != 0) {
        iVar4 = *(int *)((int)param_1 + 0x50);
        iVar3 = (int)DAT_00804ca4;
        if (*(int *)(*(int *)(iVar4 + 0xc) + iVar3 * 4) != 0) goto LAB_00599790;
      }
    }
    param_1 = *(float *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x1c) * 0.5;
  }
  if (param_1 <= 0.0) {
    return 0;
  }
  *(float *)(iVar2 + 0xf18) = (float)(&DAT_029899a0)[*(ushort *)(iVar2 + 0x58) >> 1] * param_1;
  *(float *)(iVar2 + 0xf20) =
       param_1 * (float)(&DAT_029899a0)[(int)(*(ushort *)(iVar2 + 0x58) + 0x4000) >> 1 & 0x7fff];
  return 0;
}

