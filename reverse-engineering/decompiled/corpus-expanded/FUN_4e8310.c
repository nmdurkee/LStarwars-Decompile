/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e8310; label: FUN_004e8310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e8310(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  _DAT_00803574 = 0x2002;
  puVar3 = &DAT_0087aad8;
  do {
    iVar1 = FUN_005cfac0(puVar3);
    if (iVar1 != 0) {
      iVar1 = FUN_005d0420(puVar3);
      if ((iVar1 != 0) && (*(float *)(iVar1 + 0x4c) == 1.0)) {
        uVar2 = FUN_005cf9e0(puVar3);
        FUN_00681f40("env_steam_lp",uVar2);
        _DAT_00803574 = _DAT_00803574 | 0x4042;
      }
    }
    puVar3 = puVar3 + 3;
  } while ((int)puVar3 < 0x87aafc);
  return;
}

