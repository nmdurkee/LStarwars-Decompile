/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74c800; label: FUN_0074c800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0074c800(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  iVar2 = in_ECX[1];
  *param_1 = iVar1;
  param_1[1] = iVar2;
  if (iVar1 == 0) {
    FUN_006e9fe6();
  }
  if (*(uint *)(*in_ECX + 8) <= (uint)in_ECX[1]) {
    FUN_006e9fe6();
  }
  in_ECX[1] = in_ECX[1] + 4;
  return param_1;
}

