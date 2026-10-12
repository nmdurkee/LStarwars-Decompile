/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x5132f0; label: FUN_005132f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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
    iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&DAT_0075ffb0);
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

