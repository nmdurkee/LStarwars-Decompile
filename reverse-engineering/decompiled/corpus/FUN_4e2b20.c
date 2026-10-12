/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e2b20; label: FUN_004e2b20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e2b20(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined **ppuVar5;
  
  *(undefined1 *)(DAT_00882b2c + 2) = 0;
  iVar4 = 0;
  do {
    uVar1 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,
                         *(undefined4 *)((int)&PTR_s_red_juice_007ffe44 + iVar4));
    *(undefined4 *)((int)&DAT_00882aa8 + iVar4) = uVar1;
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x18);
  iVar4 = 0;
  do {
    uVar1 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f90d0,
                         *(undefined4 *)((int)&PTR_DAT_007ffe5c + iVar4));
    *(undefined4 *)((int)&DAT_0088909c + iVar4) = uVar1;
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0xc);
  puVar2 = &DAT_00888fe0;
  ppuVar5 = &PTR_s_but_orange_007ffe68;
  do {
    FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar2,*ppuVar5,0);
    ppuVar5 = ppuVar5 + 1;
    puVar2 = puVar2 + 3;
  } while ((int)ppuVar5 < 0x7ffe74);
  puVar3 = &DAT_00882ad0;
  ppuVar5 = &PTR_s_off_purple_007ffe74;
  do {
    FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),puVar3,*ppuVar5,0);
    ppuVar5 = ppuVar5 + 1;
    puVar3 = puVar3 + 0xc;
  } while ((int)ppuVar5 < 0x7ffe80);
  DAT_00882acc = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,"FORCE_TUBE");
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_00882b60,"green_light_on1",1);
  puVar2 = &DAT_00882aa8;
  do {
    FUN_00558970(*(undefined4 *)*puVar2);
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x882ac0);
  _DAT_00882ba8 = 0;
  DAT_008894a8 = 1;
  FUN_004ddcf0();
  return;
}

