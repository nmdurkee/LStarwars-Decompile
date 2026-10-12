/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74dc20; label: FUN_0074dc20
 */

void FUN_0074dc20(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int in_ECX;
  undefined1 local_8 [8];
  
  uVar1 = *(uint *)(in_ECX + 4);
  if ((uVar1 != 0) &&
     ((uint)((int)(*(int *)(in_ECX + 8) - uVar1) >> 2) <
      (uint)((int)(*(int *)(in_ECX + 0xc) - uVar1) >> 2))) {
    puVar2 = *(undefined4 **)(in_ECX + 8);
    *puVar2 = *param_1;
    *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
    return;
  }
  uVar3 = *(uint *)(in_ECX + 8);
  if (uVar3 < uVar1) {
    FUN_006e9fe6();
  }
  FUN_0074db00(local_8,in_ECX,uVar3,param_1);
  return;
}

