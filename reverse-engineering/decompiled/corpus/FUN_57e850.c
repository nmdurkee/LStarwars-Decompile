/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x57e850; label: FUN_0057e850
 */

void FUN_0057e850(int param_1,char *param_2,int param_3,int param_4)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  char *_Format;
  
  if (DAT_00951cb0 == (int *)0x0) {
    if (param_2 != (char *)0x0) {
      FUN_004f1f10(param_2,&DAT_00755ba8);
    }
    if (param_3 == 0) {
      return;
    }
    FUN_004f1f10(param_3,&DAT_00755ba8);
    return;
  }
  if (param_2 == (char *)0x0) goto switchD_0057e8f1_default;
  if (DAT_00951cb0[3] == 0) {
    _Format = "Clip %i";
  }
  else {
    _Format = *(char **)(DAT_00926c20 + *(short *)DAT_00951cb0[3] * 4);
  }
  _sprintf(param_2,_Format,param_1 + 1);
  if (param_4 == 0) goto switchD_0057e8f1_default;
  switch(*(undefined1 *)(*DAT_00951cb0 + 2 + param_1 * 0x44)) {
  case 0:
    if (DAT_00951cb0[4] == 0) goto switchD_0057e8f1_default;
    FUN_004f1e80(param_2,&DAT_007587cc);
    psVar2 = (short *)DAT_00951cb0[4];
    goto LAB_0057e982;
  case 1:
    if (DAT_00951cb0[5] == 0) goto switchD_0057e8f1_default;
    FUN_004f1e80(param_2,&DAT_007587cc);
    uVar4 = *(undefined4 *)(DAT_00926c20 + *(short *)DAT_00951cb0[5] * 4);
    break;
  case 2:
    if (DAT_00951cb0[6] == 0) goto switchD_0057e8f1_default;
    FUN_004f1e80(param_2,&DAT_007587cc);
    uVar4 = *(undefined4 *)(DAT_00926c20 + *(short *)DAT_00951cb0[6] * 4);
    break;
  case 3:
    if (DAT_00951cb0[7] == 0) goto switchD_0057e8f1_default;
    FUN_004f1e80(param_2,&DAT_007587cc);
    psVar2 = (short *)DAT_00951cb0[7];
LAB_0057e982:
    uVar4 = *(undefined4 *)(DAT_00926c20 + *psVar2 * 4);
    break;
  default:
    goto switchD_0057e8f1_default;
  }
  FUN_004f1e80(param_2,uVar4);
switchD_0057e8f1_default:
  if (param_3 == 0) {
    return;
  }
  iVar3 = *(short *)(*DAT_00951cb0 + param_1 * 0x44) * 0x130 + DAT_00951b78;
  iVar1 = (int)*(char *)(iVar3 + 0xa3);
  if (iVar1 != -1) {
    iVar1 = iVar1 * 0x9c + DAT_00951354;
    if ((*(byte *)(iVar1 + 0x7a) & 2) == 0) {
      FUN_004f1f10(param_3,*(undefined4 *)(DAT_00926c20 + *(short *)(iVar1 + 0x78) * 4));
      return;
    }
    iVar1 = (int)*(char *)(iVar3 + 0xa2);
    if (iVar1 != -1) {
      FUN_004f1f10(param_3,*(undefined4 *)
                            (DAT_00926c20 + *(short *)(DAT_00956290 + 2 + iVar1 * 0x1c) * 4));
      return;
    }
  }
  FUN_004f1f10(param_3,&DAT_00755ba8);
  return;
}

