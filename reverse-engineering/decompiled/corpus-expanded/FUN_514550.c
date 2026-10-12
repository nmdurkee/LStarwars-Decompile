/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x514550; label: FUN_00514550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00514550(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (unaff_ESI == 0) {
    return 0;
  }
  if (*(int *)(unaff_ESI + 0xc) == 0) {
    iVar1 = FUN_004f1440(*(int *)(unaff_ESI + 8) + 0x10);
  }
  else {
    iVar1 = FUN_004f1460(*(int *)(unaff_ESI + 8) + 0x10,*(int *)(unaff_ESI + 0xc));
  }
  if (iVar1 != 0) {
    *(uint *)(unaff_ESI + 0x50) = *(uint *)(unaff_ESI + 0x50) | 1;
    *(int *)(unaff_ESI + 0xc) = iVar1;
    return 1;
  }
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  return 1;
}

