/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1660; label: FUN_004f1660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_004f1660(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  uVar6 = (param_1 + 0xfU >> 4) + 1;
  uVar1 = ((int *)*DAT_0091eec8)[1];
  piVar5 = (int *)*DAT_0091eec8;
  piVar4 = DAT_0091eec8;
  while (piVar3 = piVar5, uVar1 < uVar6) {
    if (piVar3 == DAT_0091eec8) {
      return (int *)0x0;
    }
    piVar5 = (int *)*piVar3;
    piVar4 = piVar3;
    uVar1 = ((int *)*piVar3)[1];
  }
  if (uVar1 == uVar6) {
    *piVar4 = *piVar3;
    DAT_0091eec8 = piVar4;
    return piVar3 + 4;
  }
  piVar3[1] = piVar3[1] - uVar6;
  iVar2 = piVar3[1];
  piVar3[iVar2 * 4 + 1] = uVar6;
  DAT_0091eec8 = piVar4;
  return piVar3 + iVar2 * 4 + 4;
}

