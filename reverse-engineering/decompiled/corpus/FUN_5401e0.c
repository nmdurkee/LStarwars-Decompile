/* Ghidra analysis pseudocode, not original source.
 * ev_3c859e02b972a8e60701cf54913e5d4895bfb87c225b3b379a359b744e8ff688
 * Entry: 0x5401e0; label: FUN_005401e0
 */

void FUN_005401e0(int param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  
  uVar2 = FUN_004f9e70(param_1);
  FUN_004f7fb0(param_1);
  uVar1 = *(undefined4 *)(param_1 + 0x510);
  iVar4 = FUN_004f8b10(uVar1,&DAT_007614fc);
  cVar3 = '\0';
  if (iVar4 != 0) {
    iVar4 = FUN_004f8b10(uVar1,&DAT_007614f8);
    cVar3 = (-(iVar4 != 0) & 0xfeU) + 1;
  }
  *(char *)(DAT_029838fc + 0x101 + *(int *)(DAT_029838fc + 0x110) * 2) = cVar3;
  *(undefined1 *)(DAT_029838fc + 0x100 + *(int *)(DAT_029838fc + 0x110) * 2) = uVar2;
  *(int *)(DAT_029838fc + 0x110) = *(int *)(DAT_029838fc + 0x110) + 1;
  return;
}

