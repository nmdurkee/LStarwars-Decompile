/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x548690; label: FUN_00548690
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

