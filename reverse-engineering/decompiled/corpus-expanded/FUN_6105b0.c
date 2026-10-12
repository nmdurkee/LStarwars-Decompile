/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x6105b0; label: FUN_006105b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

