/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x5132f0; label: FUN_005132f0
 */

void FUN_005132f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int unaff_ESI;
  
  FUN_004f7fb0();
  iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&DAT_0075ffc8);
  if (iVar1 == 0) {
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & 0xfffd;
    FUN_004f7fb0();
    uVar2 = FUN_00513100(*(undefined4 *)(unaff_ESI + 0x510),DAT_00922218);
    *(undefined4 *)(param_1 + 0x20) = uVar2;
    FUN_004f7fb0();
    iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),"KeepBlockedMessages");
    if (iVar1 == 0) {
      *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) | 2;
      return;
    }
  }
  else {
    iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&PTR_DAT_0075ffb0);
    if (iVar1 == 0) {
      *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) | 1;
      return;
    }
    if (DAT_00922238 == 0) {
      if (DAT_00922248 == 1) {
        if (DAT_00922220 == 0) {
          puVar3 = &DAT_00755ba8;
        }
        else {
          puVar3 = *(undefined **)(DAT_00922220 + 0x18);
        }
        FUN_00512860(*(undefined4 *)(DAT_0092221c + 8),puVar3,*(undefined4 *)(unaff_ESI + 0x50c));
        return;
      }
      if (DAT_00922220 == 0) {
        puVar3 = &DAT_00755ba8;
      }
      else {
        puVar3 = *(undefined **)(DAT_00922220 + 0x18);
      }
      FUN_00512850(*(undefined4 *)(DAT_0092221c + 8),puVar3,*(undefined4 *)(unaff_ESI + 0x50c));
    }
  }
  return;
}

