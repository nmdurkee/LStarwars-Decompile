/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f3140; label: FUN_005f3140
 */

int * FUN_005f3140(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)*param_2;
  iVar1 = *piVar2;
  if (0x414e4934 < piVar2[1]) {
    piVar2 = (int *)FUN_004f4f40(piVar2);
    return piVar2;
  }
  if ((iVar1 != 0x414e4933) && (iVar1 != 0x414e4934)) {
    if (iVar1 != 2) {
      FUN_005c12e0();
    }
    *piVar2 = param_1;
    iVar1 = *param_2;
    uVar3 = FUN_005e91f0(*(undefined4 *)(iVar1 + 8),iVar1 - *(int *)(iVar1 + 4),0,0);
    *(undefined4 *)(*param_2 + 8) = uVar3;
    *(int *)(*param_2 + 4) = *param_2;
    return *(int **)(*param_2 + 8);
  }
  FUN_005ca320(piVar2,piVar2,0);
  return piVar2;
}

