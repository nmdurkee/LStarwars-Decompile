/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fa740; label: FUN_004fa740
 */

int FUN_004fa740(int *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == (int *)0x0) {
    return -1;
  }
  iVar2 = FUN_004f9aa0(param_1,param_2);
  if (iVar2 < 0) {
    return -1;
  }
  iVar6 = iVar2 * 0x10;
  uVar3 = *(uint *)(param_1[2] + iVar6);
  uVar4 = (int)uVar3 >> 0x1f;
  if (*param_1 < -1) {
    uVar4 = uVar4 << 8 | uVar3 >> 0x18;
    uVar3 = uVar3 << 8;
  }
  iVar5 = ((int)DAT_0091ee9c >> 0x1f) + uVar4 + (uint)CARRY4(DAT_0091ee9c,uVar3);
  if ((DAT_00800474 != 0) && (iVar1 = param_1[0x2d], iVar1 != 0)) {
    if (param_3 != (int *)0x0) {
      iVar5 = __alldiv(DAT_0091ee9c + uVar3,iVar5,0x800,0);
      iVar5 = iVar5 + iVar1;
      *param_3 = iVar5;
      param_3[1] = iVar5 >> 0x1f;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(param_1[2] + 4 + iVar6);
    }
    return iVar2;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = DAT_0091ee9c + uVar3;
    param_3[1] = iVar5;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1[2] + 4 + iVar6);
  }
  return iVar2;
}

