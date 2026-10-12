/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60d260; label: FUN_0060d260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0060d260(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x1fffffff < param_1) {
    uVar1 = FUN_0060d1a0();
  }
  iVar2 = FUN_00605220(param_1,uVar1);
  *(int *)(in_ECX + 4) = iVar2;
  *(int *)(in_ECX + 8) = iVar2;
  iVar2 = iVar2 + param_1 * 8;
  *(int *)(in_ECX + 0xc) = iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}

