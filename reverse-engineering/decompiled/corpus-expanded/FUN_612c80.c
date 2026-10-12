/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612c80; label: FUN_00612c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00612c80(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0xd03c);
  do {
    if (*piVar2 == param_1) {
      *(undefined4 *)(in_ECX + 0xd03c + iVar1 * 0xc) = 0;
      return;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 3;
  } while (iVar1 < 0x20);
  return;
}

