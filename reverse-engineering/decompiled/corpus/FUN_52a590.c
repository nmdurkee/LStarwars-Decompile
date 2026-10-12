/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52a590; label: FUN_0052a590
 */

void FUN_0052a590(int param_1)

{
  void *_Dst;
  void *pvVar1;
  
  pvVar1 = (void *)FUN_004f1440(DAT_009238e4 + 0x371a4);
  while (_Dst = pvVar1, _Dst != (void *)0x0) {
    pvVar1 = (void *)FUN_004f1460(DAT_009238e4 + 0x371a4,_Dst);
    if (*(int *)((int)_Dst + 0x3c) == param_1) {
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

