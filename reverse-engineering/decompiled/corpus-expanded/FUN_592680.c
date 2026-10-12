/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x592680; label: FUN_00592680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00592680(void)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 5;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 6;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 3;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 4;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 2;
  }
  iVar1 = FUN_004f8b10();
  if (iVar1 == 0) {
    return 7;
  }
  iVar1 = FUN_004f8b10();
  return (-(uint)(iVar1 != 0) & 0xfffffff7) + 8;
}

