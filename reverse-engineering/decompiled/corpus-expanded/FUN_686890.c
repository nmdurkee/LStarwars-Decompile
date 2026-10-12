/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x686890; label: FUN_00686890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00686890(void)

{
  undefined4 uVar1;
  
  if (DAT_029620cc != 0) {
    uVar1 = FUN_005f8f10(_DAT_029620b0,0);
    uVar1 = FUN_005f8f20(uVar1);
    FUN_005d4300(1,2,1);
    if (0 < DAT_02947d84) {
      FUN_00685770(0,2);
    }
    FUN_0074e9e0(uVar1);
    FUN_005f3950();
    FUN_005f8f30();
    return;
  }
  return;
}

