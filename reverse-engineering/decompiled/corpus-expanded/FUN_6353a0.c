/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x6353a0; label: FUN_006353a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006353a0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_0291389c != 0) {
    if (param_1 == 0) {
      return DAT_0291389c + 0x4604;
    }
    iVar1 = ((param_1 - DAT_0291389c) + -0x4604) / 0x4c + 1;
    if (iVar1 < 0x20) {
      piVar2 = (int *)(iVar1 * 0x4c + 0x4618 + DAT_0291389c);
      do {
        if (*piVar2 != 0) {
          return iVar1 * 0x4c + 0x4604 + DAT_0291389c;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 0x13;
      } while (iVar1 < 0x20);
    }
  }
  return 0;
}

