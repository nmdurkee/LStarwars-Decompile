/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x421320; label: FUN_00421320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00421320(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined ***)(param_1 + 8) = &PTR_PTR_007f2890;
  }
  iVar2 = DAT_00926c20;
  iVar3 = 0;
  do {
    iVar1 = *(int *)(iVar2 + **(short **)((int)&PTR_DAT_007f2710 + iVar3) * 4);
    *(int *)((int)&DAT_00855f90 + iVar3) = iVar1;
    if (iVar1 == 0) {
      *(undefined **)((int)&DAT_00855f90 + iVar3) = &DAT_007532a0;
    }
    iVar1 = *(int *)(iVar2 + **(short **)((int)&PTR_DAT_007f2714 + iVar3) * 4);
    *(int *)((int)&DAT_00855f94 + iVar3) = iVar1;
    if (iVar1 == 0) {
      *(undefined **)((int)&DAT_00855f94 + iVar3) = &DAT_007532a0;
    }
    iVar1 = *(int *)(iVar2 + **(short **)((int)&PTR_DAT_007f2718 + iVar3) * 4);
    *(int *)((int)&DAT_00855f98 + iVar3) = iVar1;
    if (iVar1 == 0) {
      *(undefined **)((int)&DAT_00855f98 + iVar3) = &DAT_007532a0;
    }
    iVar1 = *(int *)(iVar2 + **(short **)((int)&PTR_DAT_007f271c + iVar3) * 4);
    *(int *)((int)&DAT_00855f9c + iVar3) = iVar1;
    if (iVar1 == 0) {
      *(undefined **)((int)&DAT_00855f9c + iVar3) = &DAT_007532a0;
    }
    iVar1 = *(int *)(iVar2 + **(short **)((int)&PTR_DAT_007f2720 + iVar3) * 4);
    *(int *)((int)&DAT_00855fa0 + iVar3) = iVar1;
    if (iVar1 == 0) {
      *(undefined **)((int)&DAT_00855fa0 + iVar3) = &DAT_007532a0;
    }
    iVar3 = iVar3 + 0x14;
  } while (iVar3 < 0xb4);
  FUN_00420220(param_1,param_2,param_3);
  return;
}

