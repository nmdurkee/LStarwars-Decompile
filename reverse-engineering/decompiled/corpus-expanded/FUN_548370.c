/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548370; label: FUN_00548370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00548370(int param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xe0);
  if (sVar1 == -1) {
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x44002010) != 0) {
      return;
    }
    if ((*(uint *)(param_1 + 0xef4) & 0x800) == 0) {
      iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x182);
    }
    else {
      iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x180);
    }
  }
  else {
    iVar2 = (int)sVar1;
  }
  if (iVar2 != -1) {
    FUN_00681e90(iVar2,param_1 + 0x80);
  }
  return;
}

