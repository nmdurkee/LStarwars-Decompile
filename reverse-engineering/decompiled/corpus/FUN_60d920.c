/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60d920; label: FUN_0060d920
 */

void FUN_0060d920(undefined4 param_1)

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
    FUN_0060c030(iVar2,1,param_1);
    *(int *)(in_ECX + 8) = iVar2 + 8;
    return;
  }
  uVar3 = *(uint *)(in_ECX + 8);
  if (uVar3 < uVar1) {
    FUN_006e9fe6();
  }
  FUN_0060d800(local_8,in_ECX,uVar3,param_1);
  return;
}

