/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x59a420; label: FUN_0059a420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059a420(int param_1)

{
  uint uVar1;
  float10 fVar2;
  undefined2 local_4;
  
  fVar2 = (float10)FUN_005b7d30(_DAT_00925028,0x40800000);
  uVar1 = (uint)ROUND(fVar2 * (float10)0.25 * (float10)65536.0);
  local_4 = (undefined2)uVar1;
  *(undefined2 *)(param_1 + 0xe2) = local_4;
  local_4 = (undefined2)
            (int)ROUND((float)(&DAT_029899a0)[(int)((uVar1 & 0xffff) * 2) >> 1 & 0x7fff] * 1820.0);
  *(undefined2 *)(param_1 + 0xe0) = local_4;
  return;
}

