/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60d890; label: FUN_0060d890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060d890(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  uint local_8 [2];
  
  uVar1 = *(uint *)(in_ECX + 4);
  if ((uVar1 != 0) &&
     ((uint)((int)(*(int *)(in_ECX + 8) - uVar1) >> 3) <
      (uint)((int)(*(int *)(in_ECX + 0xc) - uVar1) >> 3))) {
    iVar2 = *(int *)(in_ECX + 8);
    local_8[0] = local_8[0] & 0xffffff00;
    FUN_0060bfa0(iVar2,1,param_1);
    *(int *)(in_ECX + 8) = iVar2 + 8;
    return;
  }
  uVar3 = *(uint *)(in_ECX + 8);
  if (uVar3 < uVar1) {
    FUN_006e9fe6();
  }
  FUN_0060d770(local_8,in_ECX,uVar3,param_1);
  return;
}

