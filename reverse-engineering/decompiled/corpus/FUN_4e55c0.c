/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e55c0; label: FUN_004e55c0
 */

void FUN_004e55c0(void)

{
  int iVar1;
  float local_c [3];
  
  iVar1 = FUN_0054fa60();
  local_c[0] = (float)iVar1 * 1.5259022e-05 * 4.0 + 32.5;
  local_c[1] = -5.5;
  iVar1 = FUN_0054fa60();
  local_c[2] = (float)iVar1 * 1.5259022e-05 * 4.0 + 12.5;
  FUN_00547d70("Dianoga_Groan",local_c);
  return;
}

