/* Ghidra pseudocode, not original source.
 * ev_3ac53ec2c8a91968fde67182539679734e70c7e49df6a3287feb2aec240cddbe
 * Entry: 0x426c50; label: FUN_00426c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00426c50(void)

{
  undefined *puVar1;
  undefined *puVar2;
  float local_4;
  
  puVar2 = (undefined *)0x0;
  local_4 = -1.0;
  if ((DAT_008569e0 != '\0') && (-1.0 < DAT_008569e8)) {
    local_4 = DAT_008569e8;
    puVar2 = &DAT_008569b8;
  }
  if ((DAT_00856a18 != '\0') && (local_4 < DAT_00856a20)) {
    local_4 = DAT_00856a20;
    puVar2 = &DAT_008569f0;
  }
  if ((DAT_00856a50 != '\0') && (local_4 < _DAT_00856a58)) {
    local_4 = _DAT_00856a58;
    puVar2 = &DAT_00856a28;
  }
  if ((DAT_00856a88 != '\0') && (local_4 < _DAT_00856a90)) {
    local_4 = _DAT_00856a90;
    puVar2 = &DAT_00856a60;
  }
  if ((DAT_00856ac0 != '\0') && (local_4 < _DAT_00856ac8)) {
    local_4 = _DAT_00856ac8;
    puVar2 = &DAT_00856a98;
  }
  if ((DAT_00856af8 != '\0') && (local_4 < _DAT_00856b00)) {
    local_4 = _DAT_00856b00;
    puVar2 = &DAT_00856ad0;
  }
  if ((DAT_00856b30 != '\0') && (local_4 < _DAT_00856b38)) {
    local_4 = _DAT_00856b38;
    puVar2 = &DAT_00856b08;
  }
  if ((DAT_00856b68 != '\0') && (local_4 < _DAT_00856b70)) {
    local_4 = _DAT_00856b70;
    puVar2 = &DAT_00856b40;
  }
  if ((DAT_00856ba0 != '\0') && (local_4 < _DAT_00856ba8)) {
    local_4 = _DAT_00856ba8;
    puVar2 = &DAT_00856b78;
  }
  if ((DAT_00856bd8 == '\0') || (puVar1 = &DAT_00856bb0, _DAT_00856be0 <= local_4)) {
    puVar1 = puVar2;
  }
  return puVar1;
}

