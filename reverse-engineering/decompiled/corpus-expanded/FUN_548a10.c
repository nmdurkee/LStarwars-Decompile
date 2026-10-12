/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548a10; label: FUN_00548a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00548a10(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != -1) {
    iVar3 = 0;
    sVar1 = *DAT_00924dc4;
    while (sVar1 != -1) {
      if (sVar1 == param_1) {
        return (int)DAT_00924dc4[iVar3 * 2 + 1];
      }
      iVar2 = iVar3 * 2;
      iVar3 = iVar3 + 1;
      sVar1 = DAT_00924dc4[iVar2 + 2];
    }
  }
  return -1;
}

