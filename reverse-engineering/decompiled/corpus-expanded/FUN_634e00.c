/* Ghidra pseudocode, not original source.
 * ev_1103904689436dd579d46533c258b0710963d6b5b648a9f295784d5cea761bb8
 * Entry: 0x634e00; label: FUN_00634e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00634e00(void)

{
  int in_ECX;
  void *_Dst;
  
  if (*(int *)(in_ECX + 8) == 0) {
    _Dst = (void *)0x0;
    if (0x6fac < *DAT_0291325c - *DAT_02913258) {
      *DAT_02913258 = *DAT_02913258 + 0xf & 0xfffffff0;
      _Dst = (void *)*DAT_02913258;
      *DAT_02913258 = *DAT_02913258 + 0x6fac;
      _memset(_Dst,0,0x6fac);
      _DAT_02913264 = _DAT_02913264 + 0x6fac;
      _DAT_02913268 = _DAT_02913268 + -0x6fac;
      _DAT_02913260 = *DAT_02913258;
    }
    *(void **)(in_ECX + 8) = _Dst;
    *(undefined4 *)((int)_Dst + 0x4f84) = 0;
    DAT_0291389c = *(undefined4 *)(in_ECX + 8);
    return;
  }
  DAT_0291389c = *(undefined4 *)(in_ECX + 8);
  return;
}

