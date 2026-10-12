/* Ghidra pseudocode, not original source.
 * ev_9a76e25c08ce4dcda3c08de929e5a103c2765ccb900e87aba0770623e17ea5fe
 * Entry: 0x6df8b0; label: FUN_006df8b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006df8b0(void)

{
  if ((_DAT_0297ae70 & 1) == 0) {
    _DAT_0297ae70 = _DAT_0297ae70 | 1;
    _DAT_0297ae30 = 0x3f800000;
    _DAT_0297ae34 = 0;
    _DAT_0297ae38 = 0;
    _DAT_0297ae3c = 0;
    _DAT_0297ae40 = 0;
    _DAT_0297ae48 = 0;
    _DAT_0297ae4c = 0;
    _DAT_0297ae50 = 0;
    _DAT_0297ae54 = 0;
    _DAT_0297ae5c = 0;
    _DAT_0297ae60 = 0;
    _DAT_0297ae64 = 0;
    _DAT_0297ae68 = 0;
    _DAT_0297ae44 = 0x3f800000;
    _DAT_0297ae58 = 0x3f800000;
    _DAT_0297ae6c = 0x3f800000;
  }
  FUN_006e56a0(0x100,&DAT_0297ae30);
  return;
}

