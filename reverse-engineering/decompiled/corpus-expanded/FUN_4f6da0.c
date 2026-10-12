/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6da0; label: FUN_004f6da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x004f6dc0) */

undefined4 FUN_004f6da0(undefined4 param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = FUN_004f6d10(param_1);
  lVar2 = FUN_004f6b40(param_1);
  if (lVar1 < lVar2) {
    return 0;
  }
  return 1;
}

