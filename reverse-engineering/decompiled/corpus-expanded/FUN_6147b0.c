/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x6147b0; label: FUN_006147b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006147b0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = (int *)(*(int *)(param_3 + 8) + 3U & 0xfffffffc);
  *(int **)(param_3 + 8) = piVar2 + 7;
  if (*piVar2 < 3) {
    return 1;
  }
  if ((param_4 == 0) &&
     (((float)piVar2[2] < (float)piVar2[1] != ((float)piVar2[2] == (float)piVar2[1]) ||
      ((float)piVar2[3] < (float)piVar2[2] != ((float)piVar2[3] == (float)piVar2[2]))))) {
    return 1;
  }
  uVar1 = FUN_00613b40(param_1,param_2,param_3,piVar2,param_4);
  return uVar1;
}

