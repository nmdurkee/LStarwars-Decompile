/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74d4a0; label: FUN_0074d4a0
 */

int * FUN_0074d4a0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 8);
  uVar2 = *(uint *)(in_ECX + 4);
  *param_1 = 0;
  if (uVar1 < uVar2) {
    FUN_006e9fe6();
  }
  *param_1 = in_ECX;
  param_1[1] = uVar1;
  return param_1;
}

