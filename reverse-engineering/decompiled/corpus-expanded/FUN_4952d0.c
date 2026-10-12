/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x4952d0; label: FUN_004952d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004952d0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < DAT_00802364) {
    do {
      FUN_00574de0(param_1,*(undefined4 *)(PTR_DAT_00802360 + iVar1 * 8 + 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00802364);
  }
  return;
}

