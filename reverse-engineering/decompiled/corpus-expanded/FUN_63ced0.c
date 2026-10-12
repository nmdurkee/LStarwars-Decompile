/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63ced0; label: FUN_0063ced0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063ced0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 + 0x4604 + DAT_0291389c;
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) == 1)) {
      FUN_00623e00(iVar1 + 0x20,*(undefined4 *)(iVar1 + 0x1c),
                   *(uint *)(iVar1 + 8) & 0xffffff | 0x80000000,DAT_0080ff40,0);
    }
    iVar2 = iVar2 + 0x4c;
  } while (iVar2 < 0x980);
  return;
}

