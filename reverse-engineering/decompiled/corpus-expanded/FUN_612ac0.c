/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612ac0; label: FUN_00612ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00612ac0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  iVar1 = *(int *)(in_ECX + 0xc030);
  iVar2 = 0;
  piVar3 = (int *)(in_ECX + 0xc034);
  if (0 < iVar1) {
    do {
      if (*piVar3 == 0) break;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < iVar1);
  }
  if (iVar1 <= iVar2) {
    *(int *)(in_ECX + 0xc030) = ((int)piVar3 + (-0xc034 - in_ECX) >> 2) + 1;
    *piVar3 = param_1;
    return;
  }
  *piVar3 = param_1;
  return;
}

