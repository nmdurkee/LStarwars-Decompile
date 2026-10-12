/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69b5a0; label: FUN_0069b5a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069b5a0(void)

{
  int iVar1;
  int in_ECX;
  int *in_EDX;
  
  iVar1 = FUN_0069ed70();
  if (in_EDX != (int *)0x0) {
    while (in_ECX != 0) {
      in_ECX = in_ECX + -1;
      if (*in_EDX == iVar1) {
        return 1;
      }
      in_EDX = in_EDX + 1;
    }
  }
  return 0;
}

