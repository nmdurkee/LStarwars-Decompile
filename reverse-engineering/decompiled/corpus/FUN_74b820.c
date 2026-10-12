/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x74b820; label: FUN_0074b820
 */

void FUN_0074b820(int param_1)

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

