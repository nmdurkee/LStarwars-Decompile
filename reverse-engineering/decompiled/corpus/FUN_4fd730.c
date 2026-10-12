/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fd730; label: FUN_004fd730
 */

void FUN_004fd730(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_004fd5d0(param_1,*param_2,*param_3 - *param_2);
  *param_2 = *param_2 + iVar1;
  return;
}

