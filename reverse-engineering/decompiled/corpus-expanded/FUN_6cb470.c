/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cb470; label: FUN_006cb470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cb470(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  *(int *)(in_ECX + 0x3c) = param_3;
  if (param_3 != 0) {
    *(uint *)(in_ECX + 0xa5c) = *param_1 + 0xfU & 0xfffffff0;
    iVar2 = (*param_1 + 0xfU & 0xfffffff0) + 0x20000;
    *param_1 = iVar2;
    *(int *)(in_ECX + 0xa60) = iVar2;
  }
  DAT_0081fa74 = 0;
  _DAT_0081fa78 = *(undefined4 *)(in_ECX + 0x940);
  if (*(int *)(in_ECX + 0x940) != 0) {
    *(undefined ***)(*(int *)(in_ECX + 0x940) + 4) = &PTR_PTR_0081fa70;
  }
  *(undefined ***)(in_ECX + 0x940) = &PTR_PTR_0081fa70;
  if (*(int *)(in_ECX + 0x93c) == 0) {
    *(undefined ***)(in_ECX + 0x93c) = &PTR_PTR_0081fa70;
  }
  *(int *)(in_ECX + 0x944) = *(int *)(in_ECX + 0x944) + 1;
  for (piVar1 = *(int **)(in_ECX + 0x93c); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    (**(code **)(*piVar1 + 4))(param_1,param_2,param_3);
  }
  *(undefined ***)(in_ECX + 0x948) = &PTR_PTR_0081fa70;
  for (piVar1 = DAT_02973af4; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    (**(code **)(*piVar1 + 4))(param_1,param_2,param_3);
  }
  DAT_02973a6c = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02973a6c + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_02973a6c + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_02973a6c + 0x5c) = 0x3f000000;
  *(uint *)(DAT_02973a6c + 0x40) = *(uint *)(DAT_02973a6c + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02973a6c + 0x40) = *(uint *)(DAT_02973a6c + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02973a6c + 0x70) = 0x3f800000;
  *(uint *)(DAT_02973a6c + 0x40) = *(uint *)(DAT_02973a6c + 0x40) & 0xfffffff1 | 1;
  *(uint *)(DAT_02973a6c + 0x40) = *(uint *)(DAT_02973a6c + 0x40) | 0x40000;
  FUN_005e4b00(DAT_02973a6c);
  DAT_02973a70 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02973a70 + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_02973a70 + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_02973a70 + 0x5c) = 0x3f000000;
  *(undefined4 *)(DAT_02973a70 + 0x70) = 0x3f800000;
  *(uint *)(DAT_02973a70 + 0x40) = *(uint *)(DAT_02973a70 + 0x40) & 0xfffffff0;
  *(uint *)(DAT_02973a70 + 0x40) = *(uint *)(DAT_02973a70 + 0x40) & 0xfffeffff | 0x20000;
  *(uint *)(DAT_02973a70 + 0x40) = *(uint *)(DAT_02973a70 + 0x40) | 0x40000;
  FUN_005e4b00(DAT_02973a70);
  DAT_02973a74 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02973a74 + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_02973a74 + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_02973a74 + 0x5c) = 0x3f000000;
  *(uint *)(DAT_02973a74 + 0x40) = *(uint *)(DAT_02973a74 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02973a74 + 0x40) = *(uint *)(DAT_02973a74 + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02973a74 + 0x70) = 0x3f800000;
  *(uint *)(DAT_02973a74 + 0x40) = *(uint *)(DAT_02973a74 + 0x40) & 0xfffffff0;
  *(uint *)(DAT_02973a74 + 0x40) = *(uint *)(DAT_02973a74 + 0x40) | 0x40000;
  FUN_005e4b00(DAT_02973a74);
  FUN_005d1740(DAT_02973a78);
  FUN_005d1750(DAT_0081f99c,DAT_0081f99c);
  FUN_006ba6a0(0);
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  return;
}

