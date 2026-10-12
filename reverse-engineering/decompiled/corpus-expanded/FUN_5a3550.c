/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a3550; label: FUN_005a3550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a3550(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int in_EDX;
  
  piVar2 = DAT_0095da38;
  if (DAT_0095da38 != (int *)0x0) {
    iVar1 = *(int *)(in_EDX + 8);
    piVar3 = (int *)*DAT_0095da38;
    *DAT_0095da38 = iVar1;
    DAT_0095da38 = piVar3;
    if (iVar1 != 0) {
      *(int **)(iVar1 + 4) = piVar2;
    }
    piVar2[1] = 0;
    *(int **)(in_EDX + 8) = piVar2;
  }
  return;
}

