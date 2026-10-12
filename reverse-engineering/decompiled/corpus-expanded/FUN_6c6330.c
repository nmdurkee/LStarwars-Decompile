/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c6330; label: FUN_006c6330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006c6330(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  
  if ((param_4 == 0) && (*(code **)(in_ECX + 0x14) != (code *)0x0)) {
    param_4 = (**(code **)(in_ECX + 0x14))();
  }
  iVar1 = (**(code **)(*param_1 + 0x18))(param_2,param_3,param_5);
  if ((iVar1 != 0) && ((**(code **)(*param_1 + 0x28))(iVar1,param_4), (param_5 & 2) == 0)) {
    FUN_006be910(iVar1,param_1[1],unaff_EBP,unaff_EBX,param_4,param_5);
  }
  return iVar1;
}

