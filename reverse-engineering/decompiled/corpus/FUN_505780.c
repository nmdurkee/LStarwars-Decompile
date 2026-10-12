/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x505780; label: FUN_00505780
 */

void FUN_00505780(undefined4 param_1)

{
  int iVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xc) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(unaff_ESI + 4) + *(int *)(unaff_ESI + 0xc);
  }
  *(int *)(unaff_ESI + 0xc) = iVar1;
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    FUN_00500b00(param_1);
  }
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    FUN_00500c80();
  }
  if (*(int *)(unaff_ESI + 0x14) != 0) {
    FUN_00501ea0();
  }
  if (*(int *)(unaff_ESI + 0x18) != 0) {
    FUN_005028e0();
  }
  if (*(int *)(unaff_ESI + 0x24) != 0) {
    FUN_00503630(*(undefined4 *)(unaff_ESI + 4));
  }
  if (*(int *)(unaff_ESI + 0x20) != 0) {
    *(int *)(unaff_ESI + 0x20) = *(int *)(unaff_ESI + 4) + *(int *)(unaff_ESI + 0x20);
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  return;
}

