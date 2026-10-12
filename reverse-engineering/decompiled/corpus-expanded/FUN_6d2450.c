/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d2450; label: FUN_006d2450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d2450(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar3 = 0;
  local_8 = 0;
  local_4 = 0;
  if (DAT_02974644 == -1) {
    FUN_006d1d10(0xffffffff);
    return 1;
  }
  DAT_02973aa0 = DAT_02974644;
  piVar1 = *(int **)(*param_1 + 0x14);
  if ((*(uint *)(*param_1 + 4) & 0x4000000) == 0) {
    if (DAT_02973b9c != (code *)0x0) {
      uVar3 = (*DAT_02973b9c)();
    }
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[1];
    if (DAT_02973b9c != (code *)0x0) {
      uVar3 = (*DAT_02973b9c)();
    }
  }
  iVar2 = (**(code **)(*piVar1 + 0x18))(iVar2,4,2);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x28))(iVar2,uVar3);
    if ((*(uint *)(*param_1 + 4) & 0x4000000) == 0) {
      FUN_006c6700(iVar2,param_1[1]);
      (**(code **)(**(int **)(unaff_EDI + 0x14) + 0x34))(iVar2,param_1[1]);
    }
    else {
      local_8 = 0x4000000;
      FUN_006c87f0(1,DAT_02973ab0,&local_8,0);
    }
    FUN_006c9840(&stack0xffffffe8);
    FUN_006be910(iVar2,unaff_EDI,0,0,0,0);
    FUN_006c9bf0(&stack0xffffffe8,0);
    return 1;
  }
  return 0;
}

