/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x58a960; label: FUN_0058a960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0058a960(int param_1)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  if (((param_1 != 0) || (param_1 = DAT_009553d4, DAT_009553d4 != 0)) &&
     (iVar3 = 0, *(char *)(param_1 + 0x1f) != '\0')) {
    psVar2 = (short *)(param_1 + 0x20);
    do {
      iVar1 = FUN_00594960((int)*psVar2);
      if (iVar1 == 0) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      psVar2 = psVar2 + 1;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x1f));
  }
  return 1;
}

