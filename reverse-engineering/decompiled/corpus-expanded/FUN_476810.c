/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x476810; label: FUN_00476810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00476810(void)

{
  ushort uVar1;
  int in_EAX;
  
  uVar1 = *(ushort *)(in_EAX * 0x9c + 0x7a + DAT_00951354);
  if ((uVar1 & 1) == 0) {
    return &DAT_00855ea4;
  }
  if ((uVar1 & 4) != 0) {
    return &DAT_00855f24;
  }
  return &DAT_00855ed0;
}

