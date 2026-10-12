/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x623ae0; label: FUN_00623ae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00623ae0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  _DAT_0080fafc = *DAT_02910c98;
  _DAT_0080fb00 = *DAT_02912e4c;
  _DAT_0080fb04 = *DAT_02900a60;
  uVar1 = FUN_006e6b90();
  uVar2 = FUN_006e6b90();
  uVar3 = FUN_006e6b90();
  *(uint *)(DAT_029110b4 + 0x30) =
       ((uVar1 & 0xff | 0xffff8000) << 8 | uVar2 & 0xff) << 8 | uVar3 & 0xff;
  return;
}

