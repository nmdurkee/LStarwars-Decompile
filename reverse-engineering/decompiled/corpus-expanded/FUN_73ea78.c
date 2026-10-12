/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x73ea78; label: FUN_0073ea78
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0073ea78(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (0x7fffffff < param_2) {
    return 0x80070057;
  }
  uVar1 = _StringCopyWorkerA_12();
  return uVar1;
}

