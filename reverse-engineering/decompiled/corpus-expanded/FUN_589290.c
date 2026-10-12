/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x589290; label: FUN_00589290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00589290(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f9e70(param_1);
  if (iVar1 < 0x2711) {
    if (iVar1 < 0) {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 10000;
  }
  *(short *)(DAT_00954404 + 0xee) = (short)(iVar1 / 10) * 10;
  return;
}

