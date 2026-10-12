/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4cc920; label: FUN_004cc920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004cc920(undefined **param_1)

{
  int iVar1;
  int iVar2;
  undefined **ppuVar3;
  
  iVar1 = 0;
  ppuVar3 = &PTR_s_batman_007fcfb8;
  iVar2 = 0;
  do {
    if (ppuVar3 == param_1) {
      return iVar1;
    }
    iVar2 = iVar2 + 0x18;
    iVar1 = iVar1 + 1;
    ppuVar3 = ppuVar3 + 6;
  } while (iVar2 < 0xf0);
  return -1;
}

