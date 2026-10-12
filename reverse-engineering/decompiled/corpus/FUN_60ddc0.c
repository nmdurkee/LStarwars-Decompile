/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60ddc0; label: FUN_0060ddc0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060ddc0(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  _DAT_02854d28 = FUN_0060d9b0(2,&DAT_00769728,&DAT_00769858);
  if (DAT_02974d1c < 2) {
    puVar3 = &DAT_00769dc0;
    puVar2 = &DAT_00769c60;
  }
  else {
    puVar3 = &DAT_00769a70;
    puVar2 = &DAT_00769908;
  }
  _DAT_02854d2c = FUN_0060d9b0(2,puVar2,puVar3);
  if (1 < DAT_02974d1c) {
    _DAT_02854d30 = FUN_0060d9b0(2,&DAT_00769e98,&DAT_0076a3e0);
  }
  _DAT_02854d34 = FUN_0060d9b0(2,&DAT_00769e98,&DAT_0076a2b0);
  _DAT_02854d38 = FUN_0060d9b0(2,&DAT_0076a550,&DAT_0076a600);
  FUN_006e4850(&DAT_0080e630,&DAT_02854d40);
  FUN_006e4850(&DAT_0080e610,&DAT_02854d3c);
  FUN_006e4850(&DAT_0080e5f0,&DAT_02854d44);
  puVar1 = (undefined4 *)
           FUN_004eef40(0x28,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\numtl_dlist.c",0x159)
  ;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[9] = 0;
  puVar1[7] = s_DDS___0080e2b8;
  puVar1[8] = 0x338;
  _DAT_02854d48 = FUN_005e5210(puVar1);
  return;
}

