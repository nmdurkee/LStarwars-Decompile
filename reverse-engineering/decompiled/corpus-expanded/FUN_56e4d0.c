/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e4d0; label: FUN_0056e4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056e4d0(void)

{
  int iVar1;
  
  if ((DAT_008032cc == 0) && (0.0 < _DAT_00950d90)) {
    _DAT_00950d90 = _DAT_00950d90 - _DAT_00925018;
    if (0.0 < _DAT_00950d90) {
      FUN_00547930(0x51,0,0,0);
      iVar1 = FUN_0054fa60(0);
      FUN_0054ac00(0,(float)iVar1 * 1.5259022e-05 * 0.5);
      return;
    }
    FUN_00547930(0x52,0,0,0);
    return;
  }
  return;
}

