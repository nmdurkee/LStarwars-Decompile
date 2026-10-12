/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74be00; label: FUN_0074be00
 */

void FUN_0074be00(int param_1)

{
  uint uVar1;
  int *in_ECX;
  
  if (*in_ECX == 0) {
    FUN_006e9fe6();
  }
  uVar1 = in_ECX[1] + param_1 * 4;
  if ((*(uint *)(*in_ECX + 8) < uVar1) || (uVar1 < *(uint *)(*in_ECX + 4))) {
    FUN_006e9fe6();
  }
  in_ECX[1] = in_ECX[1] + param_1 * 4;
  return;
}

