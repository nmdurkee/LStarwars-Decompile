/* Ghidra pseudocode, not original source.
 * ev_4289758b99e4c7501e635d810a16af61d296f1bd933ef263ce76cab568b7549e
 * Entry: 0x698a50; label: FUN_00698a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00698a50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_006997a0();
  if (iVar1 == 0) {
    FUN_004f1f40(param_3,&DAT_0076ef94,param_4);
    return 1;
  }
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      FUN_004f1f40(param_3,&DAT_0076ef8c,param_4);
      return 2;
    }
    FUN_004f1f40(param_3,"unknown status",param_4);
    return 2;
  }
  FUN_004f1f40(param_3,"Playing",param_4);
  return 2;
}

