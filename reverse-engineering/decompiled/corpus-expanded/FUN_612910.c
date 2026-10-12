/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612910; label: FUN_00612910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00612910(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0xd838);
  do {
    if (*piVar2 == param_1) {
      return 0 < *(int *)(in_ECX + 0xd844 + iVar1 * 0x14);
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 5;
  } while (iVar1 < 8);
  return false;
}

