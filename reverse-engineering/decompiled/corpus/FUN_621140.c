/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x621140; label: FUN_00621140
 */

void FUN_00621140(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_40 [16];
  
  FUN_006210b0(local_40);
  puVar1 = DAT_02912e78;
  puVar3 = local_40;
  puVar4 = DAT_02912e78;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00603cc0(puVar1);
  return;
}

