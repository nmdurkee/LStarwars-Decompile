/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x46a970; label: FUN_0046a970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046a970(int param_1)

{
  char cVar1;
  float10 fVar2;
  undefined2 local_4;
  
  cVar1 = *(char *)(param_1 + 0xfd);
  local_4 = (undefined2)(int)ROUND((float)*(ushort *)(param_1 + 0xe2) + _DAT_00925018 * 16384.0);
  *(undefined2 *)(param_1 + 0xe2) = local_4;
  if ((cVar1 == '\0') || (cVar1 == '\x01')) {
    fVar2 = (float10)FUN_004b7120((int)cVar1);
    *(float *)(param_1 + 0x8c) = (float)(fVar2 + (float10)_DAT_007fc310);
  }
  return;
}

