/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547dc0; label: FUN_00547dc0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547dc0(float param_1,int param_2)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_8;
  
  iVar3 = (int)param_1;
  iVar4 = *(int *)(*(int *)((int)param_1 + 0x54) + 0x24);
  iVar5 = (int)*(short *)(iVar4 + 0xe2);
  if (iVar5 != -1) {
    param_1 = 0.0;
    if (param_2 == 0) {
      if ((*(byte *)(iVar3 + 0x1fc) & 0x80) == 0) {
        param_1 = *(float *)(iVar3 + 0x228) / *(float *)(iVar4 + 0x1c);
      }
      else {
        param_1 = ABS(*(float *)(iVar3 + 0xdc8));
      }
      if (1.0 < param_1) {
        param_1 = 1.0;
      }
    }
    fVar6 = (float10)FUN_0054fad0(*(undefined4 *)(iVar3 + 0xd94),param_1,_DAT_00925018 * 0.5);
    fVar1 = (float)fVar6;
    *(float *)(iVar3 + 0xd94) = fVar1;
    local_8 = fVar1 * 0.5 + 0.5;
    if ((*(byte *)(iVar3 + 0x1fc) & 0x80) == 0) {
      local_8 = local_8 * 0.6;
    }
    bVar2 = *(byte *)(iVar3 + 0x28d);
    iVar4 = FUN_0054fa60();
    FUN_00681f10(iVar5,iVar3 + 0x80,local_8,
                 ((float)iVar4 * 1.5259022e-05 * 0.03 + 0.985) *
                 ((((float)bVar2 / 63.0) * 0.05 - 0.025) + fVar1 * 0.4 + 0.6));
  }
  return;
}

