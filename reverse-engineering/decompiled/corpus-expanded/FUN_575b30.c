/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x575b30; label: FUN_00575b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00575b30(undefined1 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00951438;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00951440 = 0;
  _DAT_0095144c = 0;
  _DAT_00951450 = 0;
  _DAT_00951454 = 0;
  _DAT_00951458 = 0;
  _DAT_00951470 = 0;
  _DAT_00951474 = 0;
  _DAT_00951478 = 0;
  _DAT_0095147c = 0;
  _DAT_00951480 = 0;
  _DAT_00951484 = 0;
  _DAT_00951488 = 0;
  _DAT_0095148c = 0;
  _DAT_00951490 = 0;
  _DAT_00951494 = 0;
  _DAT_00951498 = 0;
  _DAT_0095149c = 0;
  _DAT_009514a0 = 0;
  _DAT_009514a4 = 0;
  _DAT_009514a8 = 0;
  _DAT_009514ac = 0;
  DAT_00803918 = param_1;
  DAT_00951438 = &DAT_00761e9c;
  DAT_0095143c = &DAT_007516c0;
  _DAT_00951444 = FUN_00575a10;
  _DAT_00951448 = FUN_00575a30;
  _DAT_0095145c = &LAB_00575ab0;
  _DAT_00951460 = FUN_00575ad0;
  _DAT_00951464 = FUN_00575b00;
  _DAT_00951468 = &LAB_00575af0;
  _DAT_0095146c = FUN_00575b10;
  return &DAT_00951438;
}

