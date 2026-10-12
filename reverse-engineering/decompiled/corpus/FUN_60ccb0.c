/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60ccb0; label: FUN_0060ccb0
 */

void FUN_0060ccb0(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  uVar1 = *(uint *)(in_ECX + 0x18);
  puVar3 = (undefined4 *)(in_ECX + 4);
  puVar2 = puVar3;
  if (0xf < uVar1) {
    puVar2 = (undefined4 *)*puVar3;
  }
  if (puVar2 <= param_1) {
    puVar2 = puVar3;
    if (0xf < uVar1) {
      puVar2 = (undefined4 *)*puVar3;
    }
    if (param_1 < (undefined4 *)(*(int *)(in_ECX + 0x14) + (int)puVar2)) {
      if (0xf < uVar1) {
        puVar3 = (undefined4 *)*puVar3;
      }
      FUN_0060cb30(in_ECX,(int)param_1 - (int)puVar3,param_2);
      return;
    }
  }
  if (param_2 == 0xffffffff) {
    FUN_006e67be();
  }
  if (*(uint *)(in_ECX + 0x18) < param_2) {
    FUN_0060bdd0(param_2,*(undefined4 *)(in_ECX + 0x14));
  }
  else if (param_2 == 0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    *(undefined1 *)puVar3 = 0;
    return;
  }
  if (param_2 != 0) {
    puVar2 = puVar3;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      puVar2 = (undefined4 *)*puVar3;
    }
    _memcpy_s(puVar2,*(uint *)(in_ECX + 0x18),param_1,param_2);
    *(uint *)(in_ECX + 0x14) = param_2;
    if (0xf < *(uint *)(in_ECX + 0x18)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    *(undefined1 *)((int)puVar3 + param_2) = 0;
  }
  return;
}

