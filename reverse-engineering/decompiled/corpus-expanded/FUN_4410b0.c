/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x4410b0; label: FUN_004410b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004410b0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_007f8cc4,param_2);
  if (((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) ||
     ((*(uint *)(iVar2 + 0xa0) & 0x100) == 0)) {
    iVar2 = 0;
  }
  return iVar2;
}

