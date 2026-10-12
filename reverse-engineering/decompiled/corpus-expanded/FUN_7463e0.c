/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x7463e0; label: FUN_007463e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_007463e0(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = in_ECX[1];
  if (0 < iVar1) {
    if (*(char *)(iVar1 + -1 + *in_ECX) == '\0') {
      return *in_ECX;
    }
    if (in_ECX[2] < iVar1 + 1) {
      FUN_007484e0((iVar1 * 3 + 3) / 2);
    }
    *(undefined1 *)(*in_ECX + in_ECX[1]) = 0;
    in_ECX[1] = in_ECX[1] + 1;
  }
  return *in_ECX;
}

