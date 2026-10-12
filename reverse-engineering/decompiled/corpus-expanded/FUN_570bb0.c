/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x570bb0; label: FUN_00570bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00570bb0(void)

{
  int iVar1;
  
  iVar1 = FUN_0055f450();
  if ((((DAT_00951364 == 0) || (*(int *)(iVar1 + 300) != DAT_00951364)) && (DAT_0093b2a8 == 0)) &&
     (((*(int *)(iVar1 + 300) == 0 || ((*(ushort *)(*(int *)(iVar1 + 300) + 0x7a) & 0x100) == 0)) &&
      ((*(int *)(iVar1 + 0x128) == 0 || ((*(uint *)(*(int *)(iVar1 + 0x128) + 100) & 0x400) == 0))))
     )) {
    return 0;
  }
  return 1;
}

