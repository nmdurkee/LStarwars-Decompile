/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x521a30; label: FUN_00521a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00521a30(void)

{
  void *_Dst;
  
  _Dst = (void *)FUN_004f1440(DAT_009238e4 + 0x411f8);
  if (_Dst != (void *)0x0) {
    FUN_004f1410(DAT_009238e4 + 0x411f8,_Dst);
    _memset(_Dst,0,0x118);
    FUN_004f1310(DAT_009238e4 + 0x41200,_Dst);
  }
  return _Dst;
}

