/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5bfd70; label: FUN_005bfd70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005bfd70(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_4;
  
  iVar1 = FUN_004fa5f0(param_2,1);
  if (iVar1 != 0) {
    local_4 = 2;
    FUN_004f03d0(iVar1,&local_4,4);
    FUN_004f03d0(iVar1,param_1,0x5c);
    FUN_004f99e0(iVar1);
  }
  return iVar1 != 0;
}

