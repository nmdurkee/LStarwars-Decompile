/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612b60; label: FUN_00612b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00612b60(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  if (param_1 != 0) {
    iVar1 = 0;
    piVar2 = (int *)(in_ECX + 0x3c);
    do {
      if ((*(short *)((int)piVar2 + -10) != 0) && (*piVar2 == param_1)) {
        return in_ECX + (iVar1 * 3 + 6) * 8;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 6;
    } while (iVar1 < 0x800);
  }
  return 0;
}

