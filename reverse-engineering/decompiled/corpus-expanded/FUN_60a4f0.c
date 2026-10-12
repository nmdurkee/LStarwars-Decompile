/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x60a4f0; label: FUN_0060a4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060a4f0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_005e5310(param_2);
  if (iVar1 != 0) {
    FUN_005f1f50(param_2);
    _DAT_02855354 = (iVar1 + -0x2855050) / 0x30;
    (&DAT_02855350)[_DAT_02855354 >> 3] =
         (&DAT_02855350)[_DAT_02855354 >> 3] & ~('\x01' << ((byte)_DAT_02855354 & 7));
  }
  return;
}

