/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x6105b0; label: FUN_006105b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006105b0(void)

{
  void *pvVar1;
  
  pvVar1 = (void *)0x0;
  if (0x40000 < *DAT_0291325c - *DAT_02913258) {
    *DAT_02913258 = *DAT_02913258 + 0xf & 0xfffffff0;
    pvVar1 = (void *)*DAT_02913258;
    *DAT_02913258 = *DAT_02913258 + 0x40000;
    _memset(pvVar1,0,0x40000);
    _DAT_02913264 = _DAT_02913264 + 0x40000;
    _DAT_02913268 = _DAT_02913268 + -0x40000;
    _DAT_02913260 = *DAT_02913258;
  }
  DAT_028fec0c = pvVar1;
  if (0x10000 < *DAT_0291325c - *DAT_02913258) {
    *DAT_02913258 = *DAT_02913258 + 0xf & 0xfffffff0;
    pvVar1 = (void *)*DAT_02913258;
    *DAT_02913258 = *DAT_02913258 + 0x10000;
    _memset(pvVar1,0,0x10000);
    _DAT_02913264 = _DAT_02913264 + 0x10000;
    _DAT_02913268 = _DAT_02913268 + -0x10000;
    DAT_028fec08 = pvVar1;
    _DAT_02913260 = *DAT_02913258;
    return;
  }
  DAT_028fec08 = (void *)0x0;
  return;
}

