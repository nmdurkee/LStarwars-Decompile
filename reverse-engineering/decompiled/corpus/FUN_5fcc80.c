/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fcc80; label: FUN_005fcc80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fcc80(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)FUN_005d6190();
  puVar2 = (undefined4 *)FUN_005d6180();
  puVar4 = &DAT_009869b4;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  _DAT_009869f4 = *puVar1;
  _DAT_009869f8 = puVar1[5];
  _DAT_009869fc = puVar1[10];
  _DAT_00986a00 = puVar1[0xb];
  _DAT_00986a04 = puVar1[0xe];
  FUN_005dad10(&DAT_00986a24,&DAT_00986a28);
  FUN_005daef0(&DAT_00986a2c,&DAT_00986a30);
  _DAT_009868c0 = _DAT_009868c0 + 1;
  _DAT_009868cc = _DAT_009868cc + 1;
  _DAT_009869b0 = 0;
  _DAT_00986a24 = _DAT_00986a24 * ((float)DAT_00973900 / 640.0);
  _DAT_00986a2c = ((float)DAT_00973900 / 640.0) * _DAT_00986a2c;
  _DAT_00986a28 = _DAT_00986a28 * ((float)DAT_00973904 / 224.0);
  _DAT_00986a30 = ((float)DAT_00973904 / 224.0) * _DAT_00986a30;
  return;
}

