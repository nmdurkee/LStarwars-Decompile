/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d3620; label: FUN_004d3620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d3620(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_004d3150(param_1);
  iVar2 = FUN_0054fa60();
  if (iVar2 < 0x8000) {
    uVar1 = 0x3ecccccd;
  }
  else {
    uVar1 = 0xbecccccd;
  }
  FUN_00549de0(PTR_DAT_008021b4,uVar1,2,0);
  FUN_0054a910(0x3f333333,0,0,0);
  return;
}

