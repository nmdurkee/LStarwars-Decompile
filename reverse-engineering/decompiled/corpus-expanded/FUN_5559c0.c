/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x5559c0; label: FUN_005559c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005559c0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  short *psVar3;
  
  if (((param_2 != 0) && (bVar1 = *(byte *)(param_2 + 0xac), (bVar1 & 1) != 0)) &&
     ((bVar1 & 4) == 0)) {
    if (((bVar1 & 0x22) != 0) && (*(short *)(param_2 + 0xae) == *(short *)(param_3 + 0xfa))) {
      return 1;
    }
    if (*(short *)(param_2 + 0xae) == *(short *)(param_3 + 0xfa)) {
      FUN_00555930(param_4);
      return 1;
    }
    iVar2 = 0;
    if (*(byte *)(param_2 + 0x8b) != 0) {
      psVar3 = (short *)(param_2 + 0xf4);
      do {
        if (*psVar3 == *(short *)(param_3 + 0xfa)) {
          FUN_00555930(param_4);
          return 1;
        }
        iVar2 = iVar2 + 1;
        psVar3 = psVar3 + 0x22;
      } while (iVar2 < (int)(uint)*(byte *)(param_2 + 0x8b));
    }
    return 0;
  }
  return 0;
}

