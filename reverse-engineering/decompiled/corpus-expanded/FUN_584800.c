/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x584800; label: FUN_00584800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00584800(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  
  if (((((DAT_0095440c & 2) != 0) && (*(byte *)((int)DAT_00954404 + 0x11f) < 0x20)) &&
      (iVar1 = FUN_004f7fb0(param_1), iVar1 != 0)) &&
     (iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510)), iVar1 < 0x18)) {
    FUN_004f1f10(DAT_00954404[1] + (uint)*(byte *)((int)DAT_00954404 + 0x11f) * 0x1c,
                 *(undefined4 *)(param_1 + 0x510));
    uVar2 = FUN_004f9e70(param_1);
    if (uVar2 < 0x20) {
      uVar3 = (uint)*(byte *)((int)DAT_00954404 + 0x11f);
      iVar1 = 0;
      if (uVar3 != 0) {
        psVar4 = (short *)(DAT_00954404[1] + 0x18);
        do {
          if ((int)*psVar4 == uVar2) {
            return;
          }
          iVar1 = iVar1 + 1;
          psVar4 = psVar4 + 0xe;
        } while (iVar1 < (int)uVar3);
      }
      *(short *)(DAT_00954404[1] + 0x18 + uVar3 * 0x1c) = (short)uVar2;
      *(undefined2 *)(DAT_00954404[1] + 0x1a + (uint)*(byte *)((int)DAT_00954404 + 0x11f) * 0x1c) =
           0xffff;
      *(char *)((int)DAT_00954404 + 0x11f) = *(char *)((int)DAT_00954404 + 0x11f) + '\x01';
      DAT_00954410 = 1;
      *DAT_00954404 = FUN_0055bb30;
    }
  }
  return;
}

