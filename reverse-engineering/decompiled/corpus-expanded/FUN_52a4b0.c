/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x52a4b0; label: FUN_0052a4b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052a4b0(int param_1)

{
  void *_Dst;
  void *pvVar1;
  
  pvVar1 = (void *)FUN_004f1440(DAT_009238e4 + 0x371a4);
  while (_Dst = pvVar1, _Dst != (void *)0x0) {
    pvVar1 = (void *)FUN_004f1460(DAT_009238e4 + 0x371a4,_Dst);
    if (((*(int *)((int)_Dst + 0x40) == param_1) || (*(int *)((int)_Dst + 0x44) == param_1)) &&
       (FUN_00524900((int)_Dst + 0x28,(int *)((int)_Dst + 0x38),
                     *(undefined4 *)(DAT_009238e4 + 0x4868),0), *(int *)((int)_Dst + 0x38) == 0)) {
      FUN_004f1410(DAT_009238e4 + 0x371a4,_Dst);
      _memset(_Dst,0,0xac);
      FUN_004f1310(DAT_009238e4 + 0x3719c,_Dst);
      if (_Dst == *(void **)(DAT_009238e4 + 0x371b0)) {
        *(undefined4 *)(DAT_009238e4 + 0x371b0) = 0;
      }
    }
  }
  return;
}

