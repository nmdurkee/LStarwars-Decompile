/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x5483e0; label: FUN_005483e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005483e0(int param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xde);
  if (sVar1 == -1) {
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x44002010) != 0) goto LAB_00548443;
    if ((*(uint *)(param_1 + 0xef4) & 0x800) == 0) {
      iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x186);
    }
    else {
      iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x184);
    }
  }
  else {
    iVar2 = (int)sVar1;
  }
  if (iVar2 != -1) {
    FUN_00681e90(iVar2,param_1 + 0x80);
  }
LAB_00548443:
  if (DAT_00924de0 != (code *)0x0) {
    (*DAT_00924de0)(param_1);
  }
  return;
}

