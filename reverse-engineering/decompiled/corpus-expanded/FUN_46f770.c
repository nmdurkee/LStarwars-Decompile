/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46f770; label: FUN_0046f770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0046f770(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00879370;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00879384 = 0;
  _DAT_00879390 = 0;
  _DAT_008793a8 = 0;
  _DAT_008793b0 = 0;
  _DAT_008793b4 = 0;
  _DAT_008793b8 = 0;
  _DAT_008793bc = 0;
  _DAT_008793c0 = 0;
  _DAT_008793c4 = 0;
  _DAT_008793e0 = 0;
  _DAT_008793e4 = 0;
  DAT_007f90d0 = param_1;
  DAT_00879370 = "Panel";
  DAT_00879374 = &DAT_007516c0;
  _DAT_00879378 = 0xc;
  _DAT_0087937c = FUN_0046eaa0;
  _DAT_00879380 = FUN_0046eac0;
  _DAT_00879388 = FUN_0046df70;
  _DAT_0087938c = FUN_0046e290;
  _DAT_00879394 = FUN_0046eb30;
  _DAT_00879398 = FUN_0046eb60;
  _DAT_0087939c = FUN_0046eb80;
  _DAT_008793a0 = &LAB_0046eb90;
  _DAT_008793a4 = FUN_0046f730;
  _DAT_008793ac = FUN_0046dbb0;
  _DAT_008793c8 = FUN_0046eba0;
  _DAT_008793cc = FUN_0046ebc0;
  _DAT_008793d0 = FUN_0046ebe0;
  _DAT_008793d4 = FUN_0046f620;
  _DAT_008793d8 = FUN_0046db00;
  _DAT_008793dc = FUN_0046d950;
  return &DAT_00879370;
}

