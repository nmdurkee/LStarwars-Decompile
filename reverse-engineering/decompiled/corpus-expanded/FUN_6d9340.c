/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9340; label: FUN_006d9340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d9340(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_02975144;
  if (*(char *)(DAT_02975144 + 0x4e10) == '\0') {
    *(undefined1 *)(DAT_02975144 + 0x4e10) = 1;
    uVar2 = FUN_006d5990();
    *(undefined4 *)(iVar1 + 0x68b0) = uVar2;
  }
  return;
}

