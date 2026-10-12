/* Ghidra analysis pseudocode, not original source.
 * ev_bdb17253d8eceafb8feb22cd0a23bb82c1f6b43d5fe47ab3712e26b834ea25e8
 * Entry: 0x4f5c10; label: FUN_004f5c10
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

