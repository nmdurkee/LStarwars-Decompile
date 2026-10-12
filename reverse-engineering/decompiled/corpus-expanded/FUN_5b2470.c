/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b2470; label: FUN_005b2470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b2470(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  undefined4 *local_8;
  undefined4 local_4;
  
  uVar2 = 0;
  if (DAT_0095e42c != (code *)0x0) {
    iVar1 = (*DAT_0095e42c)();
    if ((iVar1 != 0) && (0.2 <= _DAT_0095e424)) {
      uVar2 = 1;
      DAT_0095e428 = 1;
    }
  }
  local_10 = _DAT_0095e434;
  local_14 = DAT_00925410;
  local_18 = DAT_009253b0;
  local_8 = &local_18;
  local_c = DAT_0093b328;
  local_4 = 2;
  if (DAT_0095e418 != (int *)0x0) {
    (**(code **)(*DAT_0095e418 + 0x20))(&local_10);
  }
  _DAT_0095e424 = _DAT_0095e434 + _DAT_0095e424;
  return uVar2;
}

