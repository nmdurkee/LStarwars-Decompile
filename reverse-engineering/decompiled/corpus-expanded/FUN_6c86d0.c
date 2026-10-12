/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c86d0; label: FUN_006c86d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006c86d0(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBP;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(code **)(in_ECX + 0x14) != (code *)0x0) {
    uVar2 = (**(code **)(in_ECX + 0x14))();
  }
  iVar1 = (**(code **)(*param_1 + 0x18))(param_2,4,param_3);
  if ((iVar1 != 0) && ((**(code **)(*param_1 + 0x28))(iVar1,uVar2), (param_3 & 2) == 0)) {
    FUN_006be910(iVar1,param_1[1],unaff_EBP,4,uVar2,param_3);
  }
  return iVar1;
}

