/* Ghidra pseudocode, not original source.
 * ev_573fcacabc8e68ea03635b0f8aa232ed45a87b6cc51fa6af4ed20e3c9ee5dc27
 * Entry: 0x5d1a30; label: FUN_005d1a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d1a30(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_004fa5f0(param_1,1);
  if (iVar1 != 0) {
    FUN_004f03d0(iVar1,param_2,*(short *)(param_2 + 0x1b4) * 2 + 0x1bc);
    FUN_004f99e0(iVar1);
  }
  return;
}

