/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x5489b0; label: FUN_005489b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005489b0(int param_1)

{
  short sVar1;
  int iVar2;
  
  if (param_1 != -1) {
    iVar2 = 0;
    sVar1 = *DAT_009248c0;
    while (sVar1 != -1) {
      if (sVar1 == param_1) {
        return (int)DAT_009248c0[iVar2 * 0xe + 1];
      }
      iVar2 = iVar2 + 1;
      sVar1 = DAT_009248c0[iVar2 * 0xe];
    }
  }
  return -1;
}

