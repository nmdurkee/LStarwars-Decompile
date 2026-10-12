/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x605090; label: FUN_00605090
 */

void FUN_00605090(int param_1)

{
  uint uVar1;
  int *in_ECX;
  
  if (*in_ECX == 0) {
    FUN_006e9fe6();
  }
  uVar1 = in_ECX[1] + param_1 * 8;
  if ((*(uint *)(*in_ECX + 8) < uVar1) || (uVar1 < *(uint *)(*in_ECX + 4))) {
    FUN_006e9fe6();
  }
  in_ECX[1] = in_ECX[1] + param_1 * 8;
  return;
}

