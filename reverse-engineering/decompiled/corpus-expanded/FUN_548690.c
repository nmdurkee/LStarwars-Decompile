/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548690; label: FUN_00548690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00548690(int param_1,int param_2)

{
  int iVar1;
  
  FUN_00650870(&DAT_00924cf8);
  if (((param_2 == 0) && (*(code **)(PTR_DAT_008020bc + 4) != (code *)0x0)) &&
     (iVar1 = (**(code **)(PTR_DAT_008020bc + 4))(), iVar1 != 0)) {
    FUN_00697a30(1);
  }
  else {
    FUN_00697a30(0);
    if (param_2 != 0) {
      return;
    }
  }
  if ((DAT_00951be0 == 0) && (*(short *)(*(int *)(param_1 + 0x128) + 0x96) != -1)) {
    FUN_00681e90();
    return;
  }
  return;
}

