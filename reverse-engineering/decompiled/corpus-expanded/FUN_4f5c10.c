/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5c10; label: FUN_004f5c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f5c10(char *param_1)

{
  int iVar1;
  va_list _ArgList;
  
  iVar1 = FUN_006e81d7();
  FID_conflict__fputc(10,(FILE *)(iVar1 + 0x40));
  _ArgList = &stack0x00000008;
  iVar1 = FUN_006e81d7();
  FID_conflict__vfprintf((FILE *)(iVar1 + 0x40),param_1,_ArgList);
  iVar1 = FUN_006e81d7();
  FID_conflict__fputc(10,(FILE *)(iVar1 + 0x40));
  FUN_004ef790();
  return;
}

