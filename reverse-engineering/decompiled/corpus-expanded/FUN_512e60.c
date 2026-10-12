/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x512e60; label: FUN_00512e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00512e60(void)

{
  uint uVar1;
  uint *in_EAX;
  void *_Dst;
  size_t in_ECX;
  int *unaff_EDI;
  
  _Dst = (void *)0x0;
  if ((unaff_EDI != (int *)0x0) && (in_EAX != (uint *)0x0)) {
    if (*unaff_EDI + in_ECX < *in_EAX) {
      uVar1 = *unaff_EDI + 0xf;
      _Dst = (void *)(uVar1 & 0xfffffff0);
      *unaff_EDI = (uVar1 & 0xfffffff0) + in_ECX;
      _memset(_Dst,0,in_ECX);
    }
  }
  return _Dst;
}

