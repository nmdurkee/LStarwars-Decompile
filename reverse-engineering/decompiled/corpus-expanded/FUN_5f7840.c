/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f7840; label: FUN_005f7840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f7840(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  return;
}

