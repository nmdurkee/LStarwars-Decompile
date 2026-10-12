/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x5400c0; label: FUN_005400c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005400c0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (((DAT_009242c4 != (uint *)0x0) && (DAT_009242dc != 0)) && (DAT_029838e0 != 0)) {
    uVar1 = *DAT_009242c4 + 3 & 0xfffffffc;
    *DAT_009242c4 = uVar1;
    *(uint *)(DAT_029838fc + 0xf8) = uVar1;
    *(undefined2 *)(DAT_029838fc + 0xfc) = 0;
    iVar2 = FUN_004f7fb0(param_1);
    while (iVar2 != 0) {
      iVar2 = FUN_005cf5b0(DAT_029838e0,
                           *(int *)(DAT_029838fc + 0xf8) +
                           (uint)*(ushort *)(DAT_029838fc + 0xfc) * 0xc,
                           *(undefined4 *)(param_1 + 0x510),1);
      if (iVar2 != 0) {
        *(short *)(DAT_029838fc + 0xfc) = *(short *)(DAT_029838fc + 0xfc) + 1;
      }
      iVar2 = FUN_004f7fb0(param_1);
    }
    if (*(ushort *)(DAT_029838fc + 0xfc) != 0) {
      *DAT_009242c4 = *DAT_009242c4 + (uint)*(ushort *)(DAT_029838fc + 0xfc) * 0xc;
      return;
    }
    *(undefined4 *)(DAT_029838fc + 0xf8) = 0;
  }
  return;
}

