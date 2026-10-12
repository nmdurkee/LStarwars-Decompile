/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x592660; label: FUN_00592660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00592660(int param_1)

{
  int iVar1;
  
  if ((*(ushort *)(param_1 + 0x12) & 0x180) != 0) {
    iVar1 = FUN_0055c880();
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

