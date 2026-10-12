/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d34a0; label: FUN_005d34a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d34a0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_004ffaa0(DAT_0080b6d4);
  _DAT_00963f50 = FUN_006e6b90();
  DAT_009736e4 = DAT_0080b618;
  for (puVar2 = DAT_009738d8; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[1]) {
    for (puVar1 = (undefined4 *)*puVar2; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1
        ) {
      if (puVar1[5] != 0) {
        FUN_005d2d10(puVar1[5]);
      }
    }
  }
  FUN_004ffac0();
  return;
}

