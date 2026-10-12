/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x5661f0; label: FUN_005661f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005661f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00806680;
  puVar3 = DAT_00925164;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00603cc0(DAT_00925164);
  FUN_005d4290(1);
  if (DAT_009506f0 == DAT_009506f4) {
    FUN_005ebd80(0xf00,DAT_009506f0);
  }
  else {
    FUN_005feab0(0xf00,DAT_009506f0,DAT_009506f4,0x3f800000);
  }
  if (_DAT_00950678 != 1.0) {
    FUN_00564af0(1.0 - _DAT_00950678,0);
    FUN_005f3950();
    return;
  }
  FUN_005f3950();
  return;
}

