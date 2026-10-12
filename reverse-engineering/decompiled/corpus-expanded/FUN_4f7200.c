/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f7200; label: FUN_004f7200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f7200(int param_1,int param_2)

{
  int iVar1;
  int extraout_ECX;
  int iVar2;
  undefined8 uVar3;
  
  if (param_2 != 0) {
    iVar1 = DAT_0091ee80;
    if (DAT_0091eea8 <= DAT_0091ee80) {
      iVar1 = FUN_004ef790();
      param_2 = extraout_ECX;
    }
    *(int *)(iVar1 * 0x10 + DAT_0091eeac) = param_2;
    uVar3 = FUN_004f6d10(param_1);
    iVar1 = DAT_0091eeac;
    iVar2 = DAT_0091ee80 * 0x10;
    *(int *)(iVar2 + 8 + DAT_0091eeac) = (int)uVar3;
    DAT_0091ee80 = DAT_0091ee80 + 1;
    *(int *)(iVar2 + 0xc + iVar1) = (int)((ulonglong)uVar3 >> 0x20);
  }
  if (0xfff < param_1) {
    FUN_006dee60(param_1 + -0x1000,&DAT_0091eeb4,4,0);
    return;
  }
  if (0x3ff < param_1) {
    FUN_004f0380(param_1);
    return;
  }
  FUN_004ff3f0(param_1 + -1,&DAT_0091eeb4,4);
  return;
}

