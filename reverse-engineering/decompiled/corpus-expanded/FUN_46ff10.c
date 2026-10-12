/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x46ff10; label: FUN_0046ff10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0046ff10(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_008793f0;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_008793f8 = 0;
  _DAT_00879404 = 0;
  _DAT_00879410 = 0;
  _DAT_00879428 = 0;
  _DAT_00879430 = 0;
  _DAT_00879434 = 0;
  _DAT_00879438 = 0;
  _DAT_0087943c = 0;
  _DAT_00879440 = 0;
  _DAT_00879444 = 0;
  _DAT_00879448 = 0;
  _DAT_0087944c = 0;
  _DAT_00879450 = 0;
  _DAT_008793e8 = param_1;
  DAT_008793f0 = "Torp Machine";
  DAT_008793f4 = &DAT_007516c0;
  _DAT_008793fc = FUN_0046fe30;
  _DAT_00879400 = FUN_0046fe50;
  _DAT_00879408 = FUN_0046fb80;
  _DAT_0087940c = FUN_0046fbe0;
  _DAT_00879414 = FUN_0046fec0;
  _DAT_00879418 = FUN_0046fee0;
  _DAT_0087941c = FUN_0046fef0;
  _DAT_00879420 = &LAB_0046ff00;
  _DAT_00879424 = FUN_0046fa60;
  _DAT_0087942c = FUN_0046fa40;
  _DAT_00879454 = FUN_0046fa90;
  _DAT_00879458 = FUN_0046f990;
  _DAT_0087945c = FUN_0046f8c0;
  return &DAT_008793f0;
}

