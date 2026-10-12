/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635350; label: FUN_00635350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00635350(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0;
  piVar2 = (int *)(DAT_0291389c + 0x4664);
  iVar3 = 8;
  do {
    if (piVar2[-0x13] != 0) {
      iVar1 = iVar1 + 1;
    }
    if (*piVar2 != 0) {
      iVar1 = iVar1 + 1;
    }
    if (piVar2[0x13] != 0) {
      iVar1 = iVar1 + 1;
    }
    if (piVar2[0x26] != 0) {
      iVar1 = iVar1 + 1;
    }
    piVar2 = piVar2 + 0x4c;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}

