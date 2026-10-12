/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612bd0; label: FUN_00612bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00612bd0(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0xd03c);
  do {
    if (*piVar2 == param_1) {
      if (param_1 == 0) {
        *(undefined4 *)(in_ECX + 0xd034 + iVar1 * 0xc) = 0;
        *(undefined4 *)(in_ECX + (iVar1 * 3 + 0x340e) * 4) = 0;
      }
      return in_ECX + 0xd034 + iVar1 * 0xc;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 3;
  } while (iVar1 < 0x20);
  return 0;
}

