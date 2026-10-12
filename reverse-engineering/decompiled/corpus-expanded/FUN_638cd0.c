/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x638cd0; label: FUN_00638cd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00638cd0(undefined4 param_1,int param_2)

{
  if (DAT_02913824 != 0) {
    *(ushort *)(DAT_02913824 + 0x5e) =
         *(ushort *)(DAT_02913824 + 0x5e) &
         ~(ushort)(1 << ((byte)*(undefined4 *)(param_2 + 0xc) & 0x1f));
    if ((*(byte *)(param_2 + 0x11) & 1) != 0) {
      *(ushort *)(DAT_02913824 + 0x5e) =
           *(ushort *)(DAT_02913824 + 0x5e) |
           (ushort)(1 << ((byte)*(undefined4 *)(param_2 + 0xc) & 0x1f));
    }
    *(ushort *)(DAT_02913824 + 0x60) =
         *(ushort *)(DAT_02913824 + 0x60) & ~*(ushort *)(DAT_02913824 + 0x5e);
    FUN_006382a0();
    return;
  }
  return;
}

