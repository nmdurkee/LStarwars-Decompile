/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6d10; label: FUN_004f6d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x004f6d7d) */

longlong FUN_004f6d10(int param_1)

{
  int iVar1;
  longlong lVar2;
  
  if (0xfff < param_1) {
    iVar1 = FUN_006dee90(param_1 + -0x1000,0,2,0);
    return (longlong)iVar1;
  }
  if (param_1 < 0x400) {
    param_1 = param_1 + -1;
    if (*(int *)(&DAT_008ceb7c + param_1 * 0x40) == 0) {
      lVar2 = FUN_004ff430(param_1,0,0,1);
      if ((int)((ulonglong)lVar2 >> 0x20) < 1) {
        while (lVar2 < 0) {
          lVar2 = FUN_004ff430(param_1,0,0,1);
        }
      }
      return lVar2;
    }
    return *(longlong *)(&DAT_008ceb58 + param_1 * 0x40);
  }
  lVar2 = FUN_004f6c20(param_1);
  return lVar2;
}

