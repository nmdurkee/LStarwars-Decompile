/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612b10; label: FUN_00612b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00612b10(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = (int *)(in_ECX + 0xc034);
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0xc030)) {
    while (*piVar2 != param_1) {
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
      if (*(int *)(in_ECX + 0xc030) <= iVar1) {
        return;
      }
    }
    *piVar2 = 0;
  }
  return;
}

